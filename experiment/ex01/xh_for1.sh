#!/bin/sh
for i in 1 3 4 7 9
  do echo $i
done

for i in `ls *.sh`
  do mv $i xh_$i
done

