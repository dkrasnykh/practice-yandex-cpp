//https://contest.yandex.ru/contest/45469/problems/17/
#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q1;
    deque<int> q2;

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        char c;
        cin >> c;
        int id;
        switch (c) {
            case '+': {
                cin >> id;
                if (q1.size() <= q2.size()) {
                    q2.push_back(id);
                    q1.push(q2.front());
                    q2.pop_front();
                } else {
                    q2.push_back(id);
                }
                break;
            }
            case '*': {
                cin >> id;
                if (q1.size() >= q2.size()+1) {
                    q2.push_front(id);
                } else {
                    q1.push(id);
                }
                break;
            }
            case '-': {
                ans.push_back(q1.front());
                q1.pop();
                if (q2.size() > q1.size()) {
                    q1.push(q2.front());
                    q2.pop_front();
                }
                break;
            }
        }
    }
    for (const auto& e : ans) {
        cout << e << '\n';
    }
    return 0;
}
