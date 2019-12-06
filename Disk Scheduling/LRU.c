#include <stdio.h>
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
    int counter[frameSize];
    int count = 0;
    for (int i = 0; i < sequenceLenght; i++)
    {
        printf("\nEnter the value for element at positon %d : ", i + 1);
        scanf("%d", &sequence[i]);
    }
    // fill frames initially with -1
    for (int i = 0; i < frameSize; i++)
    {
        frame[i] = -1;
        counter[i] = 0;
    }
    //brain
    int notPresent = 1;
    int min;
    int valueToChange;
    for (int currentPostion = 0; currentPostion < sequenceLenght; currentPostion++)
    {  
        min = 100;
        count++;
         //1 means not present
        notPresent = 1;
        for (int i = 0; i < frameSize; i++)
        {
            if (frame[i] == sequence[currentPostion])
            {   
                //0 means is present
                counter[i] = count;
                notPresent = 0;
                break;
            }
            //when frames are empty
            //-1 means position is empty
            else if(frame[i] == -1){
                pageFaults++;
                frame[i] = sequence[currentPostion];
                counter[i] = count;
                notPresent = 0;
                break;
            }
        }
        if (notPresent == 1)
        {
            for(int i=0;i<frameSize;i++){
                if(counter[i] < min){
                    min = counter[i];
                    valueToChange = frame[i];
                }
            }
            for (int i = 0; i < frameSize; i++)
            {
                if (valueToChange == frame[i])
                {   
                    pageFaults++;
                    frame[i] = sequence[currentPostion];
                    counter[i] = count;
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

// 1 2 3 4 5 4 3 2 1
/*
1-4
2-5
3
*/