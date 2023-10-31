package exceptionTask;
import java.util.Scanner;
public class ArthematicE {

	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		try {
			int a,b;
			System.out.println("Enter Two Integers");
			a=s.nextInt();
			b=s.nextInt();
			System.out.println("Addition : "+(a+b)+"\nSubtraction:" +(a-b)+"\nMultiplication: "+(long)(a*b));
			if(b==0) {
				throw new ArithmeticException("Divisor can't be zero");
			}
			System.out.println("\nDivision: "+(double)a/b);
		}
		catch(ArithmeticException e) {
			System.out.println("Error:\t"+e.getMessage());
		}
	}
}
