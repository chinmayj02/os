#include<iostream>
using namespace std;
int main()
{
    // int AT[20],BT[20],temp[20];
    // int WT[20],TAT[20],CT[20];
    int i,j,small,cnt=0,time,n;
    double avg=0,tt=0,end;

    cout<<endl<<"Enter the number of processes:";
    cin>>n;
    int *AT=new int[n+3];
    int *BT=new int[n+3];
    int *temp=new int[n+3];
    int *WT=new int[n+3];
    int *TAT=new int[n+3];
    int *CT=new int[n+3];

    cout<<endl<<"Enter the Arrival time | Burst time of :\n";
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>AT[i];
        cin>>BT[i];
        temp[i]=BT[i];
    }

    BT[19]=9999;
    for(time=0;cnt!=n;time++)
    {   
        small=19;
        for(i=0;i<n;i++)
        {   
            if(AT[i]<=time && BT[i]<BT[small] &&BT[i]>0)
            { 
               
                small=i;
               
            }
        }
        BT[small]--;
        if(BT[small]==0)
        {
            cnt++;
            end=time+1;
            CT[small]=end;
            WT[small]=end-AT[small]-temp[small];
            TAT[small]=end-AT[small];
        }
    }

    cout<<endl<<"\nPID\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT";
    for(i=0;i<n;i++)
    {
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<AT[i]<<"\t\t"<<temp[i]<<"\t\t"<<CT[i]<<"\t\t"<<TAT[i]<<"\t\t"<<WT[i];
        avg=avg+WT[i];
        tt=tt+TAT[i];
    }
    cout<<endl<<"Average waiting time:"<<avg/n;
    cout<<endl<<"Average TAT time:"<<tt/n;
}