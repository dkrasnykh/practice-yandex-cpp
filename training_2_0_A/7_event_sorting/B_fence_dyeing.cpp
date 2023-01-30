#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int min_value = 1000000100;
	bool less = true;
	int amount = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		min_value = min(min_value, a[i]);
		if (less) {
			amount += a[i];
		}
		if (amount > k && less) {
			less = false;
		}
	}
	if (less) {
		cout << min_value;
		return 0;
	}
	if (n == 1) {
		cout << k;
		return 0;
	}
	sort(a.begin(), a.end());

	int current = k;
	int ans = 0;
	int size = static_cast<int>(a.size());
	int occupied = 0;

	for (int i = 0; i < size - 1; ++i) {
		if (occupied + ans >= a[i]) {
			occupied += ans;
			current -= ans;
		}
		else {
			current -= (a[i] - occupied);
			occupied += (a[i] - occupied);
			int d = (size - i - 1) == 0 ? 1 : (size - i - 1);
			ans = max(0, current / d);
		}
		if (ans == 0) {
			break;
		}
	}

	cout << min(ans, a[0]);
	return 0;
}
