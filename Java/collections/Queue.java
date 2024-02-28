import java.util.Arrays;
import java.util.PriorityQueue;
public class Pq {=
	public static void main(String[] args) {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.offer(15);
		pq.offer(10);
		pq.offer(5);
		pq.offer(2);
		pq.offer(7);
		System.out.println(pq);
		
		Integer[] array = pq.toArray(new Integer[pq.size()]);
		
		System.out.println("Elements in the Array: "+ Arrays.toString(array));

	}

}
