public class Message {
    private String message;
    private boolean status = false;

    public synchronized String readMessage() {
        while (!status) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        status = false;
        notify();
        return message;
    }
    public synchronized void writeMessage(String message) {
        while (status) {
            try {
                wait();
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        this.message = message;
        status = true;
        notify();
    }
}
