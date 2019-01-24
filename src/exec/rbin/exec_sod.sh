#!/bin/bash
if [ "$ROOT_DIR" = "" ]; then
    exit "Must set ROOT_DIR!"
else
    . $ROOT_DIR/src/bin/include.sh
fi

mkdir -p $RUN_DIR/exec
$BIN_DIR/generate_universe_and_exchanges.sh
$BIN_DIR/distribute_massive.sh
$BIN_DIR/gen_volume_distr.sh
$BIN_DIR/generate_etfbeta.py
$BIN_DIR/generate_klist.py
$BIN_DIR/copy_gtparams.sh
