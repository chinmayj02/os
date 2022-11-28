#include<iostream>

using namespace std;

int main(void) {
	int n,m,hit=0,miss=0;
	cout << "Enter number of frames: ";
	cin >> n;
	cout << "Enetr the size of reference string: ";
	cin >> m;
	int* ref_str = new int[m];
	cout << "Enetr " << m << " page numbers of reference string: ";
	for (int i = 0; i < m; i++) cin >> ref_str[i];
	int* queue = new int[n];
	for (int i = 0; i < n; i++) queue[i] = -1;
	for (int i = 0; i < m; i++) {
			if (queue[i] == ref_str[i]) {
				hit++;
			}
			else {
				miss++;
				queue[i] = ref_str[i];
			}
		// printing queue after every iteration
		for (int j = 0; j < n; j++)cout << queue[j] << " ";
		cout << endl;
	}
	cout << "\nHits= " << hit << "\nMiss= " << miss;
	cout << "\nHit ratio= " << hit / m;
}