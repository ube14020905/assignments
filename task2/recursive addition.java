import java.util.Scanner;
public class Addition {
	 public static int add(int a, int b) {
	        if (b == 0) {
	            return a;
	        } else {
	            return add(a + 1, b - 1);
	        }
	    }
	public static void main(String[] args) {
		int a,b;
	    Scanner s=new Scanner(System.in);
	    System.out.println("Enter a value:");
	    a=s.nextInt();
	    System.out.println("Enter b value:");
	    b=s.nextInt();
        int sum = add(a, b);	        
        System.out.println("The sum of " + a + " and " + b + " is: " + sum);
	}

}
