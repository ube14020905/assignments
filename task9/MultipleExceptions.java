package exceptionTask;
import java.util.Scanner;
import java.util.InputMismatchException;
public class MultipleExceptions {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int[] ar=new int[6];
		try {
			System.out.println("Enter array elements");
			for(int i=0;i<6;i++) {
				ar[i]=s.nextInt();
			}
			System.out.println("Enter the index of no. you want");
			int n=s.nextInt();
			System.out.println(ar[n]);
		}
		catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("Array index out of bound exception "+e.getMessage());
		}
		catch(InputMismatchException e) {
			System.out.println("Enter integer values only");
		}
	}

}
