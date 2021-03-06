/*
Task table schema:
P.id A.T B.T C.T T.A.T W.T
*/
#include<stdio.h>
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
}
int main(){
    int task[5][6];
    for (int i=0;i<5;i++){
        printf("Enter the arrival time and burst time for process P%d :", i+1);
        task[i][0]=i+1;
        scanf("%d %d", &task[i][1], &task[i][2]);
    }
    printf("I.D.     A.T.    B.T.");
    for (int i=0;i<5;i++){
        printf("\n %d\t %d\t %d\n", task[i][0],task[i][1],task[i][2]);
    }
    //bubble short
   for (int i = 0; i < 5-1; i++){       
       // Last i elements are already in place    
       for (int j = 0; j < 5-i-1; j++){
           if (task[j][1] > task[j+1][1]){ 
              swap(&task[j][1], &task[j+1][1]);
              swap(&task[j][0], &task[j+1][0]);
              swap(&task[j][2], &task[j+1][2]);
           }
       } 
   }
//calculating CT,TAT & WT
   int ct=task[0][1];
   for (int i=0;i<5;i++){
        //finding C.T
       ct=ct+task[i][2];
       task[i][3]=ct;
       //finding T.A.T
       task[i][4]=task[i][3]-task[i][1];
       //finding W.T
       task[i][5]=task[i][4]-task[i][2];

   }
   //final output
   printf("I.D.     A.T.    B.T.    C.T.    T.A.T.  W.T.");
    for (int i=0;i<5;i++){
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\n", task[i][0],task[i][1],task[i][2],task[i][3],task[i][4],task[i][5]);
    }
    //finding total W.T and T.A.T
    float totaltat=0;
    float totalwt=0;
    for(int i=0;i<5;i++){
        totaltat+=task[i][4];
        totalwt+=task[i][5];
    }
    printf("\n Average Turnaround time is : %f", totaltat/5);
    printf("\n Average waiting time is : %f\n", totalwt/5);
    return 0;
}
 
