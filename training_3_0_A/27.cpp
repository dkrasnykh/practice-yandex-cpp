//https://contest.yandex.ru/contest/45469/problems/27/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	int size1 = static_cast<int>(s1.size());
	int size2 = static_cast<int>(s2.size());
	vector<vector<int>> dp(size1, vector<int>(size2, 0));
	int imatch = -1;
	for (int j = 0; j < size2; ++j) {
		if (s2[j] == s1[0]) {
			imatch = j;
		}
		if (imatch >= 0) {
			dp[0][j] = j;
		} else {
			dp[0][j] = j + 1;
		}
	}
	imatch = -1;
	for (int i = 0; i < size1; ++i) {
		if (s1[i] == s2[0]) {
			imatch = i;
		}
		if (imatch>=0) {
			dp[i][0] = i;
		} else {
			dp[i][0] = i + 1;
		}
	}
	for (int i = 1; i < size1; ++i) {
		for (int j = 1; j < size2; ++j) {
			if (s1[i] == s2[j]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
		}
	}
	cout << dp[size1-1][size2-1];
	return 0;
}

