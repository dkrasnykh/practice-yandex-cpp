//https://contest.yandex.ru/contest/45468/problems/16/
#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

int main() {
    queue<string> q;
    vector<string> ans;
    while (true) {
        string s;
        cin >> s;
        if (s.compare("push") == 0) {
            cin >> s;
            q.push(s);
            ans.push_back("ok");
        } else if (s.compare("pop") == 0) {
            if (!q.empty()) {
                s = q.front();
                ans.push_back(s);
                q.pop();
            } else {
                ans.push_back("error");
            }
        } else if (s.compare("front") == 0) {
            if (!q.empty()) {
                ans.push_back(q.front());
            }
            else {
                ans.push_back("error");
            }
        } else if (s.compare("size") == 0) {
            std::ostringstream ostr;
            ostr << q.size();
            string res = ostr.str();
            ans.push_back(res);
        } else if (s.compare("clear") == 0) {
            while (!q.empty()) {
                q.pop();
            }
            ans.push_back("ok");
        } else if (s.compare("exit") == 0) {
            ans.push_back("bye");
            break;
        }
    }
    for (size_t i = 0; i != ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}
