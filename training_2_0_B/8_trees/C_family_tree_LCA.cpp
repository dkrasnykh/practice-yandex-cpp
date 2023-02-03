#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<bool> used;
vector<vector<int>> adj;
int n, l;
vector<int> tin, tout;
int timer;
vector <vector<int>> up;

void dfs(int v, int p = 0) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i - 1]][i - 1];
    for (size_t i = 0; i < adj[v].size(); ++i) {
        int to = adj[v][i];
        if (to != p)
            dfs(to, v);
    }
    tout[v] = ++timer;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (upper(a, b)) {
        return a;
    }
    if (upper(b, a)) {
        return b;
    }
    for (int i = l; i >= 0; --i) {
        if (!upper(up[a][i], b)) {
            a = up[a][i];
        }
    }
    return up[a][0];
}

int main() {
    int n;
    cin >> n;
    map<string, int> to_id;
    map<int, string> to_name;
    vector<vector<string>> a(n - 1);
    set<string> children;
    set<string> parents;

    for (int i = 0; i < n - 1; ++i) {
        a[i].resize(2);
        string s;
        cin >> s;
        a[i][0] = s;
        cin >> s;
        a[i][1] = s;
        children.insert(a[i][0]);
        parents.insert(a[i][1]);
    }

    vector<vector<string>> reqs;
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        if (s.empty()) {
            continue;
        }
        string child, parent;
        ss >> child;
        ss >> parent;
        reqs.push_back({ child, parent });
    }

    string root;
    for (const auto& e: parents) {
        auto it = children.find(e);
        if (it==children.end()) {
            root = e;
            break;
        }
    }
    parents.erase(root);
    to_id[root] = 0;
    to_name[0] = root;
    int id = 1;
    for (const auto& e : parents) {
        auto it = to_id.find(e);
        if (it == to_id.end()) {
            to_id.insert({ e, id });
            to_name.insert({ id, e });
            ++id;
        }
    }
    for (const auto& e : children) {
        auto it = to_id.find(e);
        if (it == to_id.end()) {
            to_id.insert({ e, id });
            to_name.insert({ id, e });
            ++id;
        }
    }
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; ++i) {
        adj[to_id[a[i][1]]].push_back(to_id[a[i][0]]);
        adj[to_id[a[i][0]]].push_back(to_id[a[i][1]]);
    }
    tin.resize(n);
    tout.resize(n);
    up.resize(n);
    l = 1;
    while ((1 << l) <= n) {
        ++l;
    }
    for (int i = 0; i < n; ++i) {
        up[i].resize(l + 1);
    }
    dfs(0);

    for (const auto& req : reqs) {
        int a, b;
        a = to_id[req[0]];
        b = to_id[req[1]];
        int res = lca(a, b);
        cout << to_name[res] <<'\n';
    }
    return 0;
}
