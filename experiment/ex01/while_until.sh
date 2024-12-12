#!/bin/sh
i=0
while [ $i -lt 5 ]
do
  echo $i
  i=$((i+1))
done

i=1
until [ $i -gt 5 ]
do
  echo $i
  i=$((i+1))
done

