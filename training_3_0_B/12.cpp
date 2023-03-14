//https://contest.yandex.ru/contest/45468/problems/12/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> stack;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '{') {
            stack.push('{');
        } else if (s[i] == '[') {
            stack.push('[');
        } else if (s[i] == '(') {
            stack.push('(');
        } else if (s[i] == '}') {
            if (stack.size() > 0 && stack.top() == '{') {
                stack.pop();
            } else {
                cout << "no";
                return 0;
            }
        } else if (s[i] == ']') {
            if (stack.size() > 0 && stack.top() == '[') {
                stack.pop();
            } else {
                cout << "no";
                return 0;
            }
        } else if (s[i] == ')') {
            if (stack.size() > 0 && stack.top() == '(') {
                stack.pop();
            } else {
                cout << "no";
                return 0;
            }
        }
    }
    cout << ((stack.size() == 0) ? "yes" : "no");
}
