//https://contest.yandex.ru/contest/45469/problems/12/
#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

bool issign(char c) {
    return (c == '+' || c == '-' || c == '*' || c=='(' || c==')');
}

bool isdigit(char c) {
    return c >= '0' && c <= '9';
}

bool isnumber(string s) {
    if ((s[0] == '-' && s.size() > 1) || isdigit(s[0])) {
        return true;
    }
    return false;
}
//
bool validation(string s, vector<string>& subs) {
    int size = static_cast<int>(s.size());
    int balance = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i] != ' ' && !isdigit(s[i]) && !issign(s[i])) {
            return false;
        }
        if (s[i] == '(') {
            ++balance;
        }
        if (s[i] == ')') {
            --balance;
        }
        if (balance < 0) {
            return false;
        }
    }
    if (balance > 0) {
        return false;
    }

    int lenght = 0;
    for (int i = 0; i < size; ++i) {
        if (s[i] == ' ' && lenght > 0) {
            string word = s.substr(i - lenght, lenght);
            subs.push_back(word);
            lenght = 0;
        } else if (i == 0 && s[i] == '-') {
            lenght = 1;
        } else if (i > 0 && s[i] == '-' && (s[i - 1] == '(' || s[i - 1] == '*') && lenght>0) {
            string word = s.substr(i - lenght, lenght);
            subs.push_back(word);
            lenght = 1;
        } else if (issign(s[i]) && lenght > 0) {
            string word = s.substr(i - lenght, lenght);
            subs.push_back(word);
            string word2 = { s[i] };
            subs.push_back(word2);
            lenght = 0;
        } else if (i > 0 && isdigit(s[i]) && !isdigit(s[i - 1]) && lenght > 0  && !(s[i-1]=='-' && i==1) && !(i - 2 >= 0 && isdigit(s[i]) && (s[i - 1] == '-') && (s[i - 2] == '(' || s[i - 2] == '*'))) {
            string word = s.substr(i - lenght, lenght);
            subs.push_back(word);
            lenght = 1;
        } else if (s[i]!=' ') {
            ++lenght;
        }
    }
    if (lenght > 0) {
        subs.push_back(s.substr(size - lenght, lenght));
    }

    size = static_cast<int>(subs.size());
    if (subs[0] == "*" || subs[0] == "+") {
        return false;
    }
    if (subs[size-1]=="*" || subs[size-1]=="+" || subs[size-1]=="-") {
        return false;
    }
    for (int i = 1; i < size - 1; ++i) {
        if (subs[i] == "*" && !isnumber(subs[i - 1]) && subs[i-1]!=")") {
            return false;
        }
        if (subs[i] == "*" && !isnumber(subs[i+1]) && i + 1 == size - 1) {
            return false;
        }
        if ((subs[i]=="*" || subs[i]=="+" || subs[i]=="-") && (!isnumber(subs[i+1]) && subs[i+1]!="(")) {
            return false;
        }
        if (i==size-2 && subs[i]=="*" && (subs[i+1]=="+" || subs[i+1]=="-") && !isnumber(subs[i+2])) {
            return false;
        }
        if (subs[i]=="+" && subs[i-1]=="+") {
            return false;
        }
        if ((subs[i] == "+" || subs[i] == "-") && !isnumber(subs[i+1]) && subs[i+1]!="(") {
            return false;
        }
        if (isnumber(subs[i]) && isnumber(subs[i-1]) || isnumber(subs[i]) && isnumber(subs[i+1])) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);
    vector<string> subs;
    if (!validation(s, subs)) {
        cout << "WRONG";
        return 0;
    }
    stack<string> build;
    vector<string> postfix;
    int size = static_cast<int>(subs.size());
    for (int i = 0; i < size; ++i) {
        if (isnumber(subs[i])) {
            postfix.push_back(subs[i]);
        }
        if (subs[i]=="+" || subs[i]=="-") {
            while (!build.empty() && (build.top()=="+" || build.top()=="-" || build.top()=="*")) {
                postfix.push_back(build.top());
                build.pop();
            }
            build.push(subs[i]);
        }

        if (subs[i]=="*") {
            while (!build.empty() && (build.top() == "*")) {
                postfix.push_back(build.top());
                build.pop();
            }
            build.push(subs[i]);
        }

        if (subs[i]=="(") {
            build.push(subs[i]);
        }

        if (subs[i]==")") {
            while (!build.empty() && build.top()!="(") {
                postfix.push_back(build.top());
                build.pop();
            }
            build.pop();
        }
    }
    while (!build.empty()) {
        postfix.push_back(build.top());
        build.pop();
    }
    stack<long long> terms;
    for (size_t i = 0; i != postfix.size(); ++i) {
        if (postfix[i] == "+") {
            long long t1 = terms.top();
            terms.pop();
            long long t2 = terms.top();
            terms.pop();
            terms.push(t1 + t2);
        } else if (postfix[i] == "-") {
            long long t1 = terms.top();
            terms.pop();
            long long t2 = terms.top();
            terms.pop();
            terms.push(t2 - t1);
        } else if (postfix[i] == "*") {
            long long t1 = terms.top();
            terms.pop();
            long long t2 = terms.top();
            terms.pop();
            terms.push(t2 * t1);
        } else {
            terms.push(stoll(postfix[i]));
        }
    }
    cout << terms.top() << '\n';
    return 0;
}

