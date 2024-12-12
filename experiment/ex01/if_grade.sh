#!/bin/sh
# Usage: ./if_grade.sh grade
# grade should be between 0 and 100, including 0 and 100
if [ $1 -lt 0 ] || [ $1 -gt 100 ] ; then
    echo "Error: invalid grade"
elif [ $1 -lt 60 ] ; then
    echo 'not pass'
elif [ $1 -lt 70 ] ; then
    echo 'pass'
elif [ $1 -lt 80 ] ; then
    echo 'good'
else
    echo 'excellent'
fi

