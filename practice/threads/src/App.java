import java.lang.Thread;
import java.lang.Exception;

class A extends Thread{
    public void run(){
        System.out.println("\nThread A starts here.\n");
        for(int i=0;i<10;i++){
            System.out.println("Iteration "+i);
            if(i==4){
                System.out.println("i=4");
                try{
                    sleep(5000);
                }
                catch(Exception e){

                }
            }
        }
        System.out.println("\nThread A ends here.\n");
    }
}

class B extends Thread{
    public void run(){
        System.out.println("\nThread B starts here.\n");
        for(int i=0;i<10;i++){
            System.out.println("Iteration "+i);
            if(i==4){
                System.out.println("i=4");
                try{
                    stop();
                }
                catch(Exception e){

                }
            }
        }        
        System.out.println("\nThread B ends here.\n");
    }
}

public class App {
    public static void main(String[] args) throws Exception {
        A t1=new A();
        t1.start();
        B t2=new B();
        t2.start();
    }
}
