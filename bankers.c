#include<stdio.h>

void main(){
    int np,nr;
    printf("Enter the number of processes: ");
    scanf("%d",&np);
    printf("Enter the number of resources: ");
    scanf("%d",&nr);
    int allocated[np][nr];
    int max[np][nr];
    int available[nr];
    printf("Enter Allocated matrix: ");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&allocated[i][j]);
        }
    }
    printf("Enter Max matrix: ");
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("Enter the available instances of resources: ");
    for(int j=0;j<nr;j++){
        scanf("%d",&available[j]); 
    }
    
    // Calculate need matrix
    int need[np][nr];
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            need[i][j]=max[i][j]-allocated[i][j];
        }
    }
    
    // Safety algorithm
    int finish[np];
    int work[nr];
    for(int i=0;i<nr;i++){
        work[i]=available[i];
    }
    for(int i=0;i<np;i++){
        finish[i]=0;
    }
    
    int safeSequence[np];
    int count=0;
    while(count<np){
        int found=0;
        for(int i=0;i<np;i++){
            if(finish[i]==0){
                int j;
                for(j=0;j<nr;j++){
                    if(need[i][j]>work[j]){
                        break;
                    }
                }
                if(j==nr){
                    for(int k=0;k<nr;k++){
                        work[k]+=allocated[i][k];
                    }
                    safeSequence[count++]=i;
                    finish[i]=1;
                    found=1;
                }
            }
        }
        if(found==0){
            printf("System is not in safe state\n");
            return;
        }
    }
    
    printf("System is in safe state.\nSafe sequence is: ");
    for(int i=0;i<np;i++){
        printf("%d ", safeSequence[i]);
    }
}
