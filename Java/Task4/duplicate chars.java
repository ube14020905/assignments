package strings;
import java.util.Scanner;
public class CharCount {

	public static void main(String[] args) {
        String s =new String();
        Scanner a=new Scanner(System.in);
        System.out.println("Enter a sentence");
        s=a.nextLine();
        duplicateChars(s);
    }
 
    public static void duplicateChars(String input) {
        input = input.toLowerCase().replaceAll(" ", "");
        int[] charCount = new int[26];

        for (char ch : input.toCharArray()) {
            if (Character.isLetter(ch)) {
                int index = ch - 'a';
                charCount[index]++;
            }
        }
        for (int i = 0; i < charCount.length; i++) {
            if (charCount[i] > 1) {
                char ch = (char) (i + 'a');
                System.out.println("Char: " + ch + ", Count: " + charCount[i] + " times.");
            }
        }
    }

}
