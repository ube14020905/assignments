class First extends Thread{
    @Override
    public void run() {
        for (int i=0;i<5;i++){
            System.out.println("hello!");
        }
    }
}
class Second extends Thread{
    @Override
    public void run() {
        for (int i=0;i<5;i++){
            System.out.println("hi!");
        }
    }
}
public class FirstCodeThread {
    public static void main(String[] args) {
        First f=new First();
        Second s=new Second();
        f.start();
        s.start();
    }
}
