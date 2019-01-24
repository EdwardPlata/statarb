#!/bin/sh
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

HOST=`basename \`hostname\` .tower-research.com`
CONF=$EXEC_ROOT_DIR/gt-server-conf
PARAM=$EXEC_ROOT_DIR/gt-params
STARTTM=""
if [ "x$1" = "xnow" ] ; then
  STARTTM="-s `date -d '+1 minute' +%H%M`"
fi

ulimit -c 2097152

mkdir -p $EXEC_LOG_DIR/client
$EXEC_ROOT_DIR/bin/ProcessManager -c $CONF/processmanager.conf $STARTTM
