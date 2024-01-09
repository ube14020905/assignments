import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class HashMapStream {
    public static void main(String[] args) {
        Map<String, Integer> hashMap = new HashMap<>();
        hashMap.put("Apple", 10);
        hashMap.put("Banana", 5);
        System.out.println("Step 1: Print all map values by iteration");
        for (Map.Entry<String, Integer> entry : hashMap.entrySet()) {
            System.out.println("Key: " + entry.getKey() + ", Value: " + entry.getValue());
        }
        System.out.println("\nStep 2: Print keys alone");
        for (String key : hashMap.keySet()) {
            System.out.println("Key: " + key);
        }
        hashMap.put("Cherry", 7);
        System.out.println("\nStep 4: Print the first 2 keys alone without printing all the keys using streams");
        hashMap.keySet().stream().limit(2).forEach(key -> System.out.println("Key: " + key));
    }
}
