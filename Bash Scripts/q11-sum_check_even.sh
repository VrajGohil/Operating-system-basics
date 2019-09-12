total=0
for i in $*
    do
    total=$((total+$i))
done
echo $total
if [ $((total % 2)) -eq 0 ]
    then
    echo "Total is even"
    else
    echo "Total is odd"
fi