#!/bin/bash

TMP_FILE=$TMP_DIR/processes.$$.tmp

ps axwwo user,pid,start,time,args | 
grep -v "^root" | 
grep -v ssh | 
grep -v ssh-agent | 
grep -v "^rpc" | 
grep -v "^nagios" | 
grep -v "^smmsp" | 
grep -v "^nscd" | 
grep -v "^nx" | 
grep -v "bash$" | 
grep -v nxagent | 
grep -v nxnode | 
grep -v xterm |
grep -v "gnome-terminal$" |
grep -v bonobo-activation-server |
grep -v /apps/homefs1/gveda/.nx/ |
grep -v gnome-pty-helper |
grep -v /usr/libexec/gconfd-2 |
grep -v mysqld |
grep -v eclipse | 
grep -v Bootstrap |
grep -v top |
grep -v "^ntp" | awk '$3 !~ ":" {print $0;}' > $TMP_FILE

NUM=`wc -l $TMP_FILE | cut -d' ' -f1`
if [ $NUM -gt 1 ]; then
    cat $TMP_FILE
fi

rm -f $TMP_FILE

exit 0
