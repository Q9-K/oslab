#!/bin/bash
a=1
name1="file"
name2="newfile"
while [ $a -le 100 ]
do
	if [ $a -gt 70 ]	   #if loop variable is greater than 70
	then
		rm -rf  "$name1$a"
	elif [ $a -gt 40 ]         # else if loop variable is great than 40
	then
		mv "$name1$a" "$name2$a" 
	fi
	((a++))       #don't forget change the loop variable
done
