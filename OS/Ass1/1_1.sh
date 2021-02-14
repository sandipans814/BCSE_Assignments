while [ 1 == 1 ]   
do
    echo "=========================================="
    echo "Enter 1: To add"
    echo "Enter 2: To multiply"
    echo "Enter 3: To divide"
    echo "Enter 4: To concatenate"
    echo "Enter 5: To extract common substring"
    echo "================= Input =================="


    read -p "Enter value 1: " userv1
    read -p "Enter value 2: " userv2
    read -p "Enter choice : " choice

    echo "================ Output =================="

    if [ $choice == '1' ]
    then
        sum=$((userv1 + userv2))
        echo "Sum: $sum"
    elif [ $choice == '2' ]
    then
        product=$((userv1 * userv2))
        echo "Product: $product"
    elif [ $choice == '3' ]
    then
        quotient=$((userv1 / userv2))
        remainder=$((userv1 % userv2))
        echo "Quotient: $quotient, Remainder: $remainder"
    elif [ $choice == '4' ]
    then
        concatenate="$userv1 $userv2"
        echo "Concatenated result: $concatenate"
    elif [ $choice == '5' ]
    then
        common_prefix() {
        local n=0
        while [[ "${1:n:1}" == "${2:n:1}" ]]; do
            ((n++))
        done
        echo "Common substring: ${1:0:n}"
        }
        common_prefix $userv1 $userv2
    fi

    echo "=========================================="
    echo "================= Input =================="
    read -p "Enter X to exit: " choice
    if [ $choice == 'X' ]
    then
        echo "============== Terminated ================"
        echo "=========================================="
        break
    fi
done