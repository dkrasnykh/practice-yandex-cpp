//https://contest.yandex.ru/contest/45469/problems/21/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		int exp = round(pow(i, 1.0 / 3));
		int mindp = n + 1;
		for (int j = 1; j <= exp; ++j) {
			if (i - j * j * j >= 0) {
				mindp = min(mindp, dp[i - j * j * j] + 1);
			}
		}
		dp[i] = mindp;
	}
	cout << dp[n];
	return 0;
}
