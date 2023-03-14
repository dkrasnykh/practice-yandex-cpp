//https://contest.yandex.ru/contest/45468/problems/23/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> dp(max(n + 1, 4));
	vector<int> p(max(n + 1, 4));
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	p[1] = -1;
	p[2] = 1;
	p[3] = 1;
	for (int i = 4; i <= n; ++i) {
		dp[i] = dp[i - 1] + 1;
		p[i] = i - 1;
		if (i%2 == 0 && dp[i/2] + 1 < dp[i]) {
			dp[i] = dp[i / 2] + 1;
			p[i] = i / 2;
		}
		if (i%3 == 0 && dp[i/3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;
			p[i] = i / 3;
		}
	}
	cout << dp[n] << '\n';
	vector<int> ans;
	ans.push_back(n);
	int i = n;
	while (p[i] != -1) {
		ans.push_back(p[i]);
		i = p[i];
	}
	for (int i = static_cast<int>(ans.size()) - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
	return 0;
}

