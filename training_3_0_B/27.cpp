//https://contest.yandex.ru/contest/45468/problems/27/
#include <iostream>
#include <vector>

using namespace std;

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
		dp[i][0] = -1;
	}
	for (int i = 0; i <= m; ++i) {
		dp[0][i] = -1;
	}
	dp[0][1] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + table[i][j];
		}
	}
	vector<char> ans;
	int i = n;
	int j = m;
	while (i > 0 && j > 0) {
		if (dp[i][j]-table[i][j] == dp[i-1][j]) {
			ans.push_back('D');
			--i;
		} else if (dp[i][j]-table[i][j]==dp[i][j-1]) {
			ans.push_back('R');
			--j;
		}
	}
	cout << dp[n][m] << '\n';
	int size = static_cast<int>(ans.size());
	for (int i = size - 2; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
	return 0;
}
