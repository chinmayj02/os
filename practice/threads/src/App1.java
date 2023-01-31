import java.lang.Thread;
import java.lang.Runnable;
import java.lang.Exception;

class C implements Runnable{
    public void run(){
        System.out.println("\nThread A starts here.\n");
        for(int i=0;i<10;i++){
            System.out.println("Iteration "+i);
            if(i==4){
                System.out.println("i=4");
                try{
                    //sleep(5000);
                }
                catch(Exception e){

                }
            }
        }
        System.out.println("\nThread A ends here.\n");
    }
}

class D implements Runnable{
    public void run(){
        System.out.println("\nThread B starts here.\n");
        for(int i=0;i<10;i++){
            System.out.println("Iteration "+i);
            if(i==4){
                System.out.println("i=4");
                try{
                    //stop();
                }
                catch(Exception e){

                }
            }
        }        
        System.out.println("\nThread B ends here.\n");
    }
}

public class App1 {
    public static void main(String[] args) throws Exception {
        C t1=new C();
        Thread T1=new Thread(t1);
        T1.start();
        D t2=new D();
        Thread T2=new Thread(t2);
        T2.start();
    }
}