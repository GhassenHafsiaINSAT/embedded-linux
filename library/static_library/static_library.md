# Static Library 

- Static library have extension .a in linux and .lib in windows.  
- Copying the code of library function into your object code with each compilation error.  

## How to create a static library 
- `gcc -c lib_add.c lib_sub.c fpic` : compile `lib_add.c` and `lib_sub.c` into position independant object files.  
- `ar rcs lib_calc.a lib_add.o lib_sub.o` : all the files .o will be added to `lib_calc.a`.  

 ## How to link our program to the static library
- `gcc -c main.c -o main.o`
- `gcc -o main main.o -L. calc.a`
