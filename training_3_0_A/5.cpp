//https://contest.yandex.ru/contest/45469/problems/5/
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000100;
vector<int> alphaset;

bool check(int n) {
	for (int i = 1; i < n - 1; ++i) {
		if (alphaset[i] > 0 && (alphaset[i - 1] != 0 || alphaset[i + 1] != 0)) {
			return false;

		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	alphaset = vector<int>(n);
	int mincnt = INF;
	for (int i = 0; i < n; ++i) {
		cin >> alphaset[i];
		mincnt = min(mincnt, alphaset[i]);
	}

	long long goodness = 0;
	goodness += (n - 1) * static_cast<long long>(mincnt);

	for (int i = 0; i < n; ++i) {
		alphaset[i] -= mincnt;
	}

	while (true) {
		int l = -1;
		mincnt = INF;
		for (int i = 0; i < n; ++i) {
			if (l==-1 && alphaset[i]>0 && i+1<alphaset.size() && alphaset[i+1]>0) {
				l = i;
				mincnt = min(mincnt, alphaset[i]);
			} else if (l != -1 && alphaset[i] > 0) {
				mincnt = min(mincnt, alphaset[i]);
				if (i + 1 == alphaset.size() || alphaset[i + 1] == 0) {
					goodness += (i - l) * static_cast<long long>(mincnt);
					for (int j = l; j <= i; ++j) {
						alphaset[j] -= mincnt;
					}
					mincnt = INF;
					l = -1;
				}
			}
		}
		if (check(n)) {
			break;
		}
	}
	cout << goodness << '\n';
	return 0;
}
