#!/bin/sh
echo 'Hello World!'
# 注意sh中不能写多余的空格，包括赋值语句
# 变量的引用和打印
HELLO="Hello World!"

echo ${HELLO}
echo $HELLO
# 字符串截取 开始下标:截取长度
echo ${HELLO:0:5}
echo ${HELLO:2:5}
echo ${HELLO:2}

# set与unset
echo '使用set命令'
set HELLO
echo $1
echo '使用unset命令后'
unset HELLO
echo $1



