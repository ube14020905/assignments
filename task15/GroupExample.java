class MyThread extends Thread {
    public MyThread(ThreadGroup group, String name) {
        super(group, name);
    }
    public void run() {
        System.out.println(Thread.currentThread().getName() + " is performing a specific task.");
    }
}

public class GroupExample {
    public static void main(String[] args) {

        ThreadGroup group = new ThreadGroup("MyThreadGroup");
        MyThread thread1 = new MyThread(group, "Alpha");
        MyThread thread2 = new MyThread(group, "Bravo");
        MyThread thread3 = new MyThread(group, "Charlie");
        thread1.start();
        thread2.start();
        thread3.start();
        group.list();
    }

}
