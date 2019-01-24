#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

ACCOUNT=rts1
SERVER_STR=`cat $CONFIG_DIR/exec.conf | grep servers`
SERVER_LIST=`echo $SERVER_STR | sed 's/.*=[ \t,]*//' | sed 's/:[0-9]*//g'`
MOC_SERVER_STR=`cat $CONFIG_DIR/exec.moc.conf | grep servers`
MOC_SERVER_LIST=`echo $MOC_SERVER_STR | sed 's/.*=[ \t,]*//' | sed 's/:[0-9]*//g'`
ALL_SERVER_LIST="$SERVER_LIST $MOC_SERVER_LIST"

