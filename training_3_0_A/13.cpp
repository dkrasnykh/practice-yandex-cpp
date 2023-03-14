//https://contest.yandex.ru/contest/45469/problems/13/
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    string postfix;
    stack<char> st;
    int size = static_cast<int>(s.size());
    for (int i = 0; i < size; ++i) {
        if (s[i] == '1' || s[i] == '0') {
            postfix.push_back(s[i]);
        } else if (s[i]=='!') {
            while (!st.empty() && st.top()=='!') {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        } else if (s[i] == '&') {
            while (!st.empty() && (st.top() == '!' || st.top() == '&')) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        } else if (s[i] == '|' || s[i] == '^') {
            while (!st.empty() && (st.top() == '!' || st.top() == '&' || st.top() == '|' || st.top()=='^')) {
                postfix.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        } else if (s[i]=='(') {
            st.push(s[i]);
        } else if (s[i]==')') {
            while (!st.empty() && st.top()!='(') {
                postfix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
    }
    while (!st.empty()) {
        postfix.push_back(st.top());
        st.pop();
    }

    stack<int> terms;
    for (size_t i = 0; i != postfix.size(); ++i) {
        if (postfix[i]=='!') {
            int t1 = terms.top();
            terms.pop();
            terms.push((t1==0?1:0));
        } else if (postfix[i] == '&') {
            int t1 = terms.top();
            terms.pop();
            int t2 = terms.top();
            terms.pop();
            terms.push(t1&t2);
        } else if (postfix[i] == '|') {
            int t1 = terms.top();
            terms.pop();
            int t2 = terms.top();
            terms.pop();
            terms.push(t2|t1);
        } else if (postfix[i] == '^') {
            int t1 = terms.top();
            terms.pop();
            int t2 = terms.top();
            terms.pop();
            terms.push(t1^t2);
        } else {
            terms.push(postfix[i]-48);
        }
    }
    cout << terms.top() << '\n';
    return 0;
}

