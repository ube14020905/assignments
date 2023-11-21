import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class FileTask2 {
    public static void appendToFile(File file,String data) throws IOException {
        FileWriter writer=new FileWriter(file,true);
        writer.append(data);
        writer.flush();
        writer.close();
    }
    public static void main(String[] args) throws IOException {
        Scanner s=new Scanner(System.in);
        String data=s.nextLine();
        File file=new File("C:\\Users\\ubedu\\IdeaProjects\\Files\\data\\fileTask1.txt");
        appendToFile(file,data);
    }
}
