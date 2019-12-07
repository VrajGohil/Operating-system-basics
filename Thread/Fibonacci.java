import java.lang.Thread;
class Fibonacci extends Thread 
{ 
    int[] array;
    int i;
    Fibonacci(int[] fib_arr, int i)
    {
        this.array = fib_arr;
        this.i = i;
    }
    public void run() 
    { 
        try
        { 
            if(this.i == 0)
                this.array[this.i] = 0;
            else if(this.i == 1 || this.i == 2)
                this.array[this.i] = 1;
            else
            {
                this.array[i] = this.array[i-1] + this.array[i-2];
            }
        } 
        catch (Exception e) 
        { 
            System.out.println ("Exception : " + e); 
        } 
    } 
} 