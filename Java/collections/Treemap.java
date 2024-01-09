package Collections;

import java.util.TreeMap;

public class CeilingKey {
	
    public static void main(String[] args) {
        
        TreeMap<Integer, String> Map = new TreeMap<>();

        
        Map.put(1, "One");
        Map.put(4, "Four");
        Map.put(6, "Six");
        Map.put(8, "Eight");
        Map.put(10, "Ten");
        map.put(2, "Two");
      
        int givenKey = 5;
        Integer Key = Map.ceilingKey(givenKey);
        
        String result;
        if (Key != null) {
            result = Map.get(Key);
        } else {
            result = null;
        }
       
        if (result != null) {
            System.out.println("Key: " + Key + ", Value: " + result);
        } else {
            System.out.println("No key strictly less than " + givenKey + " found.");
        }
    }
}
