//https://contest.yandex.ru/contest/45469/problems/9/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<long long>> matrix(n + 1);
	vector<vector<long long>> prefix(n + 1);
	for (int i = 1; i <= n; ++i) {
		matrix[i].resize(m + 1);
		prefix[i].resize(m + 1);
		for (int j = 1; j <= m; ++j) {
			cin >> matrix[i][j];
		}
	}
	for (int i =1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			prefix[i][j] = matrix[i][j];
			if (i > 1) {
				prefix[i][j] += prefix[i - 1][j];
			}
			if (j > 1) {
				prefix[i][j] += prefix[i][j - 1];
			}
			if (i > 1 && j > 1) {
				prefix[i][j] -= prefix[i - 1][j - 1];
			}
		}
	}
	vector<long long> ans;
	for (int i = 0; i < k; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		long long target = 0;
		target += prefix[x2][y2];
		if (x1 > 1) {
			target -= prefix[x1 - 1][y2];
		}
		if (y1 > 1) {
			target -= prefix[x2][y1 - 1];
		}
		if (x1 > 1 && y1 > 1) {
			target += prefix[x1 - 1][y1 - 1];
		}
		ans.push_back(target);
	}
	for (const auto& e : ans) {
		cout << e << '\n';
	}
	return 0;
}
