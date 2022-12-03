#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int head_pos=0,no_of_tracks=0;
	vector<int> ref_str;
	cout << "Enter the cylinder numbers: ";
	while (cin.peek() != '\n')
	{
		int x;
		cin >> x;
		ref_str.push_back(x);
	}
	cout<<"Enter initial head position: ";
    cin>>head_pos;
	vector<int>::iterator v;
	for (v = ref_str.begin(); v != ref_str.end(); v++)
	{
        no_of_tracks+=abs(*v-head_pos);
        cout<<"\nRequest #"<<*v<<" serviced.";
        head_pos=*v;
    }
    cout<<"\nTotal travel= "<<no_of_tracks;
}

// Enter the cylinder numbers: 4 8 3 10 6 2
// Enter initial head position: 10

//  Request #4 serviced.
//  Request #8 serviced.
//  Request #3 serviced.
//  Request #10 serviced.
//  Request #6 serviced.
//  Request #2 serviced.
// Total travel= 30