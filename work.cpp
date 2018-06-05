#include <iostream>  
#include <pthread.h>
#include <unistd.h>  
using namespace std;  
  
void* thread1(void*);  
void* thread2(void*);  
  
int main(int argc, char* argv[]) {  
    pthread_t t[2];  
    int iret1, iret2;  
  
    iret1 = pthread_create(&t[0], NULL, thread1, NULL);  
  
    if (iret1) {  
        fprintf(stderr, "Error - pthread_create() return code: %d\n", iret1);  
        exit(EXIT_FAILURE);  
    }  
  
    iret2 = pthread_create(&t[1], NULL, thread2, NULL);  
  
    if(iret2) {  
        fprintf(stderr, "Error - pthread_create() return code: %d\n", iret2);  
        exit(EXIT_FAILURE);  
    }  
  
    printf("pthread_create() for thread 1 returns: %d\n", iret1);  
    printf("pthread_create() for thread 2 returns: %d\n", iret2);  
  
    return 0;  
}  
  
void* thread1(void*) {  
    for (int i=0; i<5; i++) {  
        cout <<"Hello World" <<endl;  
  
        sleep(1);  
    }  
}  
  
void* thread2(void*) {  
    for (int i=0; i<5; i++) {  
        cout <<"Hi zj" <<endl;  
  
        sleep(1);  
    }  
}  
