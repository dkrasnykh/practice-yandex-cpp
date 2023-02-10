#include <iostream>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	set<pair<int, int>> edges;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u != v) {
			edges.insert({min(u,v), max(u,v)});
		}
	}
	cout << n << ' ' << edges.size() << '\n';
	for (const auto& e: edges) {
		cout << e.first << ' ' << e.second << '\n';
	}
	return 0;
}
