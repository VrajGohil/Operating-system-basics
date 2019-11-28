#include <stdio.h>

#define MAX 50
int queue_array[MAX];
int rear = - 1;
int front = - 1;
void insert(int add_item){
    if (rear == MAX - 1)
        printf("Queue is Full!!!! \n");
    else
    {
        if (front == - 1){
            front = 0;
        }
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
} 

int delete(){
    int value;
    if (front == - 1 || front > rear)
    {
        printf("Queue Empty!!! \n");
        return 0;
    }
    else
    {
        value = queue_array[front];
        front = front + 1;
    }
    return value;
} 

int main(){
    int sequenceLenght;
    int frameSize;
    int frame[frameSize];
    int pageFaults = 0;
    printf("Enter the sequence lenght :");
    scanf("%d",&sequenceLenght);
    printf("\nEnter the frame size : ");
    scanf("%d",&frameSize);
    int sequence[sequenceLenght];
    for(int i=0;i<sequenceLenght;i++){
        printf("\nEnter the value for element at positon %d : ",i+1);
        scanf("%d",&sequence[i]);
    }
    //fill frames initially till frame size
    for(int i=0;i<frameSize;i++){
        pageFaults++;
        frame[i]=sequence[i];
        insert(frame[i]);
    }
    //for rest of the sequence
    int notPresent = 0;
    int valueToChange;
    for(int currentPostion = frameSize;currentPostion < sequenceLenght;currentPostion++){
        insert(frame[currentPostion]);
        for(int i=0;i<frameSize;i++){
            if(frame[i]!=sequence[currentPostion]){
                notPresent = 1;
            }
            else{
                notPresent= 0;
            }
        }
        if(notPresent == 1){
            pageFaults++;
            valueToChange = delete();
            for(int i=0;i<frameSize;i++){
                if(valueToChange == frame[i]){
                    frame[i]=sequence[currentPostion];
                    break;
                }
            }
        }
    }
    printf("Total page faults = %d\n",pageFaults);
    return 0;
} 