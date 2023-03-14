//https://contest.yandex.ru/contest/45469/problems/20/
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    unordered_map<int, int> last_ind;
    vector<int> request(p);
    vector<int> next(p, p);
    for (int i = 0; i < p; ++i) {
        cin >> request[i];
        auto it = last_ind.find(request[i]);
        if (it != last_ind.end()) {
            next[last_ind[request[i]]] = i;
        }
        last_ind[request[i]] = i;
    }
    int ans = 0;
    set<pair<int, int>> q;
    unordered_set<int> onfloor;
    for (int i = 0; i < p; ++i) {
        auto it = onfloor.find(request[i]);
        if (it == onfloor.end()) {
            ++ans;
            if (q.size() == k) {
                auto it1 = q.end();
                it1--;
                onfloor.erase(it1->second);
                q.erase(it1);
            }
            q.insert({ next[i], request[i] });
            onfloor.insert(request[i]);
        } else {
            q.erase({ i, request[i] });
            q.insert({ next[i], request[i] });
        }
    }
    cout << ans << '\n';
    return 0;
}

