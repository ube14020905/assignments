import java.util.ArrayList;
import java.util.Scanner;
public class ReplaceEle {

	public static void main(String[] args) {
		int n,e;
		ArrayList<Integer> l=new ArrayList<>();
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the no. of elements in List:");
		n=s.nextInt();
		for(int i=0;i<n;i++) {
			l.add(s.nextInt());
		}
		System.out.println("Original ArrayList: " + l);
		if (l.size() >= 2) {
			System.out.print("Enter the new integer to replace the second element: ");
			int r = s.nextInt();
			l.set(1, r);
			System.out.println("Updated ArrayList: " + l);
			}
		else {
			System.out.println("ArrayList does not have at least two elements to replace the second element.");
	        }
	}
}
