class Example extends Thread{
    Example(String name){
        super(name);
    }
    public void run() {
        for(int i=0;i<3;i++){
            System.out.println("This is: "+getName());
        }
    }
}
public class PriorityExample {
    public static void main(String[] args) {
        Example t1=new Example("Stark");
        Example t2=new Example("Charlie");
        Example t3=new Example("Knight");
        t1.setPriority(Thread.MAX_PRIORITY);
        t2.setPriority(Thread.MIN_PRIORITY);
        t3.setPriority(Thread.NORM_PRIORITY);
        t1.start();
        t2.start();
        t3.start();
    }
}
