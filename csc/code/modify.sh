#!/bin/bash
sed s/$2/$3/g $1 > result_tmp
cat result_tmp > $1
rm result_tmp
