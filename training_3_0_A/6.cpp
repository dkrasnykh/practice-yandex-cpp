//https://contest.yandex.ru/contest/45469/problems/6/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isintersect(pair<int, int> segment1, pair<int, int> segment2) {
	int a1 = segment1.first;
	int b1 = segment1.second;
	int a2 = segment2.first;
	int b2 = segment2.second;
	return (a1 >= a2 && a1 <= b2 || b1 >= a2 && b1 <= b2 || a2 >= a1 && a2 <= b1 || b2 >= a1 && b2 <= b1);
}

int main() {
	int m, n;
	cin >> m >> n;
	vector<pair<int, int>> segment;
	vector<bool> used(n, true);
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		segment.push_back({ a, b });
	}
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j >= 0; --j) {
			if (isintersect(segment[i], segment[j])) {
				used[j] = false;
			}
		}
	}
	int ans = 0;
	for (const auto& e: used) {
		ans += e;
	}
	cout << ans << '\n';
	return 0;
}

