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
    int bt[5];
    for (int i=0;i<5;i++){
        printf("Enter the arrival time and burst time for process P%d :", i+1);
        task[i][0]=i+1;
        scanf("%d %d", &task[i][1], &task[i][2]);
        bt[i]=task[i][2];
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
              swap(&bt[j],&bt[j+1]);
           }
       } 
   }
   int min;
   int total_bt = 1000;
   int ct=task[0][1];
   int index;
   int time=ct;
   while (total_bt!=0){
       total_bt = 0;
       min = 1000;
       for(int i=0;i<5;i++){
           if(task[i][2]<min && bt[i]!=0 && ct>=task[i][1] && min!=bt[i]){
               min = task[i][2];
               index=i;
           }
           total_bt+=bt[i];
       }
        bt[index]-= 1;
        time++;
        task[index][3]=time;
        
        //finding C.T
        ct++;
        
   }
   task[index][3]--;
   for(int i=0;i<5;i++){
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
 
