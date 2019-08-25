echo "Enter a number"
read n
p=0
for ((i=2;i<n;i++))
	do
	v=$((n % i))
	if [ $v -eq 0 ]
	then
		p=0
	else
		p=1
	fi
done
if [ $p -eq 1 ]
then
		echo "Number is not prime"
	else
		echo "Number is Prime"
	fi
