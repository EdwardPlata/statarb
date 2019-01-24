#!/bin/sh

if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

HOST=`basename \`hostname\` .tower-research.com`
INSTANCE=`expr match $HOST '[^1-9]*\([1-9]*\)'`
$EXEC_ROOT_DIR/bin/set-massive.sh $EXEC_ROOT_DIR/gt-params/universe.sub$INSTANCE
