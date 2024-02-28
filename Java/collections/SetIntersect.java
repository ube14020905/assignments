import java.util.Set;
import java.util.HashSet;
public class SetIntersect {

	public static void main(String[] args) {
		
		Set<Integer> s1 = new HashSet<>();
		Set<Integer> s2 = new HashSet<>();
		
		s1.add(45);
		s1.add(1);
		s1.add(48);
		s1.add(78);
		s1.add(10);
    
		s2.add(45);
		s2.add(18);
		s2.add(89);
		s2.add(10);
		s2.add(21);
    
		System.out.println("The first set elements: ");
		System.out.println(s1);
		System.out.println("The Secong set elements: ");
		System.out.println(s2);
		
		s1.retainAll(s2);
		
		System.out.println("The Common elements between two sets: "+ s1);

	}

}
