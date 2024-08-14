if [ $# -ne 1 ]; then 
echo "het argument" 
exit 1
fi 

if [ -e /home/ghassen/projetLinux/Code/C/$1 ]; then 
echo "mawjoud"
if [ $1==*.* ]; then 
echo "fichier" 
else 
echo "dossier" 
fi 
fi 
