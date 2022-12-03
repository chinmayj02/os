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
    while (ref_str.size() > 0)
    {
        int min = *(ref_str.begin());
        for (v = ref_str.begin(); v != ref_str.end(); v++)
        {
            if (abs(head_pos - *v) < min)
            {
                min = abs(head_pos - *v);
                del = v;
            }
        }

        no_of_tracks += min;
        cout << "\nRequest #" << *del << " serviced.";
        head_pos = *del;
        ref_str.erase(del);
    }
    cout << "\nTotal travel= " << no_of_tracks;
}

// Enter the cylinder numbers: 95 180 34 119 11 123 62 64
// Enter initial head position: 50

// Request #62 serviced.
// Request #64 serviced.
// Request #34 serviced.
// Request #11 serviced.
// Request #95 serviced.
// Request #119 serviced.
// Request #123 serviced.
// Request #180 serviced.
// Total travel= 236