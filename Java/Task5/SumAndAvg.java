import java.util.Scanner;
public class SumAndAvg {

	public static void main(String[] args) {
		int n;
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the Size of array : ");
		n=s.nextInt();
		int[] a = new int[n];
		System.out.println("Enter the elements of array :");
		int sum=0;
		for(int i=0;i<n;i++) {
			a[i]=s.nextInt();
			sum+=a[i];
		}
		System.out.println("The sum of all integers in the array is : "+sum);
		System.out.println("The Average of all integers in the array is : "+sum/n);
	}

}
