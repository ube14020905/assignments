import java.util.Scanner;
public class Multiplication {
	 public static int mul(int a, int b) {
	        if (b == 0) {
	            return 0;
	            }
	        else if (b < 0) {
	            return -mul(a, -b); 
	        } else if (b == 1) {
	            return a;
	        } else {
	            return a + mul(a, b - 1);
	            }
	    }
	public static void main(String[] args) {
		int a,b;
	    Scanner s=new Scanner(System.in);
	    System.out.println("Enter a value:");
	    a=s.nextInt();
	    System.out.println("Enter b value:");
	    b=s.nextInt();
        int m = mul(a, b);	        
        System.out.println("The multiplication of " + a + " and " + b + " is: " + m);
	}

}
