#include<iostream>
#include<iomanip>
using namespace std;

#define INFINITY 9999;

int main(){
    int n; //number of processes
    cout<<"Enter number of processes: ";
    cin>>n;
    int* arrival_time=new int[n]; // arrival times of n processes
    int* burst_time=new int[n]; // burst times of n processes
    bool* completed=new bool[n]; // completion status of n processes
    int* wait_time=new int[n]; // wait times of n processes
    int* turnaround_time=new int[n]; // turnaround times of n processes
    int* completion_time=new int[n]; // completion times of n processes
    int cpu_time=0; // initial cpu time

    //taking inputs for n processes: 
    cout<<"Enter arrival times and burst times of the "<<n<<" processes:\n";
    for(int i=0;i<n;i++){
        cout<<"Arrival time of process P"<<i<<": ";
        cin>>arrival_time[i];
        cout<<"Burst time of process P"<<i<<": ";
        cin>>burst_time[i];
        completed[i]=false;
        wait_time[i]=0;
        turnaround_time[i]=0;
    }

    //running the first arrived process:
    int count=0;
x:  int min_arrival_time=INFINITY;
    int process_tobe_executed=0;
    for(int i=0;i<n;i++){
        if(arrival_time[i]<min_arrival_time && !completed[i]){
            min_arrival_time=arrival_time[i];
            if(arrival_time[i]<=cpu_time){
                process_tobe_executed=i;
                count++;
            }
        }
    }
    if(count==0){
        cpu_time+=min_arrival_time;
        goto x;
    }
    completed[process_tobe_executed]=true;
    wait_time[process_tobe_executed]=cpu_time-arrival_time[process_tobe_executed];
    cpu_time+=burst_time[process_tobe_executed];
    completion_time[process_tobe_executed]=cpu_time;
    turnaround_time[process_tobe_executed]=wait_time[process_tobe_executed]+burst_time[process_tobe_executed];

    //check if all processes are executed:
    for(int i=0;i<n;i++){
        if(!completed[i]) goto x;
    }

    //display table:
    cout<<setw(8)<<"|Process"<<setw(13)<<"|Arrival time"<<setw(11)<<"|Burst time"<<setw(16)<<"|Completion time"<<setw(10)<<"|Wait time"<<setw(17)<<"|turnaround time|"<<endl;
    for(int i=0;i<n;i++){
        cout<<"|"<<setw(7)<<i<<"|"<<setw(12)<<arrival_time[i]<<"|"<<setw(10)<<burst_time[i]<<"|"<<setw(15)<<completion_time[i]<<"|"<<setw(9)<<wait_time[i]<<"|"<<setw(15)<<turnaround_time[i]<<"|"<<endl;
    }

    //further calculations:
    float avg_turnaround_time=0.0f;
    float avg_wait_time=0.0f;
    for(int i=0;i<n;i++){
        avg_turnaround_time+=turnaround_time[i];
        avg_wait_time+=wait_time[i];
    }
    avg_turnaround_time/=n;
    avg_wait_time/=n;
    cout<<"\n Average tat= "<<avg_turnaround_time;
    cout<<"\n Average wait time= "<<avg_wait_time;
}