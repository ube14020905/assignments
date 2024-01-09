import java.util.Scanner;

class TypeCheck {
    void type(int value) {
        System.out.println("Input is an integer.");
    }

    void type(float value) {
        System.out.println("Input is a float.");
    }

    void type(boolean value) {
        System.out.println("Input is a boolean.");
    }
}

public class Polymorphism {
    public static void main(String[] args) {
        
        TypeCheck data = new TypeCheck();
        Scanner s = new Scanner(System.in);

        System.out.print("Enter a value: ");
        if (s.hasNextInt()) {
            int inputValue = s.nextInt();
            data.type(inputValue);
        } else if (s.hasNextFloat()) {
            float inputValue = s.nextFloat();
            data.type(inputValue);
        } else if (s.hasNextBoolean()) {
            boolean inputValue = s.nextBoolean();
            data.type(inputValue);
        } else {
            System.out.println("Input is String");
        }
    }
}
