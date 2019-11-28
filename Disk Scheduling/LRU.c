#include <stdio.h>

#define MAX 50
int queue_array[MAX];
int rear = -1;
int front = -1;
void insert(int add_item)
{
    if (rear == MAX - 1)
        printf("Queue is Full!!!! \n");
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = rear + 1;
        queue_array[rear] = add_item;
    }
}

int delete ()
{
    int value;
    if (front == -1 || front > rear)
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

int main()
{
    int sequenceLenght;
    int frameSize;
    int pageFaults = 0;
    printf("Enter the sequence lenght :");
    scanf("%d", &sequenceLenght);
    printf("\nEnter the frame size : ");
    scanf("%d", &frameSize);
    int frame[frameSize];
    int sequence[sequenceLenght];
    for (int i = 0; i < sequenceLenght; i++)
    {
        printf("\nEnter the value for element at positon %d : ", i + 1);
        scanf("%d", &sequence[i]);
    }
    // fill frames initially with -1
    for (int i = 0; i < frameSize; i++)
    {
        frame[i] = -1;
    }
    //brain
    int notPresent = 1;
    int valueToChange;
    for (int currentPostion = 0; currentPostion < sequenceLenght; currentPostion++)
    {
        notPresent = 1;
        insert(sequence[currentPostion]);
        for (int i = 0; i < frameSize; i++)
        {
            if (frame[i] == sequence[currentPostion])
            {
                notPresent = 0;
            }
            //when frames are empty
            //-1 means position is empty
            else if(frame[i] == -1){
                pageFaults++;
                frame[i] = sequence[currentPostion];
                notPresent = 0;
                break;
            }
        }
        if (notPresent == 1)
        {
            valueToChange = delete ();
            for (int i = 0; i < frameSize; i++)
            {
                if (valueToChange == frame[i])
                {   
                    pageFaults++;
                    frame[i] = sequence[currentPostion];
                    break;
                }
            }
        }
        //print the working
        for(int i=0;i<frameSize;i++){
            printf("| %d |",frame[i]);
        }
        printf("\n");
    }
    printf("Total page faults = %d\n", pageFaults);
    return 0;
}