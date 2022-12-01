#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main(void)
{
	int n, m, hit = 0, miss = 0, flag = 0, head = 0;
	cout << "Enter number of frames: ";
	cin >> n;
	cin.ignore();
	vector<int> ref_str;
	cout << "Enter the reference string: ";
	while (cin.peek() != '\n')
	{
		int x;
		cin >> x;
		ref_str.push_back(x);
	}
	int *frames = new int[n];
	for (int i = 0; i < n; i++)
		frames[i] = -1;
	vector<int>::iterator v;
	for (v = ref_str.begin(); v != ref_str.end(); v++)
	{
		cout << "Iteration #" << v - ref_str.begin() + 1;
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << frames[j] << " ";
			if (frames[j] == *v)
			{
				hit++;
				flag = 1;
			}
		}
		cout << endl;
		if (flag)
		{
			flag = 0;
			continue;
		}
		miss++;
		frames[head++] = *v;
		if (head == n)
			head = 0;
	}
	cout << "\nHits= " << hit << "\nMiss= " << miss;
	cout << "\nHit ratio= " << (float)hit / (float)ref_str.size();
}

// Enter number of frames: 3
// Enter the reference string: 1 2 3 1 2 3
// Iteration #1 -1  -1  -1
// Iteration #2  1  -1  -1
// Iteration #3  1   2  -1
// Iteration #4  1   2   3
// Iteration #5  1   2   3
// Iteration #6  1   2   3

// Hits= 3
// Miss= 3
// Hit ratio= 0.5