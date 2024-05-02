//code for scan
#include<stdio.h>
int min(int arr[],int n){
    int minimum=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<minimum){
            minimum=arr[i];
        }
    }
    return minimum;
}
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
    int minimum=min(queue,nq);
    int res=((n-1)-current)+((n-1)-minimum);
    printf("Total overhead movement is :%d",res);
}

    
