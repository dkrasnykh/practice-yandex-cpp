#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> event;
	map<int, int> ans;
	for (int i = 1; i <= n; ++i) {
		int s, e;
		cin >> s >> e;
		event.push_back({e, e-s, s, i});
		ans[i] = 0;
	}
	sort(event.begin(), event.end());
	stack<vector<int>> segments;
	for (int i = 0; i < event.size(); ++i) {
		while (segments.size()>0 && event[i][2]<=segments.top()[2]) {
			auto segment = segments.top();
			segments.pop();
			ans[segment[3]] = event[i][3];

		}
		segments.push(event[i]);
	}
	for (const auto& e: ans) {
		cout << e.second << ' ';
	}
	return 0;
}
