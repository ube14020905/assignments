import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class SpecifiedKey {
    public static void main(String[] args) {
        Map<Integer, String> list = new HashMap<>();

        list.put(1, "Tirupati");
        list.put(2, "Chennai");
        list.put(3, "Banglore");
        list.put(4, "Mumbai");
        list.put(5, "Delhi");
        list.put(6, "Pune");
        System.out.println(list);

        Integer specifiedKey = 2;
        String value = list.get(specifiedKey);
        if (value != null) {
            System.out.println("Value for key '" + specifiedKey + "': " + value);
        } else {
            System.out.println("Key '" + specifiedKey + "' not found in the HashMap.");
        }
        System.out.println("Key Set of the HashMap:");
        Set<Integer> keySet = list.keySet();
        for (Integer key : keySet) {
            System.out.println(key);
        }
    }
}
