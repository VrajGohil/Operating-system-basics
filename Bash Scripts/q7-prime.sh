echo "Enter a number"
read n
p=0
for ((i=2;i<n;i++))
	do
	v=$((n % i))
	if [ $v -eq 0 ]
	then
		p=$((p+1))
	fi
done
if [ $p -eq 0 ]
then
		echo "Number is prime"
	else
		echo "Number is not Prime"
	fi
