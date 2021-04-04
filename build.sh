WD=$(realpath $(dirname "$0"))
BUILDER_NAME="tcrkbd-builder"

set -e

if [[ -n "$(docker ps -a -q -f name=$BUILDER_NAME)" ]]; then
  echo "Removing existing builder..."
  docker stop tcrkbd-builder >/dev/null
  docker rm tcrkbd-builder >/dev/null
fi

echo "Building firmware..."
docker run \
  --name $BUILDER_NAME \
  -v $WD/kb_firmware:/qmk_firmware/keyboards/crkbd/keymaps/tcrane \
  qmkfm/qmk_firmware \
  make crkbd:tcrane

echo "Copying build artefacts..."
if [[ ! -d $WD/build ]]; then
  mkdir $WD/build
fi
docker cp $BUILDER_NAME:/qmk_firmware/crkbd_rev1_legacy_tcrane.hex build/

echo "Removing container..."
docker rm $BUILDER_NAME >/dev/null
