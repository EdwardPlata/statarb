#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

if [ $# -lt 1 ]; then
    echo "Usage $0 Release"
    exit
fi

RELEASE=$1

source $ROOT_DIR/bin/exec_common_include.sh
echo Reverting to $RELEASE

for x in $ALL_SERVER_LIST; do 
	ssh $x rm $EXEC_ROOT_DIR/bin/gt-server.$ACCOUNT
	ssh $x ln -s $EXEC_ROOT_DIR/bin/gt-server.$RELEASE $EXEC_ROOT_DIR/bin/gt-server.$ACCOUNT
done

for x in $ALL_SERVER_LIST; do 
	echo ====$x====
	ssh $x ls -l $EXEC_ROOT_DIR/bin/gt-server.$RELEASE  $EXEC_ROOT_DIR/bin/gt-server.$ACCOUNT
done  
