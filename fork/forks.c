#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int globe = 10; 
int main(){
    int pid = fork(); 
    if (pid>0){ // parent section
        globe ++; 
        printf("parent with globe %d\n", globe); 
        printf("PID parent : %d\n", (int)getpid());//getpid returns its pid in the system 
    }
    else { // child section 
        globe --; 
        printf("child with globe %d\n", globe); 
        printf("PID child : %d\n", (int)getpid()); 

    }
}