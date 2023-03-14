//https://contest.yandex.ru/contest/45469/problems/23/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	unsigned long long n;
	cin >> n;
	unsigned long long ans = n * n;
	vector<unsigned long long> dp(n, 0);
	if (n == 1) {
		cout << ans;
		return 0;
	}
	dp[1] = 1;
	ans += dp[1];
	if (n == 2) {
		cout << ans;
		return 0;
	}
	dp[2] = 3;
	ans += dp[2];
	for (int i = 3; i < n; ++i) {
		dp[i] = dp[i - 1] + (dp[i - 1] - dp[i - 2] + 1);
		ans += dp[i];
	}
	for (int i = 1; i < n/2; ++i) {
		ans += dp[i * 2 - 1 + n % 2];
	}
	cout << ans;
	return 0;
}
