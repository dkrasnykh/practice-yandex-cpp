#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	map<int, int> lcnt;
	map<int, int> rcnt;

	vector<tuple<int, int, int>> event;
	for (int i = 0; i < n; ++i) {
		int timestamp;
		cin >> timestamp;
		event.push_back({timestamp, 0, i});
	}
	for (int i = 0; i < m; ++i) {
		lcnt[i] = 0;
		rcnt[i] = 0;
		int s, e;
		cin >> s >> e;
		event.push_back({ s, -1, i });
		event.push_back({ e, 1, i });
	}
	sort(event.begin(), event.end());

	int cnt = 0;

	for (int i = 0; i < event.size(); ++i) {
		int state = get<1>(event[i]);
		int id = get<2>(event[i]);

		if (state == -1) {
			lcnt[id] = cnt;
		}
		else if (state == 1) {
			rcnt[id] = cnt;
		}
		else if (state == 0) {
			++cnt;
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << (rcnt[i]-lcnt[i]) << ' ';
	}
	return 0;
}
