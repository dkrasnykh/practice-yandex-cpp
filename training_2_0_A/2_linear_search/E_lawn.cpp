#include <iostream>
#include <cmath>
#include <tuple>
#include <fstream>
#include <string>

using namespace std;

pair<int, int> intersection(long long x11, long long x12, long long x21, long long x22) {
	if (x21 >= x11 && x21 <= x12) {
		return { x21, min(x12, x22) };
	}
	if (x22 >= x11 && x22 <= x12) {
		return { max(x11, x21), x22 };
	}
	if (x21<=x11 && x11<=x22) {
		return { x11, min(x12, x22) };
	}
	if (x21<=x12 && x12<=x22) {
		return { max(x21, x11), x12 };
	}
	if (x21 <= x11 && x12 <= x22) {
		return { x11, x12 };
	}
	return { 1, 0 };
}

long long dy(long long x, long long x3, long long y3, long long r, long long y1, long long y2) {
	long double tmp = sqrt(r * r - ((x - x3) * (x - x3))) + y3;
	long double t1;
	modf(tmp, &t1);
	if (tmp < 0 && t1 > tmp) {
		tmp += -1;
	}
	long long circle_y2 = static_cast<long long>(tmp);
	long double tmp1 = -sqrt(r * r - ((x - x3) * (x - x3))) + y3;
	long double t2;
	modf(tmp1, &t2);
	if (tmp1>0 && tmp1>t2) {
		tmp1 += 1;
	}
	long long circle_y1 = static_cast<long long>(tmp1);
	pair<long long, long long> yy = intersection(y1, y2, circle_y1, circle_y2);
	long long y11 = yy.first;
	long long y12 = yy.second;
	if (y11 > y12) {
		return 0;
	}
	if (y11*y12 < 0) {
		return (abs(y12) + abs(y11) + 1);
	} else {
		return (abs(y12 - y11) + 1);
	}
}

int main() {
	long long x1, y1, x2, y2, x3, y3, r;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> r;
	pair<long long, long long> xx = intersection(x1, x2, x3 - r, x3 + r);
	long long x4 = xx.first;
	long long x5 = xx.second;
	long long ans = 0;
	for (int i = x4; i <= x5; ++i) {
		ans += dy(i, x3, y3, r, y1, y2);
	}
	cout << ans;
	return 0;
}
