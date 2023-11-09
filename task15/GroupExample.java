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
        displayThreadGroupDetails(group);
    }
    private static void displayThreadGroupDetails(ThreadGroup group) {
        System.out.println("Thread Group Name: " + group.getName());
        System.out.println("Thread Group Active Count: " + group.activeCount());
        Thread[] threads = new Thread[group.activeCount()];
        group.enumerate(threads);
        System.out.println("Threads in Thread Group:");
        for (Thread thread : threads) {
            System.out.println(" - " + thread.getName());
        }
    }
}
