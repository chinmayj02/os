// OS Expt2- FCFS and SJF cpu scheduling algorithms
// date- 13/09/2022
// 2014006- Chinmay Joshi

#include<iostream>
#include<iomanip>
#include<string>

#define infinity 9999;

using namespace std;

int main(){
    int n; //number of processes
    cout<<"Enter number of processes:";
    cin>>n;
    int *process_id=new int[n];
    int *arrival_time=new int[n];
    int *burst_time=new int[n];
    int *wait_time=new int[n];
    int *completion_time=new int[n];
    int *turnaround_time=new int[n];
    // taking different required inputs
    for(int i=1;i<=n;i++){
        cout<<endl<<"Enter process id for process #"<<i<<" : ";
        cin>>process_id[i];
        cout<<endl<<"Enter arrival time for process #"<<i<<" (process_id:"<<process_id[i]<<"): ";
        cin>>arrival_time[i];
        cout<<endl<<"Enter burst time for process #"<<i<<" (process_id:"<<process_id[i]<<"): ";
        cin>>burst_time[i];
    }
    // FCFS
    bool *completion_record=new bool[n]; //true if a process has completed execution
    for(int i=1;i<=n;i++) completion_record[i]=false;
    int exec_process=1;
    int cpu_time=0;
    int count=0; // count of executed processes
x:  int min_arrival_time=infinity;
    for(int i=n;i>=1;i--){
        // finding process with min arrival time that is yet to be executed
        if(arrival_time[i]<=min_arrival_time && completion_record[i]!=true){
            min_arrival_time=arrival_time[i];
            exec_process=i;
        }
    }
    //check if the first process to be executed has arrival time as initial cpu_time(0)
    // if not,update cpu_time to the arrival time of the first process
    if(count==0 && arrival_time[exec_process]!=0) cpu_time=arrival_time[exec_process]; 
    // execute process with min arrival_time
    completion_record[exec_process]=true;
    cpu_time+=burst_time[exec_process];
    completion_time[exec_process]=cpu_time;
    turnaround_time[exec_process]=completion_time[exec_process]-arrival_time[exec_process];
    wait_time[exec_process]=completion_time[exec_process]-burst_time[exec_process]-arrival_time[exec_process];
    count++;
    // looping until all processes are completed
    for(int i=1;i<=n;i++) if(completion_record[i]!=true) goto x;
    // displaying results in tabular form
    cout<<endl<<"**** Scheduling according to FCFS algorithm ****"<<endl;
    const char space=' ';
    const int width=17;
    cout<<endl<<left<<setw(width)<<setfill(space)<<"process_id";
    cout<<left<<setw(width)<<setfill(space)<<"arrival_time";
    cout<<left<<setw(width)<<setfill(space)<<"burst_time";
    cout<<left<<setw(width)<<setfill(space)<<"completion_time";
    cout<<left<<setw(width)<<setfill(space)<<"wait_time";
    cout<<left<<setw(width)<<setfill(space)<<"turnaround_time";
    for(int i=1;i<=n;i++){
        cout<<endl;
        cout<<left<<setw(width)<<setfill(space)<<process_id[i];
        cout<<left<<setw(width)<<setfill(space)<<arrival_time[i];
        cout<<left<<setw(width)<<setfill(space)<<burst_time[i];
        cout<<left<<setw(width)<<setfill(space)<<completion_time[i];
        cout<<left<<setw(width)<<setfill(space)<<wait_time[i];
        cout<<left<<setw(width)<<setfill(space)<<turnaround_time[i];
    }
    // final results of fcfs
    int wait_time_sum=0;
    int turnaround_time_sum=0;
    for(int i=1;i<=n;i++){
        wait_time_sum+=wait_time[i];
        turnaround_time_sum+=turnaround_time[i];
    }
    float fcfs_avg_wait_and_tat[2]={(float)wait_time_sum/n,(float)turnaround_time_sum/n};
    cout<<endl<<endl;
    cout<<"Average wait time for the processes using FCFS algorithm = "<<fcfs_avg_wait_and_tat[0];
    cout<<endl<<"Average turnaround time for the processes using FCFS algorithm= "<<fcfs_avg_wait_and_tat[1]<<endl;
    
    // SJF
    bool *arrival_status=new bool[n]; // true is a process has already arrived
    for(int i=1;i<=n;i++){
        completion_record[i]=false;
        arrival_status[i]=false;
    }
    exec_process=1;
    cpu_time=0;
    count=0;
    int flag=0; // indicates if first process has arrival time greater than initial cpu_time(0)
x1: for(int i=1;i<=n;i++) if(cpu_time>=arrival_time[i]) arrival_status[i]=true;
    int min_burst_time=infinity;
    for(int i=n;i>=1;i--){
        // finding process that has arrived and has minimum burst_time and is yet to be executed
        if(arrival_status[i]==true){
            if(burst_time[i]<=min_burst_time && completion_record[i]!=true){
                min_burst_time=burst_time[i];
                exec_process=i;
                flag=1;
            }
        }
    }
    // flag=0 if control does not enter the nested if on line 103
    // which means no process has arrival time equal to initial cpu_time(0)
    if(!flag){
        cpu_time++;
        goto x1;
    }
    // execute process with min burst_time
    if(count==0 && arrival_time[exec_process]!=0) cpu_time=arrival_time[exec_process];
    completion_record[exec_process]=true;
    cpu_time+=burst_time[exec_process];
    completion_time[exec_process]=cpu_time;
    turnaround_time[exec_process]=completion_time[exec_process]-arrival_time[exec_process];
    wait_time[exec_process]=completion_time[exec_process]-burst_time[exec_process]-arrival_time[exec_process];
    count++;
    // looping until all processes are completed
    for(int i=1;i<=n;i++) if(completion_record[i]!=true) goto x1;
    // displaying results in tabular form
    cout<<endl<<"**** Scheduling according to SJF algorithm ****"<<endl;
    cout<<endl<<left<<setw(width)<<setfill(space)<<"process_id";
    cout<<left<<setw(width)<<setfill(space)<<"arrival_time";
    cout<<left<<setw(width)<<setfill(space)<<"burst_time";
    cout<<left<<setw(width)<<setfill(space)<<"completion_time";
    cout<<left<<setw(width)<<setfill(space)<<"wait_time";
    cout<<left<<setw(width)<<setfill(space)<<"turnaround_time";
    for(int i=1;i<=n;i++){
        cout<<endl;
        cout<<left<<setw(width)<<setfill(space)<<process_id[i];
        cout<<left<<setw(width)<<setfill(space)<<arrival_time[i];
        cout<<left<<setw(width)<<setfill(space)<<burst_time[i];
        cout<<left<<setw(width)<<setfill(space)<<completion_time[i];
        cout<<left<<setw(width)<<setfill(space)<<wait_time[i];
        cout<<left<<setw(width)<<setfill(space)<<turnaround_time[i];
    }
    // final results of sjf
    wait_time_sum=0;
    turnaround_time_sum=0;
    for(int i=1;i<=n;i++){
        wait_time_sum+=wait_time[i];
        turnaround_time_sum+=turnaround_time[i];
    }
    float sjf_avg_wait_and_tat[2]={(float)wait_time_sum/n,(float)turnaround_time_sum/n};
    cout<<endl<<endl;
    cout<<"Average wait time for the processes = "<<sjf_avg_wait_and_tat[0];
    cout<<endl<<"Average turnaround time for the processes = "<<sjf_avg_wait_and_tat[1]<<endl;

    // final comparison
    cout<<endl<<"**** Comparison between FCFS and SJF ****"<<endl;
    cout<<endl<<left<<setw(width)<<setfill(space)<<"algorithm";
    cout<<left<<setw(width)<<setfill(space)<<"avg_wait_time";
    cout<<left<<setw(width)<<setfill(space)<<"avg_turnaround_time";
    cout<<endl;
    cout<<left<<setw(width)<<setfill(space)<<"FCFS";
    cout<<left<<setw(width)<<setfill(space)<<fcfs_avg_wait_and_tat[0];
    cout<<left<<setw(width)<<setfill(space)<<fcfs_avg_wait_and_tat[1];
    cout<<endl;
    cout<<left<<setw(width)<<setfill(space)<<"SJF";
    cout<<left<<setw(width)<<setfill(space)<<sjf_avg_wait_and_tat[0];
    cout<<left<<setw(width)<<setfill(space)<<sjf_avg_wait_and_tat[1];
    cout<<endl<<endl;
}

