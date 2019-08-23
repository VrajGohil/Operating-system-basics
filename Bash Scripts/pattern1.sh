echo "Enter a number"
read a
for((i=1 ; i <= $a ; i++))
do
	for((j=1 ; j <= $i ; j++))
	do
		echo -n "*"
	done
	echo 
done
