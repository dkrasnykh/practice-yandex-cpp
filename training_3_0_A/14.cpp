//https://contest.yandex.ru/contest/45469/problems/14/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int INF = 1000000100;

int main() {
    int n;
    cin >> n;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];

    }
    vector<int> leftmin(n + 1, n + 1);
    vector<int> rightmin(n + 1, 0);
    stack<pair<int, int>> s;
    for (int i = 1; i <= n; ++i) {
        while (!s.empty() && s.top().first > h[i]) {
            auto v = s.top();
            s.pop();
            leftmin[v.second] = i;
        }
        s.push({ h[i], i });
    }
    stack<pair<int, int>> s1;
    for (int i = n; i > 0; --i) {
        while (!s1.empty() && s1.top().first > h[i]) {
            auto v = s1.top();
            s1.pop();
            rightmin[v.second] = i;

        }
        s1.push({ h[i], i });
    }
    int minh = INF;
    int lastzero = 0;
    unsigned long long maxa = 0;
    for (int i = 1; i <= n; ++i) {
        unsigned long long a = (leftmin[i] - rightmin[i] - 1) * static_cast<unsigned long long>(h[i]);
        maxa = max(maxa, a);
        if (h[i]==0 && minh < INF) {
            maxa = max((i-lastzero-1) * static_cast<unsigned long long>(minh), maxa);
            minh = INF;
            lastzero = i;
        } else {
            minh = min(h[i], minh);
        }
    }
    if (minh < INF) {
        maxa = max((n - lastzero) * static_cast<unsigned long long>(minh), maxa);
    }
    cout << maxa;
    return 0;
}

