#!/bin/sh

# Author : Sandipan Saha
# Script follows here:

for d in $(find ~/Assignments/OS -maxdepth 1  -type d)
do
  #Do something, the directory is accessible with $d:
    echo "Total number of files in $d directory"
    find $d -type f | wc -l
done 

find ~/Assignments/OS -type f -newermt '12/31/2017 23:59:59' ! -newermt '1/1/2020 0:00:00'