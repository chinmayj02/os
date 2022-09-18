// OS Expt3- SRTF and RR cpu scheduling algorithms
// date- 17/09/2022
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
    int *priority=new int[n];
    // taking different required inputs
    for(int i=1;i<=n;i++){
        // cout<<endl<<"Enter process id for process #"<<i<<" : ";
        // cin>>process_id[i];
        cout<<endl<<"Enter arrival time for process #"<<i<<" (process_id:"<<process_id[i]<<"): ";
        cin>>arrival_time[i];
        cout<<endl<<"Enter burst time for process #"<<i<<" (process_id:"<<process_id[i]<<"): ";
        cin>>burst_time[i];
        // cout<<endl<<"Enter priority for process #"<<i<<" (process_id:"<<process_id[i]<<")[lower number higher priority]: ";
        // cin>>priority[i];
    }
    // SRTF
    bool *completion_record=new bool[n]; //true if a process has completed execution
    bool *arrival_status=new bool[n]; // true is a process has already arrived
    int *remaining_burst_time=new int[n]; // true is a process has already arrived
    int *start_time=new int[n]; // keeps track of time when a process resumes for calculation of wait time
    for(int i=1;i<=n;i++){
        completion_record[i]=false;
        arrival_status[i]=false;
        remaining_burst_time[i]=burst_time[i];
        start_time[i]=-1;
    }
        int currently_exec_process=1;
    int previously_exec_process=0;
    int cpu_time=0;
    int count=0; // count of executed processes
    int flag=0;
x:  for(int i=1;i<=n;i++) if(cpu_time>=arrival_time[i]) arrival_status[i]=true;
    int min_remaining_burst_time=infinity;
    for(int i=n;i>=1;i--){
        // finding process with min remaining burst time that is alaready arrived
        if(arrival_status[i]==true && completion_record[i]!=true){
            if(remaining_burst_time[i]<=min_remaining_burst_time){
                min_remaining_burst_time=remaining_burst_time[i];
                currently_exec_process=i;
                flag=1;
            }
        }
    }
    // flag=0 if control does not enter the nested if on line 55
    // which means no process has arrival time equal to initial cpu_time(0)
    if(!flag){
        cpu_time++;
        goto x;
    }
    //check if the first process to be executed has arrival time as initial cpu_time(0)
    // if not,update cpu_time to the arrival time of the first process
    if(count==0 && arrival_time[currently_exec_process]!=0) cpu_time=arrival_time[currently_exec_process]; 
    // check if the process is executing for the first time
    if (burst_time[currently_exec_process]==remaining_burst_time[currently_exec_process]){
        wait_time[currently_exec_process]=cpu_time-arrival_time[currently_exec_process];
    }
    if(currently_exec_process!=previously_exec_process) start_time[currently_exec_process]=cpu_time;
    if(start_time[currently_exec_process]>=0) wait_time[currently_exec_process]+=(cpu_time-burst_time[currently_exec_process]+remaining_burst_time[currently_exec_process]);
    // execute process with min remaining burst time
    cpu_time++;
    remaining_burst_time[currently_exec_process]--;
    if(remaining_burst_time[currently_exec_process]==0){
        completion_record[currently_exec_process]=true;
        completion_time[currently_exec_process]=cpu_time;
        turnaround_time[currently_exec_process]=completion_time[currently_exec_process]-arrival_time[currently_exec_process];
        wait_time[currently_exec_process]=completion_time[currently_exec_process]-burst_time[currently_exec_process]-arrival_time[currently_exec_process];
    }
    previously_exec_process=currently_exec_process;
    count++;
    // looping until all processes are completed
    for(int i=1;i<=n;i++) if(completion_record[i]!=true) goto x;
    // displaying results in tabular form
    cout<<endl<<"**** Scheduling according to SRTF algorithm ****"<<endl;
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
    // final results of SRTF
    int wait_time_sum=0;
    int turnaround_time_sum=0;
    for(int i=1;i<=n;i++){
        wait_time_sum+=wait_time[i];
        turnaround_time_sum+=turnaround_time[i];
    }
    float srtf_avg_wait_and_tat[2]={(float)wait_time_sum/n,(float)turnaround_time_sum/n};
    cout<<endl<<endl;
    cout<<"Average wait time for the processes using SRTF algorithm = "<<srtf_avg_wait_and_tat[0];
    cout<<endl<<"Average turnaround time for the processes using SRTF algorithm= "<<srtf_avg_wait_and_tat[1]<<endl;
}

/* Sample output


Enter number of processes:5

Enter arrival time for process #1 (process_id:0): 3

Enter burst time for process #1 (process_id:0): 1

Enter arrival time for process #2 (process_id:0): 1

Enter burst time for process #2 (process_id:0): 4

Enter arrival time for process #3 (process_id:0): 4

Enter burst time for process #3 (process_id:0): 2

Enter arrival time for process #4 (process_id:0): 0

Enter burst time for process #4 (process_id:0): 6

Enter arrival time for process #5 (process_id:0): 2

Enter burst time for process #5 (process_id:0): 3

**** Scheduling according to SRTF algorithm ****

process_id       arrival_time     burst_time       completion_time  wait_time        turnaround_time  
0                3                1                4                0                1                
0                1                4                6                1                5                
0                4                2                8                2                4                
0                0                6                16               10               16               
0                2                3                11               6                9                

Average wait time for the processes using SRTF algorithm = 3.8
Average turnaround time for the processes using SRTF algorithm= 7

*/