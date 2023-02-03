#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> used;
vector<int> path, ans;

void dfs(int v) {
	used[v] = true;
	path.push_back(v);
	for (int to : adj[v]) {
		if (!used[to]) {
			dfs(to);
		}
	}
	if (path.size() > ans.size()) {
		ans = path;
	}
	path.pop_back();
}

int main() {
	int n;
	cin >> n;
	adj = vector<vector<int>>(n + 1);
	used = vector<bool>(n + 1);
	for (int i = 0; i <n-1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1);
	used = vector<bool>(n + 1, false);
	dfs(ans.back());
	cout << ans.size();
	return 0;
}
