#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

source $ROOT_DIR/bin/exec_common_include.sh

for x in $ALL_SERVER_LIST; do 
	echo ====$x====
	ssh $x "grep RJC $EXEC_LOG_DIR/trader.log"
done


