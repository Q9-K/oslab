#!/bin/bash
#First you can use grep (-n) to find the number of lines of string.
#Then you can use awk to separate the answer.
#grep -n $2 $1 > result_tmp
#awk -F : '{print $1}' result_tmp > $3
#rm result_tmp
grep -n $2 $1 | awk -F : '{print $1}' > $3
