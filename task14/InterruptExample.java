class Bravo extends Thread{
    public void run() {
        try {
            for (int i=0;i<Integer.MAX_VALUE;i++) {
                sleep(1000);
                System.out.println("This is Thread Bravo: "+i);
            }
        } catch (InterruptedException e) {
            System.err.println(e);
        }
    }
}
public class InterruptExample {
    public static void main(String[] args) throws InterruptedException {
        Bravo b=new Bravo();
        b.start();
        Thread.sleep(5000);
        b.interrupt();
    }
}
