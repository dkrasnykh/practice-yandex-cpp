//https://contest.yandex.ru/contest/45468/problems/15/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> city(n);
	for (int i = 0; i < n; ++i) {
		cin >> city[i];
	}
	vector<int> ans(n, -1);
	stack<pair<int, int>> moveto;
	for (int i = 0; i < n; ++i) {
		while (!moveto.empty() && moveto.top().first > city[i]) {
			auto value = moveto.top();
			moveto.pop();
			ans[value.second] = i;
		}
		moveto.push({city[i], i});
	}
	for (const auto& e: ans) {
		cout << e << ' ';
	}
}
