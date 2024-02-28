package exceptionTask;
public class MultiCatchFinnally {
	
	public static void main(String[] args) {
        try {
            outerMethod();
        } catch (Exception e) {
            System.out.println("Exception caught in the main method: " + e.getMessage());
        }
    }

    public static void outerMethod() {
        try {
            System.out.println("Entering outerMethod");
            innerMethod();
            System.out.println("Exiting outerMethod");
        } catch (ArithmeticException e) {
            System.out.println("ArithmeticException caught in outerMethod: " + e.getMessage());
        } finally {
            System.out.println("Finally block in outerMethod");
        }
    }

    public static void innerMethod() {
        try {
            System.out.println("Entering innerMethod");
            int result = 10 / 0;
            System.out.println("Exiting innerMethod");
        }catch(ArithmeticException e) {
        	System.out.println("Divisor can't be zero");
        }
        catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("ArrayIndexOutOfBoundsException caught in innerMethod: " + e.getMessage());
        } finally {
            System.out.println("Finally block in innerMethod");
        }
    }
}
