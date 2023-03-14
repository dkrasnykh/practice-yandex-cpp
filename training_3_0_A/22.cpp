//https://contest.yandex.ru/contest/45469/problems/22/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> dp(n);
	vector<int> p(n);
	dp[0] = 1;
	p[0] = -1;
	int idp = -1;
	int imaxdp = 0;
	for (int i = 1; i < n; ++i) {
		int imax = -1;
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i] && (imax == -1 || dp[imax] < dp[j])) {
				imax = j;
			}
		}
		if (imax == -1) {
			dp[i] = 1;
			p[i] = -1;
		} else {
			dp[i] = dp[imax] + 1;
			p[i] = imax;
		}
		if (imaxdp < dp[i]) {
			imaxdp = dp[i];
			idp = i;
		}
	}
	vector<int> ans;
	ans.push_back(a[idp]);
	while (p[idp] != -1) {
		ans.push_back(a[p[idp]]);
		idp = p[idp];
	}
	for (int i = static_cast<int>(ans.size()) - 1; i >= 0; --i) {
		cout << ans[i] << ' ';
	}
	return 0;
}

