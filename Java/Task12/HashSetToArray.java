import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;
import java.util.HashSet;
public class HashSetToArray {
    public static <a> void main(String[] args) {
        Scanner s=new Scanner(System.in);
        HashSet hs=new HashSet<>();
        System.out.println("Enter elements of set separated by space");
        String[] a=s.nextLine().split(" ");
        hs.addAll(Arrays.asList(a));
        Iterator<String> i= hs.iterator();
        String[] n= new String[hs.size()];
        int index=0;
        while(i.hasNext()){
            n[index]=i.next();
            index+=1;
        }
        System.out.println(Arrays.toString(n));
    }
}
