//https://contest.yandex.ru/contest/45469/problems/19/
#include <iostream>
#include <queue>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(2);
    priority_queue<int, std::vector<int>, greater<int>> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        q.push(value);
    }
    long double ans = 0;
    while (!q.empty()) {
        auto v1 = q.top();
        q.pop();
        auto v2 = q.top();
        q.pop();
        long double t = (v1 + v2) * 0.05;
        ans += t;
        if (!q.empty()) {
            q.push(v1 + v2);
        }
    }
    cout << ans << '\n';
    return 0;
}

