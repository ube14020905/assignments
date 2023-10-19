import java.util.Scanner;
public class Student {
	private int subs=6;
	private String name;
	private int[] credits= {3,4,2,3,4,3};
	public Student(String name) {
		this.name=name;
	}
	public int[] getPoints()
	{
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the marks of students");
		int[] marks=new int[this.subs];
		for(int i=0;i<this.subs;i++) {
			marks[i]=s.nextInt();
		}
		return marks;
	}
	public int total() {
		int t=0;
		int[] marks=this.getPoints();
		for(int i=0;i<marks.length;i++) {
			t+=marks[i]*this.credits[i];
		}
		return t;
	}
	public double avg() {
		double s=0;
		for(int i=0;i<this.credits.length;i++) {
			s+=(double)this.credits[i];
		}
		return this.total()/s;
	}
	public String grade() {
		double avg=this.avg();
		if(avg>=9.1) {
			return "S Grade";
		}
		else if(avg>7.4) {
			return "A Grade";
		}
		else if(avg>6.4) {
			return "B Grade";
		}
		else if(avg>5.4) {
			return "C Grade";
		}
		else if(avg>4.4) {
			return "D Grade";
		}
		else if(avg>3.4) {
			return "E Grade";
		}
		else {
			return "Fail";
		}
	}
	public static void main(String[] args) {

		Student s1=new Student("Shaik");
		System.out.println(s1.grade());
	}

}
