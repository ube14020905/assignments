import java.util.TreeMap;

public class GreatestKey {
    public static void main(String[] args) {
        
        TreeMap<Integer, String> Map = new TreeMap<>();

        
        Map.put(1, "One");
        Map.put(4, "Four");
        Map.put(6, "Six");
        Map.put(8, "Eight");
        Map.put(10, "Ten");
        
        System.out.println(Map);

       
        int givenKey = 7;

       
        Integer lowerKey = Map.lowerKey(givenKey);
        
        String result;
        if (lowerKey != null) {
            result = Map.get(lowerKey);
        } else {
            result = null;
        }

       
        if (result != null) {
            System.out.println("Key: " + lowerKey + ", Value: " + result);
        } else {
            System.out.println("No key strictly less than " + givenKey + " found.");
        }
    }
}
