#!/usr/bin/env bash

set -o pipefail

REQUIRED_GEN_PACK_LIB="0.12.0"
DEFAULT_ARGS=()

CURRENT_TAG="$(git describe --exact-match --tags HEAD 2>/dev/null || true)"
TAG_VERSION=""
TAG_DATE=""
if [[ "${CURRENT_TAG}" == v* ]]; then
  TAG_VERSION="${CURRENT_TAG#v}"
  TAG_DATE="$(git log -1 --date=format:%Y-%m-%d --format=%ad HEAD 2>/dev/null || date -u +%Y-%m-%d)"
fi

PACK_DIRS="
  .config
  interfaces
"

PACK_BASE_FILES="
  LICENSE.md
  CMakeLists.txt
  MyVendor.myswpart_part_drivers.pdsc
  myswpart.c
  myswpart.h
"

PACK_DELETE_FILES="
  .gitignore
  gen_pack.sh
"

function preprocess() {
  return 0
}

function postprocess() {
  if [[ -n "${TAG_VERSION}" ]]; then
    local build="$1"
    local pdsc
    pdsc="$(find "${build}" -maxdepth 1 -name '*.pdsc' -print -quit)"

    if [[ -z "${pdsc}" ]]; then
      echo "gen_pack.sh> Error: No PDSC file found in build folder '${build}'." >&2
      return 1
    fi

    python3 - "${pdsc}" "${TAG_VERSION}" "${TAG_DATE}" <<'PY'
import sys
import xml.etree.ElementTree as ET

pdsc_path, version, release_date = sys.argv[1:]
ns_stm32 = "https://developer.st.com/schemas/stm32cube/1.0.0"
ns_xsi = "http://www.w3.org/2001/XMLSchema-instance"

ET.register_namespace("stm32", ns_stm32)
ET.register_namespace("xsi", ns_xsi)

tree = ET.parse(pdsc_path)
root = tree.getroot()

compat_release = root.find(f"./environments/environment/{{{ns_stm32}}}pack/compatibility/release")
if compat_release is not None:
    compat_release.set("version", version)

for component in root.findall("./components/component"):
    component.set("Cversion", version)

releases = root.find("./releases")
if releases is None:
    releases = ET.SubElement(root, "releases")

release_entries = releases.findall("release")
if release_entries and release_entries[0].get("version") == version:
    release_entry = release_entries[0]
else:
    release_entry = ET.Element("release")
    releases.insert(0, release_entry)

release_entry.set("version", version)
release_entry.set("date", release_date)
release_entry.text = f"Release {version}."

if hasattr(ET, "indent"):
    ET.indent(tree, space="  ")

tree.write(pdsc_path, encoding="UTF-8", xml_declaration=True)
PY
  fi

  return 0
}

if [[ -f "${GEN_PACK_LIB_PATH}/gen-pack" ]]; then
  . "${GEN_PACK_LIB_PATH}/gen-pack"
else
  . <(curl -sL "https://raw.githubusercontent.com/Open-CMSIS-Pack/gen-pack/main/bootstrap")
fi

gen_pack "${DEFAULT_ARGS[@]}" "$@"

exit 0
