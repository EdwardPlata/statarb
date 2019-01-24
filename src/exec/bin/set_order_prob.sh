#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

PROBABILITY=1.0

source $ROOT_DIR/bin/exec_common_include.sh
SERVER_NUMS=
for x in $ALL_SERVER_LIST; do 
  SERVER_NUMS="$SERVER_NUMS `expr match $SERVER '[^1-9]*\([1-9]*\)'`"
done

$EXEC_ROOT_DIR/bin/gt-server-umsg -c 1700 -m $PROBABILITY $SERVER_NUMS
