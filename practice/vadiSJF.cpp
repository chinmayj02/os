#include<iostream>
using namespace std;

struct PCB
{
    int pid,at,bt,ct,tat,wt;
    bool status,arrived;
};

PCB minproc(PCB processes[],int n,int cpu)
{
    
    struct PCB *temp_array=new PCB[n];
    int temp_arry_size=0;
    //Create a temporary array & store the processes which have arrived
    for(int i=0;i<n;i++)
    {
        cout<<endl<<processes[i].pid<<'\t'<<processes[i].at<<'\t'<<cpu<<'\t'<<processes[i].arrived<<'\t'<<processes[i].status;

        if((processes[i].at<=cpu)&&(processes[i].arrived==false)&&(processes[i].status==false))
        {   
            cout<<"condition";
            processes[i].arrived=true;
            temp_array[i]=processes[i];
            temp_arry_size++;
        }
    }
    
    struct PCB temp;
    //Find out a process with minimum burst time
    for(int i=0;i<temp_arry_size;i++)
    {
        for(int j=i+1;j<temp_arry_size;j++)
        {
            if(temp_array[j].bt<temp_array[i].bt)
            {
                temp=temp_array[j];
                temp_array[j]=temp_array[i];
                temp_array[i]=temp;
            }
            else if(temp_array[j].bt==temp_array[i].bt)
            {
                if(temp_array[j].at<temp_array[i].at)
                {
                    temp=temp_array[j];
                    temp_array[j]=temp_array[i];
                    temp_array[i]=temp;
                }
                else if(temp_array[j].at==temp_array[i].at)
                {
                    if(temp_array[j].pid<temp_array[i].pid)
                    {
                        temp=temp_array[j];
                        temp_array[j]=temp_array[i];
                        temp_array[i]=temp;
                    }
                }
            }
        }
    }
    //Now return the temp_array[0] which has the process with min BT
    return(temp_array[0]);
}

int main()
{
    int n,sum_bt=0;
    cout<<endl<<"SJF SCHEDULING ALGORITHM";

    cout<<endl<<"Enter the number of processes:";
    cin>>n;
    struct PCB *processes=new PCB[n];

    //Reading arrival time & burst of n processes.
    cout<<endl<<"Enter the arrival time | Burst time of:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>processes[i].at;
        cin>>processes[i].bt;
        processes[i].pid=i+1;
        processes[i].status=false;
        processes[i].arrived=false;
        sum_bt+=processes[i].bt;
    }

    //Sort the processes as per their arrival time
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(processes[j].at<processes[i].at)
            {
                struct PCB temp=processes[j];
                processes[j]=processes[i];
                processes[i]=temp;
            }
            else if(processes[j].at==processes[i].at)
            {
                if(processes[j].pid<processes[i].pid)
                {
                    struct PCB temp=processes[j];
                    processes[j]=processes[i];
                    processes[i]=temp;
                }
            }
        }
    }

    //SJF ALGORITHM
    int cputime=0;
    float sum_wt,sum_tat;
    sum_wt=sum_tat=0;
    struct PCB TEMP;
    TEMP.arrived=false;

    
    for(int i=0;cputime<sum_bt;)
    {   
        TEMP=minproc(processes,n,cputime);
        // cout<<TEMP.pid;
        if(TEMP.arrived!=false)
        {
            for(int k=0;k<n;k++)
            {
                if(processes[k].pid==TEMP.pid)
                {  
                    processes[k].status=true;
                    cputime+=TEMP.bt;
                    processes[k].ct=cputime;
                    processes[k].tat=processes[k].ct-processes[k].at;
                    processes[k].wt=processes[k].tat-processes[k].bt;
                    sum_wt=sum_wt+processes[k].wt;
                    sum_tat=sum_tat+processes[k].tat;
                }
            }
            i++;
        }
        else
            
        cputime++;
    }
    float awt,atat;
    awt=sum_wt/n;
    atat=sum_tat/n; 

    //Displaying the final table
     cout<<endl<<"PID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT";
     for(int i=0;i<n;i++)
     {
        cout<<endl<<"P["<<processes[i].pid<<"]"<<"\t\t"<<processes[i].at<<"\t\t"<<processes[i].bt<<"\t\t"<<processes[i].ct<<"\t\t"<<processes[i].tat<<"\t\t"<<processes[i].wt;
     }
     cout<<endl<<"\n";
     cout<<"The average waiting time = "<<awt<<"\n";
     cout<<"The average turn around time = "<<atat;
     cout<<endl<<"\n";
    
}