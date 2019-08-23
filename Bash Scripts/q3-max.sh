max=0
for i in $*
    do
    echo $i
    if [ $max -lt $i ]
        then
        max=$i
    fi
done
echo "Max is" $max