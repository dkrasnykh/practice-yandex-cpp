#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

//https://contest.yandex.ru/contest/45469/problems/1/
using namespace std;

int main() {
	map<char, int> freq;
	char c = '\0';
	int maxsize = 0;
	while (cin.get(c)) {
		if (c!=' ' && c!='\n') {
			freq[c]++;
			maxsize = max(maxsize, freq[c]);
		}
	}
	vector<vector<char>> ans(maxsize+1);
	for (int i = 0; i < maxsize+1; ++i) {
		ans[i].resize(freq.size(), ' ');
	}
	int j = 0;
	for (const auto& e : freq) {
		ans[0][j] = e.first;
		for (int i = 1; i <= e.second; ++i) {
			ans[i][j] = '#';
		}
		++j;
	}
	int size = static_cast<int>(freq.size());
	for (int i = maxsize; i >= 0; --i) {
		for (int j = 0; j < size; ++j) {
			cout << ans[i][j];

		}
		cout << '\n';
	}
	return 0;
}
