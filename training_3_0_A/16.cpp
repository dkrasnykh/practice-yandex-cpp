//https://contest.yandex.ru/contest/45469/problems/16/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i < k) {
            s.insert(a[i]);
        }
    }
    vector<int> ans;
    for (int i = 0; i + k < n; ++i) {
        ans.push_back(*s.begin());
        auto it = s.find(a[i]);
        s.erase(it);
        s.insert(a[i + k]);
    }
    ans.push_back(*s.begin());
    for (const auto& e: ans) {
        cout << e << '\n';
    }
    return 0;
}
