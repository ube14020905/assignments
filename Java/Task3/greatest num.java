import java.util.Scanner;
public class GreatestNum {

	public static void main(String[] args) {
		 int n;
			System.out.println("Enter the size of array:");
			Scanner s=new Scanner(System.in);
			n=s.nextInt();
			int[] arr=new int[n];
			System.out.println("Enter Array elements:");
			for(int i=0;i<n;i++) {
				arr[i]=s.nextInt();
			}
			int g=greatest(arr);
	        System.out.println("The greatest number: "+g);
	        
	    }
	public static int greatest(int[] arr) {
		int g=0;
		for(int i=1;i<arr.length;i++) {
			if(arr[i] > arr[i-1]){
				g=arr[i];
			}
		}
		return g;
	}

}
