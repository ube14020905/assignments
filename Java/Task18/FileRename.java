import java.io.File;
import java.io.IOException;

public class FileTask1 {
    static boolean createFile(String path) throws IOException {
        File f=new File(path);
        return f.createNewFile();
    }
    static boolean renameFile(String oldPath,String newPath){
        File oName=new File(oldPath);
        File nName=new File(newPath);

        return oName.renameTo(nName);
    }
    public static void main(String[] args) throws IOException {
        System.out.println(createFile("C:\\Users\\ubedu\\IdeaProjects\\Files\\data\\fileTask.txt") ? "File created" : "Failed to create new file");
        System.out.println(renameFile("C:\\Users\\ubedu\\IdeaProjects\\Files\\data\\fileTask.txt","C:\\Users\\ubedu\\IdeaProjects\\Files\\data\\fileTask1.txt") ? "File Renamed" : "Failed to Rename");
    }
}
