echo "Enter a string"
read str
p=0
len=${#str}
for ((i=0;i<len;i++))
	do
	pre=${str:len-i-1:1}
    pos=${str:i:1}
    echo $pos $pre
    if [ $pos != $pre ]
	then
		p=1
	fi
done
if [ $p -eq 1 ]
then
		echo "Number is not palindrom"
	else
		echo "Number is  palindrom"
	fi
