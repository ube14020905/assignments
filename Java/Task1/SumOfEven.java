import java.util.Scanner;
public class SumOfEven {

	public static void main(String[] args) {
		int n=100,s=0;
		while(n!=0) {
			if(n%2==0) {
				s+=n;
			}
			n-=1;
		}
		System.out.println("sum of 1 to 100 is "+s);
	}

}
