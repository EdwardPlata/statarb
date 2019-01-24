#!/bin/bash
OFF=$1

if [ "x$1" = "x" ] ; then
  echo "Usage: $0 <strategy-offset-number>"
else
    /apps/hyp2/live-opteron_rhel4/bin/umsg -h 239.255.3.128 -p 3130 -s $((2000300 + $1)) -c 100
fi
