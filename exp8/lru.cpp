#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
int main()
{
    int n, i, hit = 0, miss = 0;
    cout << "\nEnter no of frames: ";
    cin >> n;
    cin.ignore();
    vector<int> frames(n);
    vector<int> fcount(n);
    for (i = 0; i < n; i++)
    {
        frames[i] = -1;
        fcount[i] = 0;
    }
    cout << "\nEnter the Reference String :";
    vector<int> ref_str;
    while (cin.peek() != '\n')
    {
        int x;
        cin >> x;
        ref_str.push_back(x);
    }
    i = 0;
    while (i < ref_str.size())
    {
        int j = 0, flag = 0;
        while (j < n)
        {
            if (ref_str[i] == frames[j])
            {
                flag = 1;
                hit++;
                fcount[j] = i + 1;
            }
            j++;
        }
        j = 0;
        cout << endl
             << "Iteration #" << i + 1 << ": ";
        if (!flag)
        {
            miss++;
            int min = 0, k = 0;
            while (k < n)
            {
                if (fcount[min] > fcount[k])
                    min = k;
                k++;
            }
            frames[min] = ref_str[i];
            fcount[min] = i + 1;
        }
        while (j < n)
        {
            cout << setw(3) << frames[j];
            j++;
        }
        i++;
    }
    cout << "\nHits= " << hit << "\nMiss= " << miss;
    cout << "\nHit ratio= " << (float)hit / (float)ref_str.size()<<endl;
}

// Enter no of frames: 3

// Enter the Reference String :15 2 5 4 2 4 6

// Iteration #1:  15 -1 -1
// Iteration #2:  15  2 -1
// Iteration #3:  15  2  5
// Iteration #4:   4  2  5
// Iteration #5:   4  2  5
// Iteration #6:   4  2  5
// Iteration #7:   4  2  6
// Hits= 2
// Miss= 5
// Hit ratio= 0.285714