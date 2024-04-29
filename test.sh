if [ $# -ne 2 ] ; then 
exit 1
fi 

somme=$(($1 + $2)) 
echo $somme
