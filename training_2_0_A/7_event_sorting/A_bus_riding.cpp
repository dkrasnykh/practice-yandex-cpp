#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

using namespace std;

void populate(vector<vector<int>>& route, map<int, int>& station, int timestamp) {
	for (int i = 0; i < route.size(); ++i) {
		auto it = station.find(route[i][timestamp % (route[i].size())]);
		if (it==station.end()) {
			station[route[i][timestamp % (route[i].size())]] = i;
		}
	}
}

int main() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> route;
	unordered_set<int> points;

	for (int i = 0; i < k; ) {
		vector<int> point;
		int y=0;
		cin >> y;
		for (int j = 0; j < y; ++j) {
			int t;
			cin >> t;
			point.push_back(t);
			points.insert(t);
		}
		route.push_back(point);
		++i;
	}

	int p;
	cin >> p;
	vector<int> first_station(p);
	vector<vector<int>> plan;
	for (int i = 0; i < p; ++i) {
		cin >> first_station[i];
		int u;
		cin >> u;
		vector<int> iplan;
		for (int j = 0; j < u; ++j) {
			int w;
			cin >> w;
			iplan.push_back(w);
		}
		plan.push_back(iplan);
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < plan.size(); ++i) {
		int c = 0;
		int timestamp = 0;
		int current_station = first_station[i];
		auto iter = points.find(current_station);
		if (iter==points.end()) {
			ans.push_back({ 0, 0 });
			continue;
		}
		while (true) {
			if (c == plan[i].size()) {
				break;
			}
			map<int, int> station;
			populate(route, station, timestamp);

			auto it = station.find(current_station);
			if (it != station.end()) {
				timestamp += plan[i][c];
				++c;
				current_station = route[it->second][timestamp % (route[it->second].size())];
			}
			++timestamp;
		}
		ans.push_back({ timestamp - 1 , current_station});
	}
	for (const auto& e: ans) {
		cout << e.first << ' ' << e.second << '\n';
	}
	return 0;
}
