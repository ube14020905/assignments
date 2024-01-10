package exceptionTask;

public class ThrowThrows {
    public static void throwExample(int value) {
        if (value < 0) {
            throw new IllegalArgumentException("Negative value is not allowed.");
        }
        System.out.println("Value is valid: " + value);
    }
    public static void throwsExample(int value) throws IllegalArgumentException {
        if (value < 0) {
            throw new IllegalArgumentException("Negative value is not allowed.");
        }
        System.out.println("Value is valid: " + value);
    }

    public static void main(String[] args) {
        try {
            throwExample(-5);
        } catch (IllegalArgumentException e) {
            System.out.println("IllegalArgumentException caught: " + e.getMessage());
        }

        try {
            throwsExample(-5);
        } catch (IllegalArgumentException e) {
            System.out.println("IllegalArgumentException caught: " + e.getMessage());
        }
    }
}
