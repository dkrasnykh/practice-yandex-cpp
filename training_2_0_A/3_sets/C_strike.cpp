#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool isweekend(int d) {
	return ((d + 1) % 7 == 0 || d % 7 == 0);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> schedule;
	for (int i = 0; i < k; ++i) {
		int a, b;
		cin >> a >> b;
		schedule.push_back({a, b});
	}
	unordered_set<int> days(n);
	for (int i = 0; i < k; ++i) {
		int a = schedule[i].first;
		int b = schedule[i].second;
		for (int j = 0; j < (n-a) / b + 1; ++j) {
			int d = a + j * b;
			if (d <= n && !isweekend(d)) {
				days.insert(d);
			}
		}
	}
	cout << days.size();
	return 0;
}
