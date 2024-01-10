package exceptionTask;
import java.util.Scanner;
class InvalidUsername extends Exception{
	public InvalidUsername(String message) {
		super(message);
	}
}
public class UsernameException {
	public static void validate(String s) throws InvalidUsername {
		if(s.matches(".*[!@#$%^&*()_+\\\\[\\\\]{};':\\\"\\\\\\\\|,.<>?].*")) {
			throw new InvalidUsername("Username contains special characters.");
		}
	}

	public static void main(String[] args) {
		String stg;
		Scanner s = new Scanner(System.in);
		System.out.println("Enter your Username: ");
		stg=s.nextLine();
		try {
			validate(stg);
			System.out.println("Username is valid");
		}
		catch (InvalidUsername e) {
			System.out.println("Invalid user name: \t"+e.getMessage());
		}
	}
}
