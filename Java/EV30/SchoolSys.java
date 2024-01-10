import java.util.*;

class Student {
    private String name;
    private List<String> courses;

    public Student(String name, List<String> courses) {
        this.name = name;
        this.courses = courses;
    }

    public String getName() {
        return name;
    }

    public List<String> getCourses() {
        return courses;
    }
}

class School {
    private Map<String, Student> students;

    public School() {
        students = new HashMap<>();
    }

    public void addStudent(String name, List<String> courses) {
        Student student = new Student(name, courses);
        students.put(name, student);
    }

    public void removeStudent(String name) {
        students.remove(name);
    }

    public void addCourseToStudent(String name, String course) {
        Student student = students.get(name);
        if (student != null) {
            student.getCourses().add(course);
        }
    }

    public void removeCourseFromStudent(String name, String course) {
        Student student = students.get(name);
        if (student != null) {
            student.getCourses().remove(course);
        }
    }

    public List<String> getStudentCourses(String name) {
        Student student = students.get(name);
        if (student != null) {
            return student.getCourses();
        }
        return new ArrayList<>();
    }
}

public class SchoolSys {
    public static void main(String[] args) {
        School school = new School();
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("Enter an option \n1. Add Student \n2. Remove Student \n3. Add Course to Student \n4. Remove Course from Student \n5. Get Student Courses \n6. Exit");

            int option = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            switch (option) {
                case 1:
                    System.out.print("Enter student name: ");
                    String name = scanner.nextLine();
                    System.out.print("Enter courses (comma-separated): ");
                    String coursesInput = scanner.nextLine();
                    List<String> courses = Arrays.asList(coursesInput.split(","));
                    school.addStudent(name, courses);
                    break;
                case 2:
                    System.out.print("Enter student name to remove: ");
                    name = scanner.nextLine();
                    school.removeStudent(name);
                    break;
                case 3:
                    System.out.print("Enter student name: ");
                    name = scanner.nextLine();
                    System.out.print("Enter course to add: ");
                    String courseToAdd = scanner.nextLine();
                    school.addCourseToStudent(name, courseToAdd);
                    break;
                case 4:
                    System.out.print("Enter student name: ");
                    name = scanner.nextLine();
                    System.out.print("Enter course to remove: ");
                    String courseToRemove = scanner.nextLine();
                    school.removeCourseFromStudent(name, courseToRemove);
                    break;
                case 5:
                    System.out.print("Enter student name: ");
                    name = scanner.nextLine();
                    List<String> studentCourses = school.getStudentCourses(name);
                    System.out.println(name + "'s courses: " + studentCourses);
                    break;
                case 6:
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid option. Please try again.");
            }
        }
    }
}
