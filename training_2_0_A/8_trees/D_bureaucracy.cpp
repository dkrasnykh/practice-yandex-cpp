#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

//TL 41 test

vector<set<int>> adj;
vector<bool> used;
vector<int> payments;
vector<int> payment;

void dfs(int v, int boss) {
	if (adj[v].size() == 0) {
		payment[v] += 1;
		payments[v] += payment[v];
		adj[boss].erase(v);
		return;
	}
	int u = *(adj[v].begin());
	dfs(u, v);
	payment[v] += (payment[u] + 1);
	payments[v] += payment[v];
}

int main() {
	int n;
	cin >> n;
	adj = vector<set<int>>(n + 1);
	payments = vector<int>(n + 1, 0);
	for (int i = 2; i <= n; ++i) {
		int boss;
		cin >> boss;
		adj[boss].insert(i);
	}
	while (adj[1].size() != 0) {
		payment = vector<int>(n + 1, 0);
		dfs(1, 1);
	}
	payments[1] += 1;
	for (int i = 1; i <= n; ++i) {
		cout << payments[i] << ' ';
	}
	return 0;
}
