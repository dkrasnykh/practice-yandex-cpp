#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> used;

void dfs(int v) {
	used[v] = true;
	for (const auto& u : adj[v]) {
		if (!used[u]) {
			dfs(u);
		}
	}
}

int main() {
	int n;
	cin >> n;
	adj = vector<vector<int>>(n + 1);
	used = vector<bool>(n + 1, false);
	for (int i = 1; i <= n; ++i) {
		int number;
		cin >> number;
		adj[number].push_back(i);
		adj[i].push_back(number);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (used[i]) {
			continue;
		}
		dfs(i);
		++cnt;
	}
	cout << cnt;
	return 0;
}
