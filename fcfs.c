//code for fcfs 
#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,nq,current;
    printf("Enter the number of cylinders: ");
    scanf("%d",&n);
    printf("How many elements are there in the queue? Enter:  ");
    scanf("%d",&nq);
    int queue[n];
    printf("Enter all elements in queue: ");
    for(int i=0;i<nq;i++){
        scanf("%d",&queue[i]);
    }
    printf("Enter current position of head: ");
    scanf("%d",&current);
    int res=abs(current-queue[0]);
    for(int i = 0; i < nq - 1; i++){
        res += abs(queue[i] - queue[i + 1]); 
    }
    printf("Total overhead movement is :%d",res);
}