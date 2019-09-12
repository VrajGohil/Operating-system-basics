cal
date
date | awk '{print $2,$3,$4}' | tr " " /
date | awk '{print $5}'
read login_time | last "USER_NAME" | awk '{print $6}'
