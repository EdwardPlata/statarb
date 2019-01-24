#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

source $ROOT_DIR/bin/exec_common_include.sh

for x in $SERVER_LIST; do 
	echo ====$x====
	ssh $x "ps auxw | grep massive"
done


