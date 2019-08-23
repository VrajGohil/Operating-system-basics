num=$1
fac=1
for ((i=1;i<=num;i++))
    do
    fac=$((fac * i))
done
echo "factorial of " $num "is :" $fac 
