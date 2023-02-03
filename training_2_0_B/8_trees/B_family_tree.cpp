#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

vector<bool> used;
vector<vector<int>> adj;

bool dfs(int v, int target) {
    used[v] = true;
    bool founded = false;
    for (const auto& u : adj[v]) {
        if (used[u]) {
            continue;
        }
        if (u == target) {
            return true;
        }
        else {
            founded = dfs(u, target);
            if (founded) {
                break;
            }
        }
    }
    return founded;
}


int main() {
    int n;
    cin >> n;
    map<string, int> to_id;
    int id = 0;
    vector<vector<string>> a(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        a[i].resize(2);
        string s;
        cin >> s;
        a[i][0] = s;
        cin >> s;
        a[i][1] = s;
        auto it = to_id.find(a[i][0]);
        if (it == to_id.end()) {
            to_id.insert({ a[i][0], id });
            ++id;
        }
        it = to_id.find(a[i][1]);
        if (it == to_id.end()) {
            to_id.insert({ a[i][1], id });
            ++id;
        }
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
    adj = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; ++i) {
        adj[to_id[a[i][1]]].push_back(to_id[a[i][0]]);
    }
    for (const auto& req : reqs) {
        used = vector<bool>(n, false);
        if (dfs(to_id[req[0]], to_id[req[1]])) {
            cout << "1 ";
            continue;
        }
        used = vector<bool>(n, false);
        if (dfs(to_id[req[1]], to_id[req[0]])) {
            cout << "2 ";
            continue;
        }
        cout << "0 ";
    }
    return 0;
}
