#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int head_pos = 0, no_of_tracks = 0;
    vector<int> ref_str;
    cout << "Enter the cylinder numbers: ";
    while (cin.peek() != '\n')
    {
        int x;
        cin >> x;
        ref_str.push_back(x);
    }
    sort(ref_str.begin(), ref_str.end());
    cout << "Enter initial head position: ";
    cin >> head_pos;
    int init=head_pos;
    vector<int>::iterator v;
    vector<int>::iterator del;
    // vector<int>::iterator it=find(ref_str.begin(),ref_str.end(),head_pos);
    // if(it - ref_str.begin()>ref_str.size()/2){
    //     //go to right
    // }
    // else{
    //     // go to left
    // }
    vector<int>::iterator initial;
for(v=ref_str.begin();v!=ref_str.end();v++){
        if(*v<head_pos) continue;
        else {initial=v;break;}
}

    for(v=initial;v!=ref_str.end();v++){
        int min=abs(head_pos-*v);
        del=v;
        no_of_tracks+=min;
        cout << "\nRequest #" << *del << " serviced.";
        head_pos = *del;
        if(head_pos==*(ref_str.end()-1)){
            min+=abs(head_pos-*ref_str.begin());
            head_pos=*ref_str.begin();
            v=ref_str.begin()-1;
        }
        //ref_str.erase(del);
        if(v==(initial-1))break;
        
    }
    cout << "\nTotal travel= " << no_of_tracks;
}