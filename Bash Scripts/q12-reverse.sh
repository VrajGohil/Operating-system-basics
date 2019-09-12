count=0
array=()
for i in $*
    do
    count=$((count+1))
    array+=($i)
done
echo ${array[@]}

if [ $count -gt 5 ]
    then
    echo "Invalid number of arguments"
    else
    for ((i=$count-1;i>=0;i--))
    do
        echo -n "${array[i]} "
    done
fi