#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

bool is_equal(long double x, long double y) {
	//if( abs(L-R) < 0.00001 )
	return std::fabs(x - y) < std::numeric_limits<long double>::epsilon();
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (a==0 && b!=0) {
		cout << "NO";
		return 0;
	}
	if (a==0 && b==0) {
		cout << "INF";
		return 0;
	}
	if (c!=0 && d!=0) {
		long double k1 = static_cast<long double>(a) / c;
		long double k2 = static_cast<long double>(b) / d;
		if (is_equal(k1, k2)) {
			cout << "NO";
			return 0;
		}
	}
	if (b%a==0) {
		cout << -b / a;
	} else {
		cout << "NO";
	}
	return 0;
}
