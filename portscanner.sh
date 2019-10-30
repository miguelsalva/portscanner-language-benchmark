#!/bin/bash
host=$1     
for port in {0..65535};do
2>/dev/null echo > /dev/tcp/$host/$port
if [ $? == 0 ]
 then
 {
 echo " $port is open"
 }
fi
done
