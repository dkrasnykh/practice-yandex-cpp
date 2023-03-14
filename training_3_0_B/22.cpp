//https://contest.yandex.ru/contest/45468/problems/22/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<long long> dp(max(n + 1, k + 1));
	vector<long long> prefix(max(n + 1, k + 1));
	dp[0] = 1;
	prefix[0] = 0;
	dp[1] = 1;
	prefix[1] = prefix[0] + dp[0];

	for (int i = 2; i < k; ++i) {
		prefix[i] = prefix[i - 1] + dp[i - 1];
		dp[i] = prefix[i];
	}

	for (int i = k; i < n; ++i) {
		prefix[i] = prefix[i - 1] + dp[i - 1];
		dp[i] = prefix[i] - prefix[i - k];
	}
	cout << dp[n-1];
	return 0;
}

