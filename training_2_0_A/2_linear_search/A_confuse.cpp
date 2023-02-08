#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	long long min = b[0];
	long long max = b[0];
	for (int i = 0; i < n; ++i) {
		if (b[i] < min) {
			min = b[i];
		}
		if (b[i] > max) {
			max = b[i];
		}
	}
	cout << max - min << '\n';
	return 0;
}
