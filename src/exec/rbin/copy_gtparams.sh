#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

source $ROOT_DIR/bin/exec_common_include.sh

for x in $ALL_SERVER_LIST; do 
	echo ====$x====
	ssh $x rm -f $EXEC_ROOT_DIR/gt-params/universe*
	ssh $x rm -f $EXEC_ROOT_DIR/gt-params/exchanges
	ssh $x rm -f $EXEC_ROOT_DIR/gt-params/volume_distr
	ssh $x rm -f $EXEC_ROOT_DIR/gt-params/etfbetafile
	scp $RUN_DIR/exec/* $x:$EXEC_ROOT_DIR/gt-params
	ssh $x "ls -ltr $EXEC_ROOT_DIR/gt-params"
done
