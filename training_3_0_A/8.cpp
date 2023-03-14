//https://contest.yandex.ru/contest/45469/problems/8/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int k;
	cin >> k;
	int minx = 1000000100, maxx = -1000000100, miny = 1000000100, maxy = -1000000100;
	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> x >> y;
		maxx = max(maxx, x);
		minx = min(minx, x);
		maxy = max(maxy, y);
		miny = min(miny, y);
	}
	cout << minx << ' ' << miny << ' ' << maxx << ' ' << maxy << '\n';
	return 0;
}
