// OS Expt3- SRTF and RR cpu scheduling algorithms
// date- 17/09/2022
// 2014006- Chinmay Joshi

#include<iostream>
#include<iomanip>

#define infinity 9999;

using namespace std;

int main() {
    int n; //number of processes
    cout << "Enter number of processes:";
    cin >> n;
    int* process_id = new int[n];
    int* arrival_time = new int[n];
    int* burst_time = new int[n];
    int* wait_time = new int[n];
    int* completion_time = new int[n];
    int* turnaround_time = new int[n];
    int* priority = new int[n];
    // taking different required inputs
    for (int i = 1; i <= n; i++) {
        cout<<endl<<"Enter process id for process #"<<i<<" : ";
        cin>>process_id[i];
        cout << endl << "Enter arrival time for process #" << i << " (process_id:" << process_id[i] << "): ";
        cin >> arrival_time[i];
        cout << endl << "Enter burst time for process #" << i << " (process_id:" << process_id[i] << "): ";
        cin >> burst_time[i];
        cout<<endl<<"Enter priority for process #"<<i<<" (process_id:"<<process_id[i]<<")[lower number higher priority]: ";
        cin>>priority[i];
    }

    // SRTF
    bool* completion_record = new bool[n]; //true if a process has completed execution
    bool* arrival_status = new bool[n]; // true is a process has already arrived
    int* remaining_burst_time = new int[n]; 
    int* start_time = new int[n]; // keeps track of time when a process resumes for calculation of wait time
    for (int i = 1; i <= n; i++) {
        completion_record[i] = false;
        arrival_status[i] = false;
        remaining_burst_time[i] = burst_time[i];
        start_time[i] = -1;
    }
    int currently_exec_process = 1;
    int previously_exec_process = 0;
    int cpu_time = 0;
    int count = 0; // count of executed processes
    int flag = 0;
    int process_with_min_remaining_burst_time = 0;
x:  for (int i = 1; i <= n; i++) if (cpu_time >= arrival_time[i]) arrival_status[i] = true;
    int min_remaining_burst_time = infinity;
    for (int i = n; i >= 1; i--) {
        // finding process with min remaining burst time that is alaready arrived
        if (arrival_status[i] == true && completion_record[i] != true) {
            if (remaining_burst_time[i] < min_remaining_burst_time) {
                min_remaining_burst_time = remaining_burst_time[i];
                currently_exec_process = i;
                process_with_min_remaining_burst_time = i;
                flag = 1;
            }
            else if (remaining_burst_time[i] == min_remaining_burst_time) {
                if (priority[i] < priority[process_with_min_remaining_burst_time]) {
                    min_remaining_burst_time = remaining_burst_time[i];
                    currently_exec_process = i;
                    process_with_min_remaining_burst_time = i;
                    flag = 1;
                }
            }
        }
    }
    // flag=0 if control does not enter the nested if on line 55
    // which means no process has arrival time equal to initial cpu_time(0)
    if (!flag) {
        cpu_time++;
        goto x;
    }
    //check if the first process to be executed has arrival time as initial cpu_time(0)
    // if not,update cpu_time to the arrival time of the first process
    if (count == 0 && arrival_time[currently_exec_process] != 0) cpu_time = arrival_time[currently_exec_process];
    // check if the process is executing for the first time
    if (burst_time[currently_exec_process] == remaining_burst_time[currently_exec_process]) {
        wait_time[currently_exec_process] = cpu_time - arrival_time[currently_exec_process];
    }
    if (currently_exec_process != previously_exec_process) start_time[currently_exec_process] = cpu_time;
    if (start_time[currently_exec_process] >= 0) wait_time[currently_exec_process] += (cpu_time - burst_time[currently_exec_process] + remaining_burst_time[currently_exec_process]);
    // execute process with min remaining burst time
    cpu_time++;
    remaining_burst_time[currently_exec_process]--;
    if (remaining_burst_time[currently_exec_process] == 0) {
        completion_record[currently_exec_process] = true;
        completion_time[currently_exec_process] = cpu_time;
        turnaround_time[currently_exec_process] = completion_time[currently_exec_process] - arrival_time[currently_exec_process];
        wait_time[currently_exec_process] = completion_time[currently_exec_process] - burst_time[currently_exec_process] - arrival_time[currently_exec_process];
    }
    previously_exec_process = currently_exec_process;
    flag=0;
    count++;
    // looping until all processes are completed
    for (int i = 1; i <= n; i++) if (completion_record[i] != true) goto x;
    // displaying results in tabular form
    cout << endl << "**** Scheduling according to SRTF algorithm ****" << endl;
    const char space = ' ';
    const int width = 17;
    cout << endl << left << setw(width) << setfill(space) << "process_id";
    cout << left << setw(width) << setfill(space) << "arrival_time";
    cout << left << setw(width) << setfill(space) << "burst_time";
    cout << left << setw(width) << setfill(space) << "priority";
    cout << left << setw(width) << setfill(space) << "completion_time";
    cout << left << setw(width) << setfill(space) << "wait_time";
    cout << left << setw(width) << setfill(space) << "turnaround_time";
    for (int i = 1; i <= n; i++) {
        cout << endl;
        cout << left << setw(width) << setfill(space) << process_id[i];
        cout << left << setw(width) << setfill(space) << arrival_time[i];
        cout << left << setw(width) << setfill(space) << burst_time[i];
        cout << left << setw(width) << setfill(space) << priority[i];
        cout << left << setw(width) << setfill(space) << completion_time[i];
        cout << left << setw(width) << setfill(space) << wait_time[i];
        cout << left << setw(width) << setfill(space) << turnaround_time[i];
    }
    // final results of SRTF
    int wait_time_sum = 0;
    int turnaround_time_sum = 0;
    for (int i = 1; i <= n; i++) {
        wait_time_sum += wait_time[i];
        turnaround_time_sum += turnaround_time[i];
    }
    float srtf_avg_wait_and_tat[2] = { (float)wait_time_sum / n,(float)turnaround_time_sum / n };
    cout << endl << endl;
    cout << "Average wait time for the processes using SRTF algorithm = " << srtf_avg_wait_and_tat[0];
    cout << endl << "Average turnaround time for the processes using SRTF algorithm= " << srtf_avg_wait_and_tat[1] << endl;

    // RR
    int time_quantum;
    cout<<"\nFor Round Robin algorithm, enter time quantum: ";
    cin>>time_quantum;
    completion_record = new bool[n]; //true if a process has completed execution
    arrival_status = new bool[n]; // true is a process has already arrived
    remaining_burst_time = new int[n]; 
    start_time = new int[n]; // keeps track of time when a process resumes for calculation of wait time
    for (int i = 1; i <= n; i++) {
        completion_record[i] = false;
        arrival_status[i] = false;
        remaining_burst_time[i] = burst_time[i];
        start_time[i] = -1;
    }
    currently_exec_process = 1;
    previously_exec_process = 0;
    cpu_time = 0;
    count = 0; // count of executed processes
    flag = 0;
x1:  for (int i = 1; i <= n; i++) if (cpu_time >= arrival_time[i]) arrival_status[i] = true;
    int highest_priority=infinity;
    for (int i = n; i >= 1; i--) {
        // finding process with that is already arrived and has high priority
        if (arrival_status[i] == true && completion_record[i] != true) {
            if (priority[i] <= highest_priority) {
                highest_priority = priority[i];
                currently_exec_process = i;
                flag = 1;
            }
        }
    }
    // flag=0 if control does not enter the nested if on line 55
    // which means no process has arrival time equal to initial cpu_time(0)
    if (!flag) {
        cpu_time++;
        goto x1;
    }
    //check if the first process to be executed has arrival time as initial cpu_time(0)
    // if not,update cpu_time to the arrival time of the first process
    if (count == 0 && arrival_time[currently_exec_process] != 0) cpu_time = arrival_time[currently_exec_process];
    // check if the process is executing for the first time
    if (burst_time[currently_exec_process] == remaining_burst_time[currently_exec_process]) wait_time[currently_exec_process] = cpu_time - arrival_time[currently_exec_process];
    if (currently_exec_process != previously_exec_process) start_time[currently_exec_process] = cpu_time;
    if (start_time[currently_exec_process] >= 0) wait_time[currently_exec_process] += (cpu_time - burst_time[currently_exec_process] + remaining_burst_time[currently_exec_process]);
    if(remaining_burst_time[currently_exec_process]>=time_quantum){
        cpu_time+=time_quantum;
        remaining_burst_time[currently_exec_process]-=time_quantum;
    }
    else if(remaining_burst_time[currently_exec_process]<time_quantum){
        cpu_time+=remaining_burst_time[currently_exec_process];
        remaining_burst_time[currently_exec_process]=0;
    }
    if(remaining_burst_time[currently_exec_process]==0) 
    {
        completion_record[currently_exec_process]=true;
        completion_time[currently_exec_process]=cpu_time;
        turnaround_time[currently_exec_process] = completion_time[currently_exec_process] - arrival_time[currently_exec_process];
        wait_time[currently_exec_process] = completion_time[currently_exec_process] - burst_time[currently_exec_process] - arrival_time[currently_exec_process];
    }
    count++;
    flag=0;
    previously_exec_process = currently_exec_process;
    // looping until all processes are completed
    for (int i = 1; i <= n; i++) if (completion_record[i] != true) goto x1;
    // displaying results in tabular form
    cout << endl << "**** Scheduling according to RR algorithm ****" << endl;
    cout<<endl<<"Time Quantum = "<<time_quantum<<endl;
    cout << endl << left << setw(width) << setfill(space) << "process_id";
    cout << left << setw(width) << setfill(space) << "arrival_time";
    cout << left << setw(width) << setfill(space) << "burst_time";
    cout << left << setw(width) << setfill(space) << "priority";
    cout << left << setw(width) << setfill(space) << "completion_time";
    cout << left << setw(width) << setfill(space) << "wait_time";
    cout << left << setw(width) << setfill(space) << "turnaround_time";
    for (int i = 1; i <= n; i++) {
        cout << endl;
        cout << left << setw(width) << setfill(space) << process_id[i];
        cout << left << setw(width) << setfill(space) << arrival_time[i];
        cout << left << setw(width) << setfill(space) << burst_time[i];
        cout << left << setw(width) << setfill(space) << priority[i];
        cout << left << setw(width) << setfill(space) << completion_time[i];
        cout << left << setw(width) << setfill(space) << wait_time[i];
        cout << left << setw(width) << setfill(space) << turnaround_time[i];
    }
    // final results of RR
    wait_time_sum = 0;
    turnaround_time_sum = 0;
    for (int i = 1; i <= n; i++) {
        wait_time_sum += wait_time[i];
        turnaround_time_sum += turnaround_time[i];
    }
    float rr_avg_wait_and_tat[2] = { (float)wait_time_sum / n,(float)turnaround_time_sum / n };
    cout << endl << endl;
    cout << "Average wait time for the processes using RR algorithm = " << rr_avg_wait_and_tat[0];
    cout << endl << "Average turnaround time for the processes using RR algorithm= " << rr_avg_wait_and_tat[1] << endl;
    // final comparison
    cout<<endl<<"**** Comparison between SRTF and RR ****"<<endl;
    cout<<endl<<left<<setw(width)<<setfill(space)<<"algorithm";
    cout<<left<<setw(width)<<setfill(space)<<"avg_wait_time";
    cout<<left<<setw(width)<<setfill(space)<<"avg_turnaround_time";
    cout<<endl;
    cout<<left<<setw(width)<<setfill(space)<<"SRTF";
    cout<<left<<setw(width)<<setfill(space)<<srtf_avg_wait_and_tat[0];
    cout<<left<<setw(width)<<setfill(space)<<srtf_avg_wait_and_tat[1];
    cout<<endl;
    cout<<left<<setw(width)<<setfill(space)<<"RR";
    cout<<left<<setw(width)<<setfill(space)<<rr_avg_wait_and_tat[0];
    cout<<left<<setw(width)<<setfill(space)<<rr_avg_wait_and_tat[1];
    cout<<endl<<endl;
}
/* Sample output

Enter number of processes:5

Enter process id for process #1 : 1001

Enter arrival time for process #1 (process_id:1001): 1

Enter burst time for process #1 (process_id:1001): 8

Enter priority for process #1 (process_id:1001)[lower number higher priority]: 4

Enter process id for process #2 : 1002

Enter arrival time for process #2 (process_id:1002): 2

Enter burst time for process #2 (process_id:1002): 6

Enter priority for process #2 (process_id:1002)[lower number higher priority]: 1

Enter process id for process #3 : 1003

Enter arrival time for process #3 (process_id:1003): 5

Enter burst time for process #3 (process_id:1003): 1

Enter priority for process #3 (process_id:1003)[lower number higher priority]: 2

Enter process id for process #4 : 1004

Enter arrival time for process #4 (process_id:1004): 4

Enter burst time for process #4 (process_id:1004): 9

Enter priority for process #4 (process_id:1004)[lower number higher priority]: 2

Enter process id for process #5 : 1005

Enter arrival time for process #5 (process_id:1005): 3

Enter burst time for process #5 (process_id:1005): 3

Enter priority for process #5 (process_id:1005)[lower number higher priority]: 3

**** Scheduling according to SRTF algorithm ****

process_id       arrival_time     burst_time       priority         completion_time  wait_time        turnaround_time  
1001             1                8                4                19               10               18               
1002             2                6                1                12               4                10               
1003             5                1                2                6                0                1                
1004             4                9                2                28               15               24               
1005             3                3                3                7                1                4                

Average wait time for the processes using SRTF algorithm = 6
Average turnaround time for the processes using SRTF algorithm= 11.4

For Round Robin algorithm, enter time quantunm: 2

**** Scheduling according to RR algorithm ****

Time Quantum = 2

process_id       arrival_time     burst_time       priority         completion_time  wait_time        turnaround_time  
1001             1                8                4                28               19               27               
1002             2                6                1                9                1                7                
1003             5                1                2                10               4                5                
1004             4                9                2                19               6                15               
1005             3                3                3                22               16               19               

Average wait time for the processes using RR algorithm = 9.2
Average turnaround time for the processes using RR algorithm= 14.6

**** Comparison between SRTF and RR ****

algorithm        avg_wait_time    avg_turnaround_time
SRTF             6                11.4             
RR               9.2              14.6 
*/
