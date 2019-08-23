echo "Enter a number"
read a
for((i=0;i<a;i++))
do
	for((j=a-1;j>i;j--))
	do
		echo -n " "
	done
	
	for((k=0;k<i+1;k++))
	do
		echo -n $((i+1))
		echo -n " "
	done
 
	echo 
done
