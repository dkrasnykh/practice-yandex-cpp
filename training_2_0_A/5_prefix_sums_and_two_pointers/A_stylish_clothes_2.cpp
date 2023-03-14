#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n1, n2, n3, n4;
vector<vector<int>> colors(4);

int maxcolor(int p0, int p1, int p2, int p3) {
	set<int, greater<int>> color = { colors[0][p0] , colors[1][p1], colors[2][p2], colors[3][p3] };
	return (*color.begin());
}

int mincolor(int p0, int p1, int p2, int p3) {
	set<int> color = { colors[0][p0] , colors[1][p1], colors[2][p2], colors[3][p3] };
	return (*color.begin());
}

int next(int p0, int p1, int p2, int p3) {
	set<pair<int, int>> comp;
	if (p0<n1-1) {
		comp.insert({colors[0][p0], 0});
	}
	if (p1<n2-1) {
		comp.insert({ colors[1][p1], 1 });
	}
	if (p2<n3-1) {
		comp.insert({ colors[2][p2], 2 });
	}
	if (p3<n4-1) {
		comp.insert({ colors[3][p3], 3 });
	}
	return (*comp.begin()).second;
}

int main() {
	cin >> n1;
	colors[0].resize(n1);
	for (int i = 0; i < n1; ++i) {
		cin >> colors[0][i];
	}
	cin >> n2;
	colors[1].resize(n2);
	for (int i = 0; i < n2; ++i) {
		cin >> colors[1][i];
	}
	cin >> n3;
	colors[2].resize(n3);
	for (int i = 0; i < n3; ++i) {
		cin >> colors[2][i];
	}
	cin >> n4;
	colors[3].resize(n4);
	for (int i = 0; i < n4; ++i) {
		cin >> colors[3][i];
	}
	for (int i = 0; i < 4; ++i) {
		sort(colors[i].begin(), colors[i].end());
	}
	int p0 = 0, p1 = 0, p2 = 0, p3 = 0;
	int diff = 100100;
	int c0, c1, c2, c3;
	while (!(p0 == (n1 - 1) && p1 == (n2 - 1) && p2 == (n3 - 1) && p3 == (n4 - 1))) {
		int high = maxcolor(p0, p1, p2, p3);
		int low = mincolor(p0, p1, p2, p3);
		if (high == low) {
			c0 = colors[0][p0];
			c1 = colors[1][p1];
			c2 = colors[2][p2];
			c3 = colors[3][p3];
			break;
		}
		if (high - low < diff) {
			diff = high - low;
			c0 = colors[0][p0];
			c1 = colors[1][p1];
			c2 = colors[2][p2];
			c3 = colors[3][p3];
		}
		int ind = next(p0, p1, p2, p3);
		switch (ind) {
		case 0:
			++p0;
			break;
		case 1:
			++p1;
			break;
		case 2:
			++p2;
			break;
		case 3:
			++p3;
			break;
		}
	}
	cout << c0 << ' ' << c1 << ' ' << c2 << ' ' << c3;
	return 0;
}
