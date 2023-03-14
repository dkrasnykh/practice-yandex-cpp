//https://contest.yandex.ru/contest/45468/problems/21/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> dp(4);
	dp[1] = 2;
	dp[2] = 4;
	dp[3] = 7;
	int n;
	cin >> n;
	dp.resize(n + 1);
	for (int i = 4; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	cout << dp[n];
	return 0;
}
