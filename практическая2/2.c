#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int counter = 0;

void* add_one(void* unused){
    for(int i = 1; i <= 1000000; i++){
        counter++;   
    }
    return NULL;
}
int main() {
    pthread_t threadA, threadB;
    pthread_create(&threadA, NULL, add_one, NULL);
    pthread_create(&threadB, NULL, add_one, NULL);
    
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    
    printf("%d", counter);
    return 0;
}