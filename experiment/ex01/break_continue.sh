#!/bin/sh
while :; do
  read string
  if [ $? != 0 ]; then
  	echo 'Thank you. Bye!'; break
  fi
  echo "your string is $string"
done

for ((i=5; i<16; i=$i+1))
do 
    echo $i
    if [ $i -lt 10 ] ; then continue
    fi
    echo "This is a two digital numeric"
done

