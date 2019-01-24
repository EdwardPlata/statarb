#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

source $ROOT_DIR/bin/exec_common_include.sh
TIME_STAMP=`date +%Y%m%d.%H%M`

mkdir -p $RUN_DIR/exec/packetloss
for x in $SERVER_LIST; do 
	echo ====$x==== >> $RUN_DIR/exec/packetloss/stats.$TIME_STAMP
	ssh $x "netstat -su" >> $RUN_DIR/exec/packetloss/stats.$TIME_STAMP
	ssh $x "/sbin/ifconfig" >> $RUN_DIR/exec/packetloss/stats.$TIME_STAMP
done

