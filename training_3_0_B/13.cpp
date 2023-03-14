//https://contest.yandex.ru/contest/45468/problems/13/
#include <iostream>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

int main() {
    string s;
    getline(cin, s);
    int pos = s.length();
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] != ' ') {
            pos = i + 1;
            break;
        }
    }
    s = s.substr(0, pos);
    vector<string> words;
    int lenght = 0;
    for (size_t i = 0; i != s.length(); ++i) {
        if (s[i] == ' ' && lenght > 0) {
            string word = s.substr(i - lenght, lenght);
            words.push_back(word);
            lenght = 0;
        } else {
            lenght++;
        }
    }
    if (lenght > 0) {
        words.push_back(s.substr(s.length() - lenght, lenght));
    }

    stack<long long> terms;
    for (size_t i = 0; i != words.size(); ++i) {
        if (words[i] == "+") {
            long long t1 = terms.top();
            terms.pop();
            long long t2 = terms.top();
            terms.pop();
            terms.push(t1 + t2);
        } else if (words[i] == "-") {
            long long t1 = terms.top();
            terms.pop();
            long long t2 = terms.top();
            terms.pop();
            terms.push(t2 - t1);
        } else if (words[i] == "*") {
            long long t1 = terms.top();
            terms.pop();
            long long t2 = terms.top();
            terms.pop();
            terms.push(t2 * t1);
        } else {
            terms.push(stoll(words[i]));
        }
    }
    cout << terms.top() << '\n';
	return 0;
}


