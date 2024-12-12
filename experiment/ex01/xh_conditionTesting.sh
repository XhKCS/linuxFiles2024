#!/bin/sh
# 测试文件状态
echo "--- testing file ---"
[ -w test.c ]
echo $?

# 测试字符串
echo "--- testing string ---"
[ "Hello"="Hi" ]
echo $?
[ "Hello"!="Hi" ]
echo $?
[ -z "Hello" ] #是否是空串
echo $?
[ -n "Hello" ] #是否是非空串
echo $?
[ "Hello" ]
echo $?

# 测试数值比较
echo "--- testing number value ---"
NUM=100
[ $NUM -eq 100 ]
echo $?
[ $NUM -gt 90 ]
echo $?
[ $NUM -le 101 ]
echo $?

