read user 
w=`whoami`
if [ $user == $w ]
    then
    echo "User is logged in"
    else
    echo "User not logged in"
fi