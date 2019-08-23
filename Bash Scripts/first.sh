echo "Enter a number"
read a
x=`expr $a % 2`
if [ $x -eq 0 ]
then 
	echo "number is even"
else
	echo "number is odd"
fi
