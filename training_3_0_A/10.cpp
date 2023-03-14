//https://contest.yandex.ru/contest/45469/problems/10/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	string s;
	cin >> s;
	int size = static_cast<int>(s.size());
	vector<long long> prefix(size, 0);
	prefix[0] = size;
	for (int i = 1; i < size; ++i) {
		prefix[i] = prefix[i - 1] + size - i * 2;
	}
	map<char, long long> ans;
	for (int i = 0; i < size; ++i) {
		ans[s[i]] += prefix[i];
	}
	for (const auto& e: ans) {
		cout << e.first << ": " << e.second << '\n';
	}
	return 0;
}
