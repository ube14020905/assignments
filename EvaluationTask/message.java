class Sender extends Thread {
    private final Message message;
    public Sender(Message message) {
        this.message = message;
    }
    public void run() {
        String[] messages = {"Hello", "How are you?", "How's the josh","Goodbye"};
        for (String msg : messages) {
            message.writeMessage(msg);
            System.out.println("Sent: " + msg);
           try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
class Receiver extends Thread {
    private final Message message;
    public Receiver(Message message) {
        this.message = message;
    }
    public void run() {
        for (int i = 0; i < 3; i++) {
            String receivedMessage = message.readMessage();
            System.out.println("Received: " + receivedMessage);
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
    }
}