/* Sample output

Enter number of processes:3

Enter process id for process #1 : 1001

Enter arrival time for process #1 (process_id:1001): 2

Enter burst time for process #1 (process_id:1001): 5

Enter process id for process #2 : 1002

Enter arrival time for process #2 (process_id:1002): 1

Enter burst time for process #2 (process_id:1002): 7

Enter process id for process #3 : 1003

Enter arrival time for process #3 (process_id:1003): 3

Enter burst time for process #3 (process_id:1003): 3

**** Scheduling according to FCFS algorithm ****

process_id       arrival_time     burst_time       completion_time  wait_time        turnaround_time  
1001             2                5                13               6                11               
1002             1                7                8                0                7                
1003             3                3                16               10               13               

Average wait time for the processes using FCFS algorithm = 5.33333
Average turnaround time for the processes using FCFS algorithm= 10.3333

**** Scheduling according to SJF algorithm ****

process_id       arrival_time     burst_time       completion_time  wait_time        turnaround_time  
1001             2                5                16               9                14               
1002             1                7                8                0                7                
1003             3                3                11               5                8                

Average wait time for the processes = 4.66667
Average turnaround time for the processes = 9.66667

**** Comparison between FCFS and SJF ****

algorithm        avg_wait_time    avg_turnaround_time
FCFS             5.33333          10.3333          
SJF              4.66667          9.66667 

*/