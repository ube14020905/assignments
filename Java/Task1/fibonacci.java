import java.util.*;
public class Fibbo {
	public void fib(int n) {
		 	int firstNumber = 0;
	        int secondNumber = 1;

	        System.out.println("Fibonacci series of " + n + " numbers:");

	        for (int i = 1; i <= n; i++) {
	            System.out.print(firstNumber + " ");

	            int nextNumber = firstNumber + secondNumber;
	            firstNumber = secondNumber;
	            secondNumber = nextNumber;
	        }
	}
	public static void main(String[] args) {
		int n;
		Scanner s=new Scanner(System.in);
		n=s.nextInt();
		Fibbo f=new Fibbo();
		f.fib(n);

	}
}
