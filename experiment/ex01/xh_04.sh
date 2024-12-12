#!/bin/sh
echo "The color is ${COLOR:-green}"
echo $COLOR

COLOR='blue'
echo "The color is ${COLOR:-green}"

