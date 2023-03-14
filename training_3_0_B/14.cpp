//https://contest.yandex.ru/contest/45468/problems/14/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> endway;
    vector<int> way1(n);
    for (int i = 0; i < n; ++i) {
        cin >> way1[i];
    }
    int next = 1;
    for (int i = 0; i < n; ++i) {
        if (way1[i] == next) {
            ++next;
            while (!endway.empty() && endway.top() == next) {
                endway.pop();
                ++next;
            }
        } else {
            endway.push(way1[i]);
        }
    }
    if (endway.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}
