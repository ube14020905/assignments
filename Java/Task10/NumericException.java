package exceptionTask;
import java.util.Scanner;
public class NumaricException {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number as a string: ");
        String s = sc.nextLine();
        try {
            int i = Integer.parseInt(s);
            double d = Double.parseDouble(s);
            System.out.println("Successfully converted to an integer: " + i);
            System.out.println("Successfully converted to a double: " + d);
        } catch (NumberFormatException e) {
            System.out.println("Error: Unable to convert the input to a numeric value.");
        }
     }
}
