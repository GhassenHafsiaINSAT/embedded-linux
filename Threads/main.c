#include <stdio.h>
#include <pthread.h>

int sum = 0; 
pthread_mutex_t mutex; //initialement 1 

void* function0(){
    int i; 
    for(i=0;i<100000;i++){
        pthread_mutex_lock(&mutex); 
        sum+=1; 
        pthread_mutex_unlock(&mutex); 
    }
}

void* function1(){
    int i; 
    for(i=0;i<100000;i++){
        pthread_mutex_lock(&mutex); 
        sum+=1; 
        pthread_mutex_unlock(&mutex); 
    }
}
int main()
{
    //un tableau de 2 threads
    pthread_t threads[2]; 
    
    //creation des 2 threads
    pthread_create(&threads[0], NULL, &function0, NULL);
    pthread_create(&threads[1], NULL, &function1, NULL);

    //attendre les 2 threads de terminer 
    pthread_join(threads[0], NULL); 
    pthread_join(threads[1], NULL); 

    printf("sum=%d\n", sum); 
    return 0;
}