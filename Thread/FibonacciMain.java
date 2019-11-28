import java.util.*;
public class FibonacciMain
{ 
    public static void main(String[] args) 
    { 
        try
        {
            Scanner scan = new Scanner(System.in);
            System.out.println("Enter N : ");
            int N = scan.nextInt();
            scan.close();
            int[] array = new int[N];
            for (int i = 0; i < N; i++) 
            { 
                Fibonacci object = new Fibonacci(array, i); 
                object.start();
                object.join();
            }
            System.out.print("[ ");
            for(int i : array)
            {
                System.out.print(i + " ");
            }
            System.out.println("]");
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
    }
} 