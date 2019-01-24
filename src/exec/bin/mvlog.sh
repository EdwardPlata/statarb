#!/bin/bash
if [ "x$1" = "x" ] || [ ! -d "$1" ] ; then
  echo "Usage: $0 /path/to/log/dir"
  exit 2
else
  TARGETNAME="$1.`date +%Y%m%d`"
  SUFFIX=""
  if [ -d $TARGETNAME ] ; then
    SUFFIX="1"
    while [ -d "$TARGETNAME.$SUFFIX" ] ; do
      SUFFIX=$(($SUFFIX+1))
    done
    TARGETNAME="$TARGETNAME.$SUFFIX"
  fi
  mv "$1" "$TARGETNAME"
fi
