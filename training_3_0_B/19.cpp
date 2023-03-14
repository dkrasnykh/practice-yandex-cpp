//https://contest.yandex.ru/contest/45468/problems/19/
#include <iostream>
#include <vector>

using namespace std;

class Heap {
private:
    vector<int> a;

    void siftup(int v) {
        while (v != 1) {
            if (a[v] > a[v / 2]) {
                swap(a[v], a[v / 2]);
                v /= 2;
            }
            else {
                break;
            }
        }
    }

    void siftdown(int v) {
        int n = static_cast<int>(a.size()) - 1;
        while (v * 2 <= n) {
            int u = v * 2;
            if (v * 2 + 1 <= n && a[v * 2 + 1] > a[u]) {
                u = v * 2 + 1;
            }
            if (a[u] > a[v]) {
                swap(a[u], a[v]);
                v = u;
            }
            else {
                break;
            }
        }
    }
public:
    Heap() :a({ 0 }) {}
    void insert(int x) {
        a.push_back(x);
        int n = static_cast<int>(a.size()) - 1;
        siftup(n);
    }

    int extractmax() {
        int ans = a[1];
        int n = static_cast<int>(a.size()) - 1;
        swap(a[1], a[n]);
        a.pop_back();
        siftdown(1);
        return ans;
    }
};


int main() {
    int n;
    cin >> n;
    vector<int> ans;
    Heap h;
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        if (c == 0) {
            int v;
            cin >> v;
            h.insert(v);
        } else {
            ans.push_back(h.extractmax());
        }
    }
    for (const auto& e : ans) {
        cout << e << '\n';
    }
    return 0;
}

