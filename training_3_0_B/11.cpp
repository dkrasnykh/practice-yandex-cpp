//https://contest.yandex.ru/contest/45468/problems/11/
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    stack<string> stack;
    vector<string> ans;
    while (true) {
        string s, q;
        cin >> s;
        if (s.compare("push") == 0) {
            cin >> s;
            stack.push(s);
            ans.push_back("ok");
        } else if (s.compare("pop") == 0) {
            if (stack.size() == 0) {
                ans.push_back("error");
            }
            else {
                q = stack.top();
                ans.push_back(q);
                stack.pop();
            }
        } else if (s.compare("back") == 0) {
            if (stack.size() == 0) {
                ans.push_back("error");
            }
            else {
                ans.push_back(stack.top());
            }
        } else if (s.compare("size") == 0) {
            std::ostringstream ostr;
            ostr << stack.size();
            string res = ostr.str();
            ans.push_back(res);
        } else if (s.compare("clear") == 0) {
            while (stack.size() > 0) {
                stack.pop();
            }
            ans.push_back("ok");
        } else if (s.compare("exit") == 0) {
            ans.push_back("bye");
            break;
        }
    }
    for (const auto& e : ans) {
        cout << e << '\n';
    }
    return 0;
}
