//https://contest.yandex.ru/contest/45468/problems/24/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n + 3);
	vector<long long> b(n + 3);
	vector<long long> c(n + 3);
	vector<long long> dp(n + 3);
	for (int i = 0; i < 3; ++i) {
		a[i] = 11000;
		b[i] = 11000;
		c[i] = 11000;
		dp[i] = 0;
	}

	for (int i = 3; i <= n + 2; ++i) {
		cin >> a[i] >> b[i] >> c[i];
	}

	for (int i = 3; i <= n + 2; ++i) {
		dp[i] = min(a[i] + dp[i - 1], min(b[i - 1] + dp[i - 2], c[i - 2] + dp[i - 3]));
	}

	cout << dp[n + 2];
	return 0;
}

