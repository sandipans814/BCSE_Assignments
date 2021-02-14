#!/bin/sh

# Author : Zara Ali
# Copyright (c) Tutorialspoint.com
# Script follows here:

# echo "What is your name?"
# read PERSON
# echo "Hello, $PERSON"

# for TOKEN in $@
# do
#    echo $TOKEN
# done

# NAME[0]="Zara"
# NAME[1]="Qadir"
# NAME[2]="Mahnaz"
# NAME[3]="Ayan"
# NAME[4]="Daisy"
# echo "First Index: ${NAME[*]}"
# echo "Second Index: ${NAME[1]}"

# val=`expr 2 + 2`
# echo "Total value : $val"

# echo "Enter val : \c"
# read num
# expr $num + 1 2> /dev/null
# if [ $? == 0 ]
# then
# echo "Val was numeric"
# else
# echo "Val was non-numeric"
# fi

# function func_return_value {
#       return 10
#  }

# function myfunc()
# {
#     local  myresult='some value'
#     echo "$myresult"
# }

# result=$(myfunc)   # or result=`myfunc`
# echo $result

# function myfunc()
# {
#     local  __resultvar=$1
#     local  myresult='some value'
#     if [[ "$__resultvar" ]]; then
#         eval $__resultvar="'$myresult'"
#     else
#         echo "$myresult"
#     fi
# }

# myfunc result
# echo $result
# result2=$(myfunc)
# echo $result2

# a=686
# b=228.35
# c=`echo $a + $b | bc`
# echo "$c"

# find ~/Assignments -maxdepth 1 -type d

STR='GNU/Linux is an operating system'
SUB='Linux'

count2=$( grep -io -w "$SUB" "$STR" | wc -l )
echo "$count2"