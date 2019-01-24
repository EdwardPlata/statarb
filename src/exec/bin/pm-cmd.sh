#!/bin/sh

if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

HOST=`basename \`hostname\` .tower-research.com`
INSTANCE=`expr match $HOST '[^1-9]*\([1-9]*\)'`
$EXEC_ROOT_DIR/bin/gt-server.rts1 -C $EXEC_ROOT_DIR/gt-server-conf/exectrade$INSTANCE.jc/guillotine.conf -C $EXEC_ROOT_DIR/gt-server-conf/rts1.conf
