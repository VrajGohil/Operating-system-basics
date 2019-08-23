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
		echo -n "*"
		echo -n " "
	done
 
	echo 
done

for((z=a-1;z>0;z--))
do
	for((j=a;j>z;j--))
	do
		echo -n " "
	done
	
	for((k=z;k>=1;k--))
	do
		echo -n "*"
		echo -n " "
	done
 
	echo 
done
