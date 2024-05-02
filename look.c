//code for scan
#include<stdio.h>
void sort(int arr[],int n){
    int i,j, min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
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
    sort(queue,nq);
    int res=((queue[nq-1])-current)+(queue[nq-1]-queue[0]);
    printf("Total overhead movement is :%d",res);
}

    
