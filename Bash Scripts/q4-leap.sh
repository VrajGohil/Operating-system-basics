year=$1
if [ $((year % 4)) == 0 ] || [ $((year % 400)) == 0 ] && [ $((year % 100)) == 0 ]
    then
    echo "Year is leap"
    else
    echo "Year is not leap"
fi