//https://contest.yandex.ru/contest/45468/problems/18/
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

int main() {
    deque<string> d;
    vector<string> ans;
    while (true) {
        string s;
        cin >> s;
        string v;
        if (s.compare("push_front") == 0) {
            cin >> v;
            d.push_front(v);
            ans.push_back("ok");
        } else if (s.compare("push_back") == 0) {
            cin >> v;
            d.push_back(v);
            ans.push_back("ok");
        } else if (s.compare("pop_front") == 0) {
            if (d.empty()) {
                ans.push_back("error");
            } else {
                ans.push_back(d.front());
                d.pop_front();
            }
        } else if (s.compare("pop_back") == 0) {
            if (d.empty()) {
                ans.push_back("error");
            } else {
                ans.push_back(d.back());
                d.pop_back();
            }
        } else if (s.compare("front") == 0) {
            if (d.empty()) {
                ans.push_back("error");
            }
            else {
                ans.push_back(d.front());
            }
        } else if (s.compare("back") == 0) {
            if (d.empty()) {
                ans.push_back("error");
            }
            else {
                ans.push_back(d.back());
            }
        } else if (s.compare("size") == 0) {
            std::ostringstream ostr;
            ostr << d.size();
            ans.push_back(ostr.str());
        } else if (s.compare("clear") == 0) {
            d.clear();
            ans.push_back("ok");
        } else if (s.compare("exit") == 0) {
            ans.push_back("bye");
            break;
        }
    }
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}
