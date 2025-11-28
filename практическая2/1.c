#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* is_even(void* unused){
    int num = 16;
    int i = 1;
    if(num % 2 == 0){
        while(i <= 10){
            printf("%d is even\n", num);
            i++;
            usleep(1000);
        }
    }else{
        while(1){
            printf("%d is odd\n", num);
            usleep(1000);
        }
    }
    return NULL;
}

void* div(void* unused){
    double num1 = 16;
    double num2 = 3;
    int i = 1;
    if(num2 == 0){
        while(i <= 10){
            printf("Cannot be divided by 0");
            i++;
            usleep(1000);
        }
    }else{
        while(i <= 10){
            printf("%.0f / %.0f = %.2f\n", num1, num2, num1 / num2);
            i++;
            usleep(1000);
        }
    }
    return NULL;
}

void* sum(void* unused){
    int num1 = 2;
    int num2 = 3;
    int i = 1;
    while(i <= 10){
        printf("%d + %d = %d\n", num1, num2, num1 + num2);
        i++;
        usleep(1000);
    }
    return NULL;
}

int main() {
    pthread_t threadA, threadB, threadC;
    pthread_create(&threadA, NULL, is_even, NULL);
    pthread_create(&threadB, NULL, div, NULL);
    pthread_create(&threadC, NULL, sum, NULL);
    
    pthread_join(threadA, NULL);
    pthread_join(threadB, NULL);
    pthread_join(threadC, NULL);
    return 0;
}