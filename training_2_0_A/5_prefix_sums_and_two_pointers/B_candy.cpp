#include <iostream>
#include <vector>

using namespace std;

/*
ML 19 тест
*/

int main() {
	int k;
	cin >> k;
	vector<long long> heap;
	for (int i = 0; i < k; ++i) {
		int a, n;
		cin >> a >> n;
		for (int j = 0; j < n; ++j) {
			heap.push_back(a);
		}
	}
	int l = 0;
	int r = heap.size() - 1;
	while (l < r-1) {
		long long shifted = min(heap[l], heap[r]);
		heap[l] -= shifted;
		heap[r] -= shifted;
		heap[l + 1] += shifted;
		heap[r - 1] += shifted;
		if (heap[l]==0) {
			++l;
		}
		if (heap[r]==0) {
			--r;
		}
	}
	if (l==r) {
		cout << 1 << '\n' << heap[l] << '\n';
	} else if (l==r-1) {
		cout << 2 << '\n' << heap[l] << ' ' << heap[r] << '\n';
	} else if (heap[l]==0 && heap[r]==0) {
		cout << 1 << '\n' << heap[r - 1] << '\n';
	} else if (heap[l]==0) {
		cout << 2 << '\n' << heap[r-1]<<' '<<heap[r]<<'\n';
	} else if (heap[r]==0) {
		cout << 2 << '\n' << heap[l] << ' ' << heap[l + 1] << '\n';
	}
	return 0;
}
