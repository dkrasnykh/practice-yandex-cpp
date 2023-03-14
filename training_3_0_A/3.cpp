//https://contest.yandex.ru/contest/45469/problems/3/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int binsearch(int l, int r, int p, vector<int>& sticker) {
	while (l<r) {
		int m = (l+r+1) / 2;
		if (sticker[m]<p) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	if (sticker[l]<p) {
		return l;
	} else {
		return -1;
	}
}

int main() {
	int n;
	cin >> n;
	set<int> tmp;
	vector<int> sticker;
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		tmp.insert(s);
	}
	for (const auto& e : tmp) {
		sticker.push_back(e);
	}
	int k;
	cin >> k;
	vector<int> ans;
	for (int i = 0; i < k; ++i) {
		int p;
		cin >> p;
		int a = binsearch(0, sticker.size()-1, p, sticker);
		ans.push_back(a+1);
	}
	for (const auto& e: ans) {
		cout << e <<'\n';
	}
	return 0;
}
