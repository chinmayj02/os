class A implements Runnable{
    
    public void run(){
        for(int i=1;i<=10;i++) System.out.println("Class A iteration #"+i);
    }
}
class B implements Runnable{
    public void run(){
        for(int i=1;i<=10;i++) System.out.println("Class B iteration #"+i);
    }
}
class C implements Runnable{
    public void run(){
        for(int i=1;i<=10;i++) System.out.println("Class C iteration #"+i);
    }
}
public class App{
    public static void main(String[] args){
        // new A().start();
        // new B().start();
        // new C().start();
        
        A t1=new A();
        B t2=new B();
        C t3=new C();
        Thread T1=new Thread(t1);
        Thread T2=new Thread(t2);
        Thread T3=new Thread(t3);
        T1.start();
        T2.start();
        T3.start();
        
        for(int i=1;i<=100;i++) System.out.println("Main class iteration #"+i);
    }
}
/*
Class A iteration #1
Class A iteration #2
Class A iteration #3
Class A iteration #4
Class A iteration #5
Class A iteration #6
Class A iteration #7
Class A iteration #8
Class A iteration #9
Class A iteration #10
Class B iteration #1
Class B iteration #2
Class B iteration #3
Class B iteration #4
Class B iteration #5
Class B iteration #6
Class B iteration #7
Class B iteration #8
Class B iteration #9
Class B iteration #10
Main class iteration #1
Main class iteration #2
Main class iteration #3
Main class iteration #4
Main class iteration #5
Main class iteration #6
Main class iteration #7
Main class iteration #8
Main class iteration #9
Main class iteration #10
Main class iteration #11
Main class iteration #12
Main class iteration #13
Main class iteration #14
Main class iteration #15
Main class iteration #16
Main class iteration #17
Main class iteration #18
Main class iteration #19
Main class iteration #20
Main class iteration #21
Main class iteration #22
Main class iteration #23
Main class iteration #24
Main class iteration #25
Main class iteration #26
Main class iteration #27
Main class iteration #28
Main class iteration #29
Main class iteration #30
Main class iteration #31
Main class iteration #32
Class C iteration #1
Main class iteration #33
Main class iteration #34
Main class iteration #35
Main class iteration #36
Main class iteration #37
Main class iteration #38
Main class iteration #39
Main class iteration #40
Main class iteration #41
Main class iteration #42
Main class iteration #43
Main class iteration #44
Main class iteration #45
Main class iteration #46
Main class iteration #47
Main class iteration #48
Main class iteration #49
Main class iteration #50
Main class iteration #51
Main class iteration #52
Class C iteration #2
Main class iteration #53
Main class iteration #54
Main class iteration #55
Main class iteration #56
Main class iteration #57
Main class iteration #58
Main class iteration #59
Main class iteration #60
Main class iteration #61
Main class iteration #62
Main class iteration #63
Main class iteration #64
Main class iteration #65
Main class iteration #66
Main class iteration #67
Main class iteration #68
Main class iteration #69
Main class iteration #70
Main class iteration #71
Main class iteration #72
Main class iteration #73
Main class iteration #74
Main class iteration #75
Main class iteration #76
Main class iteration #77
Main class iteration #78
Main class iteration #79
Main class iteration #80
Main class iteration #81
Main class iteration #82
Main class iteration #83
Main class iteration #84
Main class iteration #85
Main class iteration #86
Main class iteration #87
Main class iteration #88
Main class iteration #89
Main class iteration #90
Main class iteration #91
Main class iteration #92
Main class iteration #93
Main class iteration #94
Main class iteration #95
Main class iteration #96
Main class iteration #97
Main class iteration #98
Main class iteration #99
Main class iteration #100
Class C iteration #3
Class C iteration #4
Class C iteration #5
Class C iteration #6
Class C iteration #7
Class C iteration #8
Class C iteration #9
Class C iteration #10
*/