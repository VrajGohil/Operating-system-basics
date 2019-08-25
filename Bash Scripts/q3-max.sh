max=0
total=0
count=0
for i in $*
    do
    echo $i
    if [ $max -lt $i ]
        then
        max=$i
        total=$((total+$i))
        count=$((count+1))
    fi
done
echo "Max is" $max
echo "Total is" $total
echo "Avg is" $((total/$count))