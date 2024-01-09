import java.util.Scanner;
class Sender extends Thread {
    private final Message message;
    public Sender(Message message) {
        this.message = message;
    }
    public void run() {
        Scanner s= new Scanner(System.in);
        System.out.println("Enter String separated by comma: ");
        String[] messages =s.nextLine().split(",");
        for (String msg : messages) {
            message.writeMessage(msg);
            System.out.println("Sent: " + msg);
           try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        message.writeMessage(null);
        s.close();
    }
}
class Receiver extends Thread {
    private final Message message;
    public Receiver(Message message) {
        this.message = message;
    }
    public void run() {
        while(true){
            String receivedMessage = message.readMessage();
            if(receivedMessage==null){
                break;
            }
            else {
                System.out.println("Received: " + receivedMessage);
            }
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
public class Messenger {
    public static void main(String[] args) {
        Message message = new Message();
        Sender sender = new Sender(message);
        Receiver receiver = new Receiver(message);

        sender.start();
        receiver.start();
        try{
            sender.join();
            receiver.join();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
