class Even extends Thread {
    public void run() {
        for (int i = 0; i < 10; i++) {
            if (i % 2 == 0) {
                System.out.println(i);
            }
        }
    }
}
class Odd extends Thread{
    public void run() {
        for (int i = 0; i < 10; i++) {
            if (i % 2 != 0) {
                System.out.println(i);
            }
        }
    }
}

public class EvenOddUsingThread {
    public static void main(String[] args) {
        System.out.println("Even odd using Multithreading");
        Even e=new Even();
        Odd o=new Odd();
        e.start();
        o.start();
    }
}
