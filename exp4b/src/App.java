class A implements Runnable{
    public void run(){
        System.out.println("Thread A begins.");
        for (int i = 0; i <= 5; ++i) System.out.println("Thread A iteration: "+i);
        System.out.println("Thread A ends.");    
    }
}
class B implements Runnable{
    public void run(){
        System.out.println("Thread B begins.");
        for (int i = 0; i <= 10; ++i) System.out.println("Thread B iteration: "+i);
        System.out.println("Thread B ends.");
    }

}
public class App{
    public static void main(String[] args){        
        A t1=new A();
        Thread T1=new Thread(t1);
        B t2=new B();
        Thread T2=new Thread(t2);
        T1.start();
        for(int i=1;i<=10;i++) System.out.println("Main class iteration #"+i);
        T2.start();        
    }
}
/*
Main class iteration #1
Main class iteration #2
Main class iteration #3
Main class iteration #4
Main class iteration #5
Thread A begins.
Main class iteration #6
Thread A iteration: 0
Thread A iteration: 1
Thread A iteration: 2
Thread A iteration: 3
Thread A iteration: 4
Thread A iteration: 5
Thread A ends.
Main class iteration #7
Main class iteration #8
Main class iteration #9
Main class iteration #10
Thread B begins.
Thread B iteration: 0
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