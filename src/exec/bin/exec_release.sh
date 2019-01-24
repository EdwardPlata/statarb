#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

if [ $# -lt 2 ]; then
    echo "Usage $0 Binary Release"
    exit
fi

BINARY=$1
RELEASE=$2

source $ROOT_DIR/bin/exec_common_include.sh
if [ -f $BINARY ]; then
    echo "Releasing:" $BINARY " as " $RELEASE 
    ls -l $BINARY
    
    for x in $SERVER_LIST; do 
        scp $BINARY $x:$EXEC_ROOT_DIR/bin/gt-server.$RELEASE
    done
    
    for x in $ALL_SERVER_LIST; do 
        echo ====$x====
        ssh $x ls -l $EXEC_ROOT_DIR/bin/gt-server.$RELEASE
    done
else
    echo $BINARY does not exist
fi
