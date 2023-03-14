//https://contest.yandex.ru/contest/45468/problems/26/
#include <iostream>
#include <vector>

using namespace std;

const int INF = 5000;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> table(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> table[i][j];
		}
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = INF;
	}
	for (int i = 0; i <= m; ++i) {
		dp[0][i] = INF;
	}
	dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + table[i][j];
		}
	}
	cout << dp[n][m];
	return 0;
}

