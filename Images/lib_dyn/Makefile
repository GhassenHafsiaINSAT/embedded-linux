main : csf.o main.o 
	gcc main.o csf.o -o main 
main.o : main.c csf.h
	gcc -c main.c -o main.o 
csf.o : csf.c 
	gcc -c csf.c -o csf.o
	
clean :
	rm *.o

mrproper : clean
	rm main 
