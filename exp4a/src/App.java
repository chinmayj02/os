class A extends Thread{
    public void run(){
        System.out.println("Thread A begins.");
        for (int i = 0; i <= 1000; ++i) {
            System.out.println("Thread A iteration: "+i);
            if(i==20){
                stop();
            }
        }
        System.out.println("Thread A ends.");
    }
}
class B extends Thread{
    public void run(){
        System.out.println("Thread B begins.");
        for (int i = 0; i <= 10; ++i) {
            System.out.println("Thread B iteration: "+i);
        }
        System.out.println("Thread B ends.");
    }
}
public class App{
    public static void main(String[] args){
        System.out.println("Main thread begins.");
        A t1=new A();
        t1.start();
        for(int i=1;i<=5;i++) System.out.println("Main thread iteration: "+i);
        B t2=new B();
        t2.start();
        
        System.out.println("Main thread ends.");

    }
}
/*
Main thread begins.
Main thread iteration: 1
Thread A begins.
Main thread iteration: 2
Main thread iteration: 3
Main thread iteration: 4
Main thread iteration: 5
Thread A iteration: 0
Thread A iteration: 1
Thread A iteration: 2
Thread A iteration: 3
Thread A iteration: 4
Thread A iteration: 5
Thread A iteration: 6
Thread A iteration: 7
Thread A iteration: 8
Thread A iteration: 9
Thread A iteration: 10
Thread A iteration: 11
Thread A iteration: 12
Thread A iteration: 13
Thread A iteration: 14
Thread A iteration: 15
Thread A iteration: 16
Thread A iteration: 17
Thread A iteration: 18
Main thread ends.
Thread B begins.
Thread B iteration: 0
Thread A iteration: 19
Thread A iteration: 20
Thread B iteration: 1
Thread B iteration: 2
Thread B iteration: 3
Thread B iteration: 4
Thread B iteration: 5
Thread B iteration: 6
Thread B iteration: 7
Thread B iteration: 8
Thread B iteration: 9
Thread B iteration: 10
Thread B ends.
*/