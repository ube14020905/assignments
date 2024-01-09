import java.util.Scanner;
import java.util.InputMismatchException;
public class FactUsingExcept{

	public static void main(String[] args) {
		int fact=1;
		try {
			Scanner s = new Scanner(System.in);
			System.out.println("Enter a number");
			int n=s.nextInt();
			if (n<0){
				throw new InvalidNumberException("Negative values doesn't have Factorial");
			}
			else if(n==0) {
				fact=1;
			}
			else {
				for(int i=1;i<=n;i++) {
					fact=n*fact;
				}
			}
			if(fact<=0) {
				throw new ArithmeticException("the result exceeded int max value");
			}
			System.out.println("The factorial of "+n+"is : "+fact);
		}
		catch(InvalidNumberException i) {
			System.err.println("Error: "+i.getMessage());
		}
		catch(ArithmeticException a) {
			System.err.println("Error: "+a.getMessage());
		}
		catch(InputMismatchException r) {
			System.err.println("Enter Integers Only");
		}
	}

}
class InvalidNumberException extends Exception{
	public InvalidNumberException(String m) {
		super(m);
	}
}
