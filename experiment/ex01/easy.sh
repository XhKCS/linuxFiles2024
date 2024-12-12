#!/bin/sh
easy(){
	typeset a
	a=$(($1+$2))
	b=$(($1+$2))
	echo "easy a is $a"
	echo "easy b is $b"
}

a=1
b=2
easy $a $b
echo "global a is $a"
echo "global b is $b"

