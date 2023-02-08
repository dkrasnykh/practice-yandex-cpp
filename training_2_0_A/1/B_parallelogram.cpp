#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <limits>
#include <fstream>
#include <string>

using namespace std;


bool is_equal(long double x, long double y) {
	//if( abs(L-R) < 0.00001 )
	return std::fabs(x - y) < std::numeric_limits<long double>::epsilon();
}

long double coefficient(int x1, int y1, int x2, int y2) {
	return ((x2 - x1 == 0) ? 0 : static_cast<long double>(y2 - y1)/(x2 -x1));
}

string is_parallelogram(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	/*
	a - x1, y1
	b - x2, y2
	c - x3, y3
	d - x4, y4
	*/
	long double k1 = coefficient(x1, y1, x2, y2);
	long double k2 = coefficient(x3, y3, x4, y4);
	//ab || cd
	if (is_equal(k1, k2) && (pow((x2-x1), 2)+pow((y2-y1), 2) == pow((x4-x3), 2)+pow((y4-y3), 2))) {
		//ac || bd
		long double k3 = coefficient(x1, y1, x3, y3);
		long double k4 = coefficient(x2, y2, x4, y4);
		if (is_equal(k3, k4) && (pow((x3 - x1), 2) + pow((y3 - y1), 2) == pow((x4 - x2), 2) + pow((y4 - y2), 2))) {
			return "YES";
		}
		//ad || bc
		long double k5 = coefficient(x1, y1, x4, y4);
		long double k6 = coefficient(x2, y2, x3, y3);
		if (is_equal(k5, k6) && (pow((x4 - x1), 2) + pow((y4 - y1), 2) == pow((x3 - x2), 2) + pow((y3 - y2), 2))) {
			return "YES";
		}
	}
	//ad || bc
	k1 = coefficient(x1, y1, x4, y4);
	k2 = coefficient(x2, y2, x3, y3);
	if (is_equal(k1, k2) && (pow((x4 - x1), 2) + pow((y4 - y1), 2) == pow((x3 - x2), 2) + pow((y3 - y2), 2))) {
		//ac || bd
		long double k3 = coefficient(x1, y1, x3, y3);
		long double k4 = coefficient(x2, y2, x4, y4);
		if (is_equal(k3, k4) && (pow((x3 - x1), 2) + pow((y3 - y1), 2) == pow((x4 - x2), 2) + pow((y4 - y2), 2))) {
			return "YES";
		}
		//ab || dc
		long double k5 = coefficient(x1, y1, x2, y2);
		long double k6 = coefficient(x3, y3, x4, y4);

		if (is_equal(k5, k6) && (pow((x2 - x1), 2) + pow((y2 - y1), 2) == pow((x4 - x3), 2) + pow((y4 - y3), 2))) {
			cout << "YES";
		}
	}
	//ac || bd
	k1 = coefficient(x1, y1, x3, y3);
	k2 = coefficient(x2, y2, x4, y4);
	if (is_equal(k1, k2) && (pow((x3 - x1), 2) + pow((y3 - y1), 2) == pow((x4 - x2), 2) + pow((y4 - y2), 2))) {
		//ab || cd
		long double k3 = coefficient(x1, y1, x2, y2);
		long double k4 = coefficient(x3, y3, x4, y4);

		if (is_equal(k3, k4) && (pow((x2 - x1), 2) + pow((y2 - y1), 2) == pow((x4 - x3), 2) + pow((y4 - y3), 2))) {
			cout << "YES";
		}
		//ad || cb
		long double k5 = coefficient(x1, y1, x4, y4);
		long double k6 = coefficient(x2, y2, x3, y3);
		if (is_equal(k5, k6) && (pow((x4 - x1), 2) + pow((y4 - y1), 2) == pow((x3 - x2), 2) + pow((y3 - y2), 2))) {
			return "YES";
		}
	}
	return "NO";
}


int main() {
	int n;
	cin >> n;
	vector<string> ans;
	for (int i = 0; i < n; ++i) {
		int x1, y1, x2, y2, x3, y3, x4, y4;
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
		ans.push_back(is_parallelogram(x1, y1, x2, y2, x3, y3, x4, y4));
	}
	for (const auto& e: ans) {
		cout << e << '\n';
	}
	return 0;
}
