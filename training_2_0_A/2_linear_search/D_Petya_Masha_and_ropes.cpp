#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	int total = 0;
	int maxlen = 0;
	for (int i = 0; i < n; ++i) {
		int d;
		cin >> d;
		total += d;
		maxlen = max(d, maxlen);
	}
	if (maxlen == (total-maxlen)) {
		cout << total << endl;
	} else {
		cout << (maxlen - (total-maxlen)) << endl;
	}
	return 0;
}
