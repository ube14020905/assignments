import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
public class CompareSets {
    public static void main(String[] args) {
        HashSet hs1=new HashSet<>();
        HashSet hs2=new HashSet<>();
        Scanner s=new Scanner(System.in);
        System.out.println("Enter elements to set1 separated by space");
        String[] s1=s.nextLine().split(" ");
        hs1.addAll(Arrays.asList(s1));
        System.out.println("Enter elements to set2 separated by space");
        String[] s2=s.nextLine().split(" ");
        hs2.addAll(Arrays.asList(s2));
        if(hs1.equals(hs2)){
            System.out.println("Both sets are same");
        }
        else{
            System.out.println("Both are different sets");
        }
    }
}
