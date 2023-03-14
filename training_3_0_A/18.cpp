//https://contest.yandex.ru/contest/45469/problems/18/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <set>

using namespace std;

int main() {
    priority_queue<pair<int, int>, std::vector<pair<int, int>>, greater<pair<int, int>>> q;
    int k, n;
    cin >> k >> n;
    int endway = 1;
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int a, d;
        cin >> a >> d;
        if (!q.empty() && q.top().first < a) {
            set<pair<int, int>> s;
            while (!q.empty() && q.top().first < a) {
                auto e = q.top();
                s.insert({ e.second, e.first });
                q.pop();
            }
            auto it = s.begin();
            q.push({ d, it->first });
            ans.push_back(it->first );
            s.erase(it);
            for (const auto& e: s) {
                q.push({ e.second, e.first });
            }
        } else {
            if (endway <= k) {
                q.push({ d, endway });
                ans.push_back(endway);
                ++endway;
            } else {
                cout << "0 " << i << '\n';
                return 0;
            }
        }
    }
    for (const auto& e: ans) {
        cout << e << ' ';
    }
    return 0;
}

