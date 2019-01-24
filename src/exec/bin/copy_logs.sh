#!/bin/sh

BIG_FILES="std.log trader.log"
SECRET_FILES="std.log trader.log"

CURDIR=/spare/local/guillotine/log
STOREDIR=/apps/exec/log

cd $STOREDIR

if [ x$TODAY = x ] ; then
    TODAY=`date +%Y%m%d`
fi

if [ x"$*" = x ] ; then 
    echo "usage: $0 acct1 [acct2 acct3 ...]" 
    exit 2
fi

for acc in "$@" ; do
    if [ ! -d $STOREDIR/$acc ] ; then
        echo "$STOREDIR/$acc does not exist -- skipping $acc"
    else
        for dir in $CURDIR/${acc}_?.$TODAY* ; do
            cd $dir
            chmod go-rwx $SECRET_FILES
            gzip $BIG_FILES
            cd $STOREDIR
            cp -R $dir $STOREDIR/$acc/
        done
    fi
done

