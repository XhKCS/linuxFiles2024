#!/bin/sh
message(){
	echo "message"
}
sum(){
	x=$1
	y=$2
	result=$((x+y))
	return $result
}

for ((i=0;i<3;i++))
do 
	message
done
echo "Enter two numbers"
read num1 num2
sum $num1 $num2
echo "The sum is $?"

