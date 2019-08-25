sum=0
n=$1
echo "You entered " $n
for((i=1 ; i<=$n ; i++))
do
    sum=$((sum+$i))
done
echo "Sum is" $sum
