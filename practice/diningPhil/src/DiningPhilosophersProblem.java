import java.util.concurrent.Semaphore;

class Chopstick {
    public Semaphore mutex = new Semaphore(1);
    void grab() {
        try {
            mutex.acquire();
        } catch (Exception e) {}
    }
    void release() {
        mutex.release();
    }
    boolean isFree() {
        return mutex.availablePermits() > 0;
    }
} 
class Philosopher extends Thread {
    public int number;
    public Chopstick leftchopstick;
    public Chopstick rightchopstick;
    Philosopher(int num, Chopstick left, Chopstick right) {
        number = num;
        leftchopstick = left;
        rightchopstick = right;
    }
    public void run() {
        while (true) {
            if(leftchopstick.isFree())leftchopstick.grab();
            System.out.println("Philosopher " + (number + 1) + " grabs left chopstick.");
            if(rightchopstick.isFree())rightchopstick.grab();
            System.out.println("Philosopher " + (number + 1) + " grabs right chopstick.");
            eat();
            leftchopstick.release();
            System.out.println("Philosopher " + (number + 1) + " releases left chopstick.");
            rightchopstick.release();
            System.out.println("Philosopher " + (number + 1) + " releases right chopstick.");
        } 
    }  
    void eat() {
        try {
            int sleepTime =5;
            System.out.println("Philosopher " + (number + 1) + " eats for " + sleepTime + "ms");
            Thread.sleep(sleepTime);
        } catch (Exception e) {}
    }
}

public class DiningPhilosophersProblem {
    static int philosopher = 5;
    static Philosopher philosophers[] = new Philosopher[philosopher];
    static Chopstick chopsticks[] = new Chopstick[philosopher];
    public static void main(String args[]) {
        for (int i = 0; i < philosopher; i++) {
            chopsticks[i] = new Chopstick();
        }  
        for (int i = 0; i < philosopher; i++) {
            philosophers[i] = new Philosopher(i, chopsticks[i], chopsticks[(i + 1) % philosopher]);
            philosophers[i].start();
        } 
        while (true) {
            try {
                Thread.sleep(10);
                boolean deadlock=true;
                for (Chopstick cs : chopsticks) {
                    if (cs.isFree()) {
                        deadlock = false;
                        break;
                    } 
                } 
                if (deadlock) {
                    Thread.sleep(2000);
                    System.out.println("deadlock");
                    break;
                }
                else {
                    Thread.sleep(2000);
                    System.out.println("everyone eats");
                    break;
                }
            } 
            catch (Exception e) {}
        }
        System.out.println("Exit The Program!");
        System.exit(0);
    }
}