#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <map>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> event;
	map<int, int> start;
	for (int i = 1; i <= n; ++i) {
		int s, e;
		cin >> s >> e;
		event.push_back({s, 1, i});
		event.push_back({e, -1, i});

		start[i] = s;
	}
	sort(event.begin(), event.end());

	int min_value = 2000000200;
	int min_id1 = -1;
	int min_id2 = -1;
	auto cmp = [](pair<int, int> a, pair<int, int> b) { return ((a.first==b.first)?(a.second<b.second):(a.first > b.first)); };
	set<pair<int, int>, decltype(cmp)> s;

	for (const auto& e : event) {
		int time = get<0>(e);
		int state = get<1>(e);
		int id = get<2>(e);

		if (state==1) {
			s.insert({time, id});
		}
		else if (state==-1) {
			auto it = s.begin();
			if ((*it).second==id && s.size()==1) {
				s.erase({ start[id], id });
				continue;
			}
			if (min_value > abs((*it).first - time)) {
				min_value = abs((*it).first - time);
				if ((*it).second == id) {
					++it;
				}
				min_id1 = (*it).second;
				min_id2 = id;
			}
			s.erase({ start[id], id });
		}
	}
	if (min_value == 2000000200) {
		cout << '0';
	}
	else {
		cout <<min(min_id1, min_id2) << ' ' << max(min_id1, min_id2);
	}
	return 0;
}
