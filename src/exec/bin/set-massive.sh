#!/bin/bash
RV=0
if [ "x$1" = "x" ] || [ ! -f $1 ] ; then
    echo "Usage: $0 <symbol-list>"
    exit 2
else
    cat "$@" | sort | uniq > /spare/local/conf/stocks.massive
    echo reload | nc -w 2 localhost 6001 | grep -q 'reload completed'
    exit $?
fi
