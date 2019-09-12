echo "Enter a number :"
read n
p=0
for ((i=1;i<=10;i++))
	do
	echo $n " X " $i " = " $((i*n))
done