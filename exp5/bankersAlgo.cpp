#include<iostream>
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
        for(int j=1;j<=no_of_resources;j++)
            cin>>max_need[i][j];
    int current_need[no_of_processes][no_of_resources];
    cout<<endl<<"Enter current need matrix:\n";
    for(int i=0;i<no_of_processes;i++)
        for(int j=0;j<no_of_resources;j++)
            cin>>current_need[i][j];
    int available[no_of_resources];
    cout<<endl<<"Enter available resources: ";
    for(int i=0;i<no_of_resources;i++)cin>>available[i];
    bool* exec_status=new bool[no_of_processes];
    for(int i=0;i<no_of_processes;i++)exec_status[i]=false;
x:  int i=0;
y:  while(i<no_of_processes){  
        if(exec_status[i]){
            i++;
            continue;
        }
        for(int j=0;j<no_of_resources;j++){
            if(current_need[i][j]>available[j]){
                i++;
                goto y;
            }
        }
        exec_status[i]=true;
        for(int j=0;j<no_of_resources;j++) available[j]+=allocation[i][j];
        cout<<endl<<"Process "<<i+1<<"  executed\n";
        i++;
    }
    for(int j=0;j<no_of_processes;j++) if(!exec_status[j])goto x;
}

/*

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

Enter current need matrix:
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

*/