#include <stdio.h>
int main(){
    int noOfProcess;
    int noOfResource;
    printf("Enter the number of processes :");
    scanf("%d",&noOfProcess);
    printf("\nEnter the number of resources :");
    scanf("%d",&noOfResource);
    int allocatedResource[noOfProcess][noOfResource];
    int requestedResource[noOfProcess][noOfResource];
    int availableResource[noOfResource];
    int totalResource[noOfResource];
    int processesCompleted = 0;
    int isProcessArrived[noOfResource];
    int isDeadlock = 0;
    //input for total resource    int totalRequestedResource;
    for(int i=0;i<noOfResource;i++){
        printf("\nEnter the total resource available for R[%d] :",i);
        scanf("%d",&totalResource[i]);
        availableResource[i]=totalResource[i];
    }
    //input for allocated Resources
    for(int i=0;i<noOfProcess;i++){
        isProcessArrived[i]=0;
        for(int j=0;j<noOfResource;j++){
            printf("\nEnter the value for P[%d] R[%d] allocated :",i,j);
            scanf("%d",&allocatedResource[i][j]);
            availableResource[j]=-allocatedResource[i][j];
        }
    }
    //input for requested Resources
    for(int i=0;i<noOfProcess;i++){
        for(int j=0;j<noOfResource;j++){
            printf("\nEnter the value for P[%d] R[%d] requested :",i,j);
            scanf("%d",&requestedResource[i][j]);
        }
    }
     //outputs
    for(int i=0;i<noOfProcess;i++){
        printf("\nP[%d] |",i);
        for(int j=0;j<noOfResource;j++){
            printf("\t%d |",allocatedResource[i][j]);
        }
        printf("\t||");
        for(int j=0;j<noOfResource;j++){
            printf("\t%d |",requestedResource[i][j]);
        }
    }
    printf("\nProcess sequence :");
    //brain
    while (processesCompleted < noOfProcess){
        for(int i=0;i<noOfProcess;i++){
            isDeadlock = 1;
            if(isProcessArrived[i] == 0){
                int lastResourceIndex;
                for(lastResourceIndex=0;lastResourceIndex<noOfResource;lastResourceIndex++){
                    if(requestedResource[i][lastResourceIndex]>availableResource[lastResourceIndex]){
                        break;
                    }
                }
                if(lastResourceIndex == noOfResource){
                    isProcessArrived[i] = 1;
                    for(int j = 0;j<noOfResource;j++){
                        requestedResource[i][j] = 0;
                        availableResource[j]+=allocatedResource[i][j];
                    }
                    printf("<-> %d ",i);
                    isDeadlock = 0;
                    processesCompleted++;
                    break;
                }
            }
        }
        if(isDeadlock == 1){
        printf("\n There is Deadloack");
        break;
        }
        else{
         printf("\n No Deadlock");
        }
    }
    return 0;
}