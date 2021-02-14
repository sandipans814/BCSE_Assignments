#!/bin/sh

# Author : Sandipan Saha
# Script follows here:

function get_input()
{
    read -p "Enter the value of $1 variable : " v1
    return $v1 ;
}

while :
do
	clear
        # display menu
        echo "Server Name - $(hostname)"
	echo "-------------------------------"
	echo "     M A I N - M E N U"
	echo "-------------------------------"
	echo "1. Add"
	echo "2. Multiply"
	echo "3. Divide."
    echo "4. Concatenate"
    echo "5. Common Substring"
	echo "6. Exit"
        # get input from the user 
	read -p "Enter your choice [ 1 -6 ] " choice
        # make decision using case..in..esac 
	case $choice in
		1)
            read -p "Enter the value of first variable : " userv1
            read -p "Enter the value of second variable : " userv2
            val=`echo $userv1 + $userv2 | bc`
            echo "Sum of $userv1 and $userv2 : $val"
			read -p "Press [Enter] key to continue..." readEnterKey
			;;
		2) 
			read -p "Enter the value of first variable : " userv1
            read -p "Enter the value of second variable : " userv2
            val=`echo $userv1 \* $userv2 | bc`
            echo "Product of $userv1 , $userv2 : $val"	
			read -p "Press [Enter] key to continue..." readEnterKey
			;;
		3)
			read -p "Enter the value of first variable : " userv1
            read -p "Enter the value of second variable : " userv2
            if [ $userv1 -ge $userv2 ]
            then
            val=`echo $userv1 / $userv2 | bc`
            echo "Quotient of $userv1 / $userv2 : $val"
            else
            echo "1st variable is smaller in value, Division not possible."
            fi
			read -p "Press [Enter] key to continue..." readEnterKey
			;;
        4)
            read -p "Enter the value of first variable : " userv1
            read -p "Enter the value of second variable : " userv2
            expr $userv1 + 1 2> /dev/null
            if [ $? == 0 ]
            then
                expr $userv2 + 1 2> /dev/null
                if [ $? == 0 ]
                then
                    echo "Two numeric values cannot be concatenated"
                else
                    val=$userv1$userv2
                    echo "Concatenated String : $val"
                fi
            else
                val=$userv1$userv2
                echo "Concatenated String : $val"
            fi
            read -p "Press [Enter] key to continue..." readEnterKey
            ;;
        5)
            read -p "Enter the value of first variable : " userv1
            read -p "Enter the value of second variable : " userv2
            if [ ${#userv1} -lt ${#userv2} ]
            then
                    userv1=$userv2
                    userv2=$userv1
            fi
            for ((i=${#userv2}; i>0; i--)); do
                    for ((j=0; j<=${#userv2}-i; j++)); do
                            if [[ $userv1 =~ ${userv2:j:i} ]]
                            then
                                    echo "Longest Common Substring of $userv1 and $userv2 is "${userv2:j:i}
                                    read -p "Press [Enter] key to continue..." readEnterKey
                                    exit
                            fi
                    done
            done
            ;;
		6)
			echo "Bye!"
			exit 0
			;;
		*)
			echo "Error: Invalid option..."	
			read -p "Press [Enter] key to continue..." readEnterKey
			;;
	esac		
				
done