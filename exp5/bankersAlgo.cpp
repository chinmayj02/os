#include<iostream>
#include<vector>
using namespace std;

int main(){
    int no_of_processes,no_of_resources;
    cout<<"Enter number of processes: ";
    cin>>no_of_processes;
    cout<<endl<<"Enter number of resources: ";
    cin>>no_of_resources;
    int allocation[no_of_processes][no_of_resources];
    cout<<endl<<"Enter allocation matrix:\n";
    for(int i=0;i<no_of_processes;i++)
        for(int j=0;j<no_of_resources;j++)
            cin>>allocation[i][j];
    int max_need[no_of_processes][no_of_resources];
    cout<<endl<<"Enter maximum need matrix:\n";
    for(int i=0;i<no_of_processes;i++)
        for(int j=0;j<no_of_resources;j++)
            cin>>max_need[i][j];
    int current_need[no_of_processes][no_of_resources];
    cout<<endl<<"The current need matrix:\n";
    for(int i=0;i<no_of_processes;i++){
        cout<<endl;
        for(int j=0;j<no_of_resources;j++){
            current_need[i][j]=max_need[i][j]-allocation[i][j];
            // cout<<"max need= "<<max_need[i][j]<<" allocation= "<<allocation[i][j];
            cout<<current_need[i][j]<<" ";
        }
    }

    //  cout<<endl<<"The allocation matrix:\n";
    // for(int i=0;i<no_of_processes;i++){
    //     cout<<endl;
    //     for(int j=0;j<no_of_resources;j++){
    //         // current_need[i][j]=max_need[i][j]-allocation[i][j];
    //         // cout<<"max need= "<<max_need[i][j]<<" allocation= "<<allocation[i][j];
    //         cout<<allocation[i][j]<<" ";
    //     }
    // }

    // cout<<endl<<"The need matrix:\n";
    // for(int i=0;i<no_of_processes;i++){
    //     cout<<endl;
    //     for(int j=0;j<no_of_resources;j++){
    //         // current_need[i][j]=max_need[i][j]-allocation[i][j];
    //         // cout<<"max need= "<<max_need[i][j]<<" allocation= "<<allocation[i][j];
    //         cout<<max_need[i][j]<<" ";
    //     }
    // }


    int available[no_of_resources];
    cout<<endl<<"Enter available resources: ";
    for(int i=0;i<no_of_resources;i++)cin>>available[i];
    bool* exec_status=new bool[no_of_processes];
    for(int i=0;i<no_of_processes;i++)exec_status[i]=false; //true if process finished execution
    // safe sequence vector
    vector<int> sequence;
    // starting from first process 
    int count=1;
    int size=0;
x:  int i=0;
y:  while(i<no_of_processes){  
        // check if process has finished execution
        // if yes goto next process
        if(exec_status[i]){
            i++;
            continue;
        }
        // check if resources needed are less than or equal to available
        // if not, skip the process and goto next
        for(int j=0;j<no_of_resources;j++){
            if(current_need[i][j]>available[j]){
                i++;
                goto y;
            }
        }
        // if resources available,execute the process
        exec_status[i]=true;
        sequence.push_back(i+1);
        // release the allocated resources and update available vector
        for(int j=0;j<no_of_resources;j++) available[j]+=allocation[i][j];
        cout<<endl<<"Process "<<i+1<<"  executed\n";
        i++;
    }
    // keeping track of iterations
    count++;
    if(sequence.size()==size){
        cout<<endl<<"System is in unsafe state\n";
        return 0;
    }
    size=sequence.size();
    // check if all processes have finished execution
    for(int j=0;j<no_of_processes;j++) if(!exec_status[j])goto x;
    cout<<endl<<"System is in safe state and the safe sequence is: ";
    for(int k=0;k<no_of_processes;k++) cout<<sequence[k]<<" "; 
    cout<<endl;   
}

/*  OUTPUT

Enter number of processes: 5

Enter number of resources: 4

Enter allocation matrix:
0 1 1 0
1 2 3 1
1 3 6 5
0 6 3 2
0 0 1 4

Enter maximum need matrix:
0 2 1 0
1 6 5 2
2 3 6 6
0 6 5 2
0 6 5 6

The current need matrix:

0 1 0 0 
0 4 2 1 
1 0 0 1 
0 0 2 0 
0 6 4 2 
Enter available resources: 1 5 2 0

Process 1  executed

Process 4  executed

Process 5  executed

Process 2  executed

Process 3  executed

System is in safe state and the safe sequence is: 1 4 5 2 3

*/