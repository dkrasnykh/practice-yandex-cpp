//https://contest.yandex.ru/contest/45468/problems/28/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
	dp[2][2] = 1;
	for (int i = 2; i < n + 2; ++i) {
		for (int j = 2; j < m + 2; ++j) {
			dp[i][j] += (dp[i - 1][j - 2] + dp[i - 2][j - 1]);
		}
	}
	cout << dp[n + 1][m + 1];
	return 0;
}
