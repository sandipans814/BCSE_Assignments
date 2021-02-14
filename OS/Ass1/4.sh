#!/bin/bash

# Author : Sandipan Saha
# Script follows here:


word1="printf"
word2="scanf"
word3="int"

declare -a files
for (( i=0; i<6; i+=1))
    do
        read -p "Enter file name: " filename
        if test -e $filename 
        then
            files[$i]=$filename
        else
            echo "File doesnot exist"
            i=-1
        fi
done 
echo "   FINAL RESULT"
echo -e "\t\tprintf\tscanf\tint"
echo "===================================="
for (( i=0; i<6; i+=1))
    do
    count1=0
    count2=0
    count3=0

    filename=${files[$i]}
    count1=$( grep -o -w "$word1" "$filename" | wc -l )
    count2=$( grep -o -w "$word2" "$filename" | wc -l )
    count3=$( grep -o -w "$word3" "$filename" | wc -l )

    echo -e "$filename\t$count1$count2$count3"
done