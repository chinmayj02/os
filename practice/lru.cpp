#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;

int main(){
    int n,hits=0,miss=0,flag=0;
    cout<<"Enetr numbe rof frames: ";
    cin>>n;
    cin.ignore();
    int* frames=new int[n];
    int* fcount=new int[n];
    for(int i=0;i<n;i++){ 
        frames[i]=-1;
        fcount[i]=0;
    }
    cout<<"Enetr reference string: ";
    vector<int> ref_str;
    // vector<int>::iterator v;
    int v=0;
    while(cin.peek()!='\n'){
        int x;
        cin>>x;
        ref_str.push_back(x);
    }
    for(v=0;v<=ref_str.size();v++){
        for(int j=0;j<n;j++){
            cout<<setw(3)<<frames[j]<<" ";
            if(frames[j]==ref_str[v]){
                hits++;
                fcount[j]=v+1;
                flag=1;
            }
        }
        cout<<endl;
        if(flag){
            flag=0;
            continue;
        }
        miss++;
        int min=0;
        for(int i=1;i<n;i++){
            if(fcount[i]<fcount[min]) min=i;
        }
        frames[min]=ref_str[v];
        fcount[min]=v+1;
    }
    cout << "\nHits= " << hits << "\nMiss= " << --miss;
    cout << "\nHit ratio= " << (float)hits / (float)ref_str.size()<<endl;
}