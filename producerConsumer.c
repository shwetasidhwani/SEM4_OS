#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

HANDLE mutex, empty,full;
int in , out = 0;
int buffer[10];

//function prototypes
void producer();
void consumer();

void producer(){
    //initialize using WAit
    WaitForSingleObject(empty, INFINITE);
    WaitForSingleObject(mutex, INFINITE);

    //logic 
    buffer[in] = 1;
    printf("Producer produces item\n");

    in = (in+1) % 10;

    ReleaseMutex(mutex);
    ReleaseSemaphore(full, 1, NULL);

}

void consumer(){
    //init
    WaitForSingleObject(full, INFINITE);
    WaitForSingleObject(mutex, INFINITE);

    int item = buffer[out];
    printf("Consumer consumes item\n");

    ReleaseMutex(mutex);
    ReleaseSemaphore(empty,1,NULL);
}

int main(){
    HANDLE producer_thread, consumer_thread;
    int choice;

    mutex = CreateMutex(NULL, FALSE, NULL);
    empty = CreateSemaphore(NULL, 10 , 10 , NULL);
    full = CreateSemaphore(NULL, 0 , 10 , NULL);

    while(1){
        printf("1.Producer\n");
        printf("2.Consumer\n");
        printf("3.Exit\n");

        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
            producer_thread = CreateThread(NULL, 0 , (LPTHREAD_START_ROUTINE)producer, NULL, 0, NULL);
            break;

            case 2:
            consumer_thread = CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)consumer, NULL, 0 , NULL);
            break;

            case 3:
            CloseHandle(mutex);
            CloseHandle(empty);
            CloseHandle(full);
            break;
            ExitProcess(0);

        }
    }

}