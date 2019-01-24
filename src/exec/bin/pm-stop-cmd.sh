#!/bin/sh

if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

HOST=`basename \`hostname\` .tower-research.com`
INSTANCE=`expr match $HOST '[^1-9]*\([1-9]*\)'`
$EXEC_ROOT_DIR/bin/gt-server-stop.sh $INSTANCE
PID=`ps ux | grep pm-cmd.sh | grep -v grep | awk '/pm-cmd/ {print $2}'`
kill -9 $PID
/bin/sleep 2
