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
    cout << "Enter initial head position: ";
    cin >> head_pos;
    vector<int>::iterator v;
    vector<int>::iterator del;
    int min;
    while(ref_str.size()>0){
        min=*ref_str.begin();
        for(v=ref_str.begin();v!=ref_str.end();v++){
            if(abs(head_pos-*v)<min){
                min=abs(head_pos-*v);
                del=v;
            }
        }
        no_of_tracks+=min;
        cout << "\nRequest #" << *del << " serviced.";
        head_pos = *del;
        ref_str.erase(del);
    }
    cout << "\nTotal travel= " << no_of_tracks;
}