import java.util.concurrent.Semaphore;

class Philosopher extends Thread {
  private Semaphore leftFork;
  private Semaphore rightFork;
  private int id;

  public Philosopher(int id, Semaphore leftFork, Semaphore rightFork) {
    this.id = id;
    this.leftFork = leftFork;
    this.rightFork = rightFork;
  }

  public void run() {
    while (true) {
      try {
        System.out.println("Philosopher " + id + " is thinking.");
        sleep((int)(Math.random() * 1000));

        System.out.println("Philosopher " + id + " is hungry.");
        leftFork.acquire();
        System.out.println("Philosopher " + id + " picked up left fork.");
        rightFork.acquire();
        System.out.println("Philosopher " + id + " picked up right fork.");

        System.out.println("Philosopher " + id + " is eating.");
        sleep((int)(Math.random() * 1000));

        System.out.println("Philosopher " + id + " finished eating.");
        leftFork.release();
        System.out.println("Philosopher " + id + " put down left fork.");
        rightFork.release();
        System.out.println("Philosopher " + id + " put down right fork.");
      } catch (InterruptedException e) {
        System.out.println("Philosopher " + id + " was interrupted.");
        break;
      }
    }
  }
}

public class App {
  public static void main(String[] args) {
    int numPhilosophers = 5;
    Semaphore[] forks = new Semaphore[numPhilosophers];

    for (int i = 0; i < numPhilosophers; i++) {
      forks[i] = new Semaphore(1);
    }

    Philosopher[] philosophers = new Philosopher[numPhilosophers];

    for (int i = 0; i < numPhilosophers; i++) {
      Semaphore leftFork = forks[i];
      Semaphore rightFork = forks[(i + 1) % numPhilosophers];
      philosophers[i] = new Philosopher(i, leftFork, rightFork);
      philosophers[i].start();
    }
  }
}
