#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

$BIN_DIR/vol_hist.py --date $DATE --hist 20
#cat $RUN_DIR/exec/volume_distr
