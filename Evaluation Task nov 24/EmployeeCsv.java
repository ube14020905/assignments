/*
Evaluation Task
Write a Java program to analyze data stored in a CSV (Comma-Separated Values) file. The CSV
file contains information about employees, with columns like "Name," "Age," "Department," and
"Salary."
The program should provide the following functionalities:
● Average Salary by Department:
Calculate and display the average salary for each department.
● Youngest and Oldest Employee:
Identify and print the names of the youngest and oldest employees.
● Top Earning Employees:
Display the names of the top N earners, where N is a user-input parameter.
 */
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

class Employee{
    private String name;
    private int age;
    private String dept;
    private double salary;

    public Employee(String name, int age, String dept, double salary) {
        this.name = name;
        this.age = age;
        this.dept = dept;
        this.salary = salary;
    }
    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }
    public String getDept() {
        return dept;
    }
    public double getSalary() {
        return salary;
    }
    public String toString() {
        return "Employee{" +
                "name='" + name + '\'' +
                ", age=" + age +
                ", dept='" + dept + '\'' +
                ", salary=" + salary +
                '}';
    }
}
public class EmpCsv {
    static ArrayList<Employee> emp=new ArrayList<>();
    static HashMap<String,Double> Avg=new HashMap<>();
    static HashMap<String,Integer> c=new HashMap<>();
    public static void avg(){
        for (Employee e:emp){
            String dept=e.getDept();
            double sal=e.getSalary();
            Avg.put(dept, Avg.getOrDefault(dept,0.0)+sal);
            c.put(dept, c.getOrDefault(dept,0)+1);
        }
        for(String e:Avg.keySet()){
            Integer i = c.get(e);
            System.out.println(e+" : "+(Avg.get(e)/(double)i));
        }
    }
    public static void add(String[] data){

        emp.add(new Employee(data[0],Integer.parseInt(data[1]),data[2],Double.parseDouble(data[3])));
    }
    public static void youngestEmp(){
        Employee young=null,old=null;
        for(Employee e:emp){
            if(young==null || e.getAge()< young.getAge()){
                young=e;
            }
            if (old == null || e.getAge()> old.getAge()){
                old=e;
            }
        }
        System.out.println("Youngest Employee: "+young.getName()+"\nOldest Employee: "+old.getName());
    }
    public static void topNEaringEmp(int n){
        emp.stream().sorted(Comparator.comparingDouble(Employee::getSalary).reversed()).limit(n).forEach(e-> System.out.println(e.getName()));
    }

    public static void main(String[] args) throws FileNotFoundException {
        String path = "C:\\Users\\ubedu\\IdeaProjects\\Files\\data\\emp.csv";
        File file = new File(path);
        Scanner s = new Scanner(file);
        s.nextLine();
        while(s.hasNext()){
            String[] data=s.nextLine().split(",");
            add(data);
            }
        avg();
        youngestEmp();
        s.close();
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter no. of employees required: ");
        int n=scanner.nextInt();
        topNEaringEmp(n);
    }
}
