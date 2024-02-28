import java.util.LinkedList;
import java.util.Scanner;
public class GetFL {

	public static void main(String[] args) {
	int a;
	Scanner s = new Scanner(System.in);
	LinkedList<Integer> l =new LinkedList<>();
	System.out.println("Enter the no. of elements in the list: ");
	a=s.nextInt();
	for(int i=0;i<a;i++) {
		l.add(s.nextInt());
	}
	System.out.println("Original list: "+ l);
	System.out.println("first element of list: "+ l.get(0));
	
	}

}
