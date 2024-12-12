#!/bin/sh
echo -n "Do you want to continue?"
read yesno
case $yesno in
y | Y | Yes | yes )
	echo "We will continue"
	;;
n | N | no | No | NO )
	echo "Game over"
	;;
* )
	echo "Incorrect input"
	exit 1
	;;
esac

