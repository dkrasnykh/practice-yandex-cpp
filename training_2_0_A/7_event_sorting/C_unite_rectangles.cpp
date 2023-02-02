#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

/*
https://contest.yandex.ru/contest/29401/problems/C/
*/

int main() {
	int n;
	cin >> n;
	vector<vector<int>> event;

	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 || y1 == y2) {
			continue;
		}
		event.push_back({ x1, -1, y1, y2, i });
		event.push_back({ x2, 1, y1, y2, i });
	}
	sort(event.begin(), event.end());
	set<vector<int>> open;

	int length_x = 0;
	int length_y = 0;
	unsigned long long s = 0;
	for (int i = 0; i != event.size(); ++i) {
		int state = event[i][1];
		int x = event[i][0];
		int y1 = event[i][2];
		int y2 = event[i][3];
		int id = event[i][4];

		if (state==-1) {
			open.insert({y1, -1, id});
			open.insert({y2, 1, id});
			length_x = (i==0)?0:(x - event[i - 1][0]);
			s += static_cast<unsigned long long>(length_y) * static_cast<unsigned long long>(length_x);

			int opened = 0;
			length_y = 0;
			int last = 0;
			for (const auto& e : open) {
				if (opened == 0) {
					last = e[0];
				}
				opened += e[1];
				if (opened==0) {
					length_y += (e[0] - last);
				}
			}
		} else if (state==1) {
			open.erase({ y1, -1, id });
			open.erase({ y2, 1, id });
			length_x = x - event[i - 1][0];
			s += static_cast<unsigned long long>(length_y) * static_cast<unsigned long long>(length_x);
			int opened = 0;
			length_y = 0;
			int last = 0;
			for (const auto& e : open) {
				if (opened == 0) {
					last = e[0];
				}
				opened += e[1];
				if (opened == 0) {
					length_y += (e[0] - last);
				}
			}
		}
	}
	cout << s << '\n';
	return 0;
}
