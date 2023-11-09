import java.util.function.Predicate;

class JoinExample extends Thread{
    JoinExample(String name){
        super(name);
    }
    public void run() {
        for(int i=0;i<3;i++){
            System.out.println("This is: "+getName());
        }
    }
}
public class JoinAndIsAlive {
    public static void main(String[] args) throws InterruptedException {
        JoinExample t1=new JoinExample("Alpha");
        JoinExample t2=new JoinExample("Charlie");
        t1.start();
        Predicate<JoinExample> j=p->(p.isAlive());
        if(j.test(t1)){
            System.out.println(t1.getName()+" is Alive");
        }
        t1.join();
        t2.start();
        if(j.test(t2)){
            System.out.println(t2.getName()+" is Alive");
        }
    }
}
