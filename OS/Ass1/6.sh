#!/bin/bash

# Author : Sandipan Saha
# Script follows here:

# Take file name as input
read -p "Enter file name: " filename
# If file does not exist return error message
test -e $filename || echo "File does not exist"

# If file exists ask for the word to be searched
read -p "Enter word to search for: " word

# Check if word exists in file
count=$( grep -io -w "$word" "$filename" | wc -l )

count2=$( grep -io  "$word" "$filename" | wc -l )

val=`expr $count2 - $count`
if [ $val -ge 0 ]
then
    echo " Partial matching of $word found $val time(s) in $filename. Leaving them unaltered."
fi
if [ $count -gt 0 ]
then
    # If found display
    echo "Exact match of $word (ignoring case) found $count time(s) in $filename"

    # Ask for the second word
    read -p "Enter word to replace with: " word2

    # sed -i 's/\<''"$word1"'\>/'"$word2"'/g' $filename
    gsed -i 's/\b'"$word"'\b/'"$word2"'/gI' $filename
    echo "Replacement done"
else
    # If not found
    echo "$word not found in $filename"
fi