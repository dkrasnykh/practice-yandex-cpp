//https://contest.yandex.ru/contest/45468/problems/30/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> seq1(n+1);
	for (int i = 1; i <= n; ++i) {
		cin >> seq1[i];
	}
	int m;
	cin >> m;
	vector<int> seq2(m+1);
	for (int i = 1; i <= m; ++i) {
		cin >> seq2[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (seq1[i] == seq2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i = n;
	int j = m;
	vector<int> ans;
	while (i > 0 && j > 0) {
		if (seq1[i] == seq2[j]) {
			ans.push_back(seq1[i]);
			--i;
			--j;
		} else if (dp[i-1][j] == dp[i][j]) {
			--i;
		} else if (dp[i][j-1] == dp[i][j]) {
			--j;
		}
	}
	int size = static_cast<int>(ans.size());
	for (int i = size - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
	return 0;
}

