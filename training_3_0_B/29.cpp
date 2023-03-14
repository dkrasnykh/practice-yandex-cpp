//https://contest.yandex.ru/contest/45468/problems/29/
#include <iostream>
#include <vector>

using namespace std;

const int INF = 35000;

int main() {
	int n;
	cin >> n;
	vector<int> price(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		cin >> price[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {

		if (price[i] > 100 && i == 1) {
			dp[1][1] = price[i];
		} else if (price[i] > 100) {
			dp[i][0] = dp[i - 1][1];
		} else {
			dp[i][0] = min(dp[i - 1][0] + price[i], dp[i - 1][1]);
		}
		for (int j = 1; j < n; ++j) {
			if (price[i] > 100) {
				dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j - 1] + price[i]);
			} else {
				dp[i][j] = min(dp[i - 1][j + 1], dp[i - 1][j] + price[i]);
			}
		}
	}
	int jmin = 0;
	int minvalue = dp[n][0];
	for (int j = 0; j <= n; ++j) {
		if (dp[n][j] <= minvalue) {
			minvalue = dp[n][j];
			jmin = j;
		}
	}

	cout << dp[n][jmin] << '\n';

	int i = n;
	int j = jmin;
	vector<int> ans;
	while (i > 0) {
		if (j < n && dp[i][j] == dp[i - 1][j + 1]) {
			ans.push_back(i);
			--i;
			++j;
		} else if (dp[i][j] == dp[i - 1][j] + price[i]) {
			--i;
		} else if (j > 0 && dp[i][j] == dp[i - 1][j - 1] + price[i]) {
			--i;
			--j;
		}
	}
	int size = static_cast<int>(ans.size());

	cout << jmin << ' ' << size << '\n';

	for (int i = size - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}

	return 0;
}

