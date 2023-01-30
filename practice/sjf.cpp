#include<iostream>
#include<iomanip>

#define INFINITY 9999;

using namespace std;

int main(){
    int n;//number of processes
    cout<<"Enter number of processes: ";
    cin>>n;
    int* arrival_time=new int[n];
    int* burst_time=new int[n];
    int* wait_time=new int[n];
    int* turnaround_time=new int[n];
    int* completion_time=new int[n];
    bool* completion_record=new bool[n];
    int cpu_time=0;

    //taking inputs and initializations
    cout<<"Enetr details of "<<n<<" processes: \n";
    for(int i=0;i<n;i++){
        cout<<"Enetr arrival time of process P"<<i<<": ";
        cin>>arrival_time[i];
        cout<<"Enetr burst time of process P"<<i<<": ";
        cin>>burst_time[i];
        wait_time[i]=0;
        turnaround_time[i]=0;
        completion_time[i]=0;
        completion_record[i]=false;
    }

    //selecting arrived process with shortest burst time 
    int count=0;
x:  int shortest_burst_time=INFINITY;
    int process_tobe_executed=0;
    for(int i=0;i<n;i++){
        if(arrival_time[i]<=cpu_time && !completion_record[i]){
            if(burst_time[i]<shortest_burst_time){
                shortest_burst_time=burst_time[i];
                process_tobe_executed=i;
                count++;
            }
        }
    }

    //executing selected process
    if(count==0){
        cpu_time++;
        goto x;
    }
    completion_record[process_tobe_executed]=true;
    wait_time[process_tobe_executed]=cpu_time-arrival_time[process_tobe_executed];
    cpu_time+=burst_time[process_tobe_executed];
    completion_time[process_tobe_executed]=cpu_time;
    turnaround_time[process_tobe_executed]=wait_time[process_tobe_executed]+burst_time[process_tobe_executed];
    for(int i=0;i<n;i++){
        if(!completion_record[i]) goto x;
    }

    //display table format
    cout<<setw(17)<<"Process"<<setw(17)<<"Arrival time"<<setw(17)<<"Burst time"<<setw(17)<<"Completion time"<<setw(17)<<"Wait time"<<setw(17)<<"Turnaround time"<<endl;
    for(int i=0;i<n;i++){
        cout<<setw(17)<<i<<setw(17)<<arrival_time[i]<<setw(17)<<burst_time[i]<<setw(17)<<completion_time[i]<<setw(17)<<wait_time[i]<<setw(17)<<turnaround_time[i]<<endl;
    }

    // final calculations
    float avg_turnaround_time=0.0f;
    float avg_wait_time=0.0f;
    for(int i=0;i<n;i++){
        avg_turnaround_time+=turnaround_time[i];
        avg_wait_time+=wait_time[i];
    }
    cout<<"\nAverage Wait time= "<<avg_wait_time/n;
    cout<<"\nAverage turnaround time= "<<avg_turnaround_time/n;
}