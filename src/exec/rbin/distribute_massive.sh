#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

PREV_DAY=`$BIN_DIR/exchange_date_add $PRIMARY_EXCHANGE $DATE -1`
INSTANCES=""

source $ROOT_DIR/bin/exec_common_include.sh
for SERVER in $SERVER_LIST ; do
  SERVER_NUM=`expr match $SERVER '[^1-9]*\([1-9]*\)'`
  if [ -z $SERVER_NUM ]; then
    echo "ERROR: Could not parse server number in $SERVER"
    exit 1
  fi
  INSTANCES="$INSTANCES $RUN_DIR/exec/universe.sub$SERVER_NUM"
done

SECURITY_FILE_SUFFIX="securityMaster.equity.us.csv"
SECURITY_FILE=$TMP_DIR/$DATE.$SECURITY_FILE_SUFFIX
wget -nv -O $SECURITY_FILE.tmp http://infradb1.jc:8080/data_config/US/$DATE.$SECURITY_FILE_SUFFIX 2>&1
awk -F, '{print $2}' $SECURITY_FILE.tmp > $SECURITY_FILE
sed -i 's/\//./g' $SECURITY_FILE

MASSIVE_GROUPS=$TMP_DIR/stocks.groups.tmp
rsync -L ase@exectrade1.jc:/apps/hyp2/live-opteron_rhel4/conf/Loggers/stocks.groups $MASSIVE_GROUPS

mkdir -p $RUN_DIR/exec
$BIN_DIR/distribute_massive.py -g $MASSIVE_GROUPS -d $PREV_DAY -t $RUN_DIR/tickers.txt -s $TMP_DIR/$DATE.$SECURITY_FILE_SUFFIX -m 2.0 $INSTANCES
RES=$?
rm -f $SECURITY_FILE $SECURITY_FILE.tmp $MASSIVE_GROUPS

if [ $RES != 0 ]; then
    echo "ERROR: problem running distribute_massive.py"
    exit 1
fi
exit 0
