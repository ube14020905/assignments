import java.util.Scanner;
import java.util.TreeSet;
public class LowerValue {

	public static void main(String[] args) {
		
		TreeSet<Integer> s = new TreeSet<>();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter n value to set: ");
		int n = sc.nextInt();
		System.out.println("Enter the list: ");
		for(int i=0; i<n; i++) {
			s.add(sc.nextInt());
		}
		
		System.out.println(s);
		
		System.out.println("Enter a givenElement");
		int a = sc.nextInt();
		int givenElement = a;
		
		Integer Lower = s.lower(givenElement);
		
		if(Lower != null) {
			System.out.println("Element in the TreeSet lower than " + givenElement + ": " + Lower);
		}
		else {
			 System.out.println("No element found in the TreeSet lower than " + givenElement);
		}
	}

}
