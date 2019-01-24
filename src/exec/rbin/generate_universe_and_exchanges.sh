#!/bin/sh
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

cd $RUN_DIR
sed 's/|.*//' tickers.txt > exec/universe
sed 's/|\([^|]*|\)\{6\}\([^|]*\)|.*/,\2/' tickers.txt | sed 's/NASD/ISLD/g'> exec/exchanges
