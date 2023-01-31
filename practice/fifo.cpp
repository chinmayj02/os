#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main(){
    int n,hits=0,miss=0,flag=0,head=0;
    cout<<"Enetr numbe rof frames: ";
    cin>>n;
    cin.ignore();
    int* frames=new int[n];
    for(int i=0;i<n;i++) frames[i]=-1;
    cout<<"Enetr reference string: ";
    vector<int> ref_str;
    vector<int>::iterator v;
    while(cin.peek()!='\n'){
        int x;
        cin>>x;
        ref_str.push_back(x);
    }
    for(v=ref_str.begin();v!=ref_str.end();v++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<frames[j]<<" ";
            if(frames[j]==*v){
                hits++;
                flag=1;
            }
        }
        cout<<endl;
        if(flag){
            continue;
            flag=0;
        }
        miss++;
        frames[head++]=*v;
        if(head==n) head=0;
    }
    cout << "\nHits= " << hits << "\nMiss= " << miss;
	cout << "\nHit ratio= " << (float)hits / (float)ref_str.size();

}