touch constitute_file
tail -1 $1 >> constitute_file
tail -1 $2 >> constitute_file
tail -1 $3 >> constitute_file
cat constitute_file