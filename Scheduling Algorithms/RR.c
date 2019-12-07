#include<stdio.h>
#include<stdlib.h>
#define N 50
int q[N];
int count=-1;

void insert(int q[],int *f,int *r,int val){
    if((*r)>=N-1)
        printf("queue is full");
    else
    {
        q[++(*r)]=val;
        if((*f)==-1)
           { *f=0;}
    }
}
void swap(int *a,int *b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int a[],int b[],int c[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				swap(&a[j],&a[j+1]);
				swap(&b[j],&b[j+1]);
                swap(&c[j],&c[j+1]);			
			}		
		}			
	}
}
int main(){
    int f,r;
    f=-1;r=-1;
	int n,Tq,time=0;
	printf("Enter number of processes :");
	scanf("%d",&n);	
	int table[n][6];
	int arrivalTime[n],burstTime[n];
    printf("Enter Time Quantum :");
    scanf("%d",&Tq);
	for(int i=0;i<n;i++){
		printf("Enter arrival time and burst time of process p%d :",i+1);
		scanf("%d %d",&table[i][1],&table[i][2]);
		table[i][0]=i+1;	
	}
	int a[n],p[n],b[n];
	for(int i=0;i<n;i++){
		a[i]=table[i][1];
		p[i]=table[i][0];
        b[i]=table[i][2];
	}
	sort(a,p,b,n);
	float tat=0,wt=0;
    time=a[0];
    int z,bt,index=0,pid,time1,y,x;

    for(int i=0;i<n;i++){
            if(a[i]<=time && b[i]!=0)
            {   
                insert(q,&f,&r,p[i]);

            }
            
        }

    while (1)
    {
        pid=q[f];
        for(int i=0;i<n;i++){
            if(pid==p[i]){
                if(b[i]>Tq){
                    b[i]-=Tq;
                    bt=b[i];
                    time+=Tq;
                }
                else
                {
                    time+=b[i];
                    b[i]=0;
                    bt=b[i];
                    for(int j=0;j<n;j++){
			            if(pid==table[j][0]){
				            //calculating complition time
				            table[j][3]=time;		
			            }		
		            }
                }
                
            }
        }
        
        for(int i=0;i<n;i++){
            if(a[i]<=time && b[i]!=0)
            {  y=0;
                for(int j=f;j<=r;j++){
                    if(p[i]==q[j])
                    {y=1;}          
                }
                if(y==0)
                    {insert(q,&f,&r,p[i]);}
            }
        }
        if(bt!=0)
            {insert(q,&f,&r,q[f]);}
        f++;
        z=0;
        for(int i=0;i<n;i++){
            if(b[i]!=0)
                z=1;
        }
        if(z==0)
            break;
            
    }
    for(int j=0;j<n;j++){
				//calculating turn around time
				table[j][4]=table[j][3]-table[j][1];
				tat+=table[j][4];
				//calculating waiting time
				table[j][5]=table[j][4]-table[j][2];
				wt+=table[j][5];				
		}
   
	//calculating average tat and wt
	tat=tat/n;
	wt=wt/n;
	printf(" P_ID\tA.T\tB.T\tC.T\tT.A.T\tW.T\n");
	for(int i=0;i<n;i++){		
		printf(" %d\t%d\t%d\t%d\t%d\t%d\n",table[i][0],table[i][1],table[i][2],table[i][3],table[i][4],table[i][5]);	
	}
    for(int i=0;i<=r;i++){
        printf(" %d |",q[i]);
    }
	printf("\nAvarage TAT is : %f\n",tat);
	printf("Avarage Waiting Time is : %f\n",wt);
}
