//https://contest.yandex.ru/contest/45469/problems/15/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <regex>
#include <iterator>
#include <fstream>

using namespace std;

bool contains(int p, int size) {
    return p >= 0 && p < size;
}

pair<int, string> diff(string s1, string s2) {
    if (s1.size() + 1 == s2.size()) {
        int cnt = 0;
        int p = -1;
        if (s1[0] != s2[0]) {
            ++cnt;
            p = 0;
        }
        for (size_t i = 1; i < s1.size(); ++i) {
            if (s1[i] != s2[i + 1]) {
                ++cnt;
                p = i;
            }
        }
        if (cnt == 0 && s2[1] != '/') {
            s2[1] = '/';
            return { 2, s2 };
        }
        else if (cnt == 0) {
            return { -1, "" };
        }
        else if (cnt == 1 && s2[1] == '/') {
            if (p != 0 && p != s1.size() - 1 && s2[p + 1] != '<' && s2[p + 1] != '>') {
                if (s2[p + 1] == '/') {
                    s2[p + 1] = s1[p];
                    return { 2, s2 };
                }
                else {
                    s1[p] = s2[p + 1];
                    return { 1, s1 };
                }
            }
            else if (p != 0 && p != s1.size() - 1 && (s2[p + 1] == '<' || s2[p + 1] == '>')) {
                s2[p + 1] = s1[p];
                return { 2, s2 };
            }
            else if (p == 0 && s1[0] != '<') {
                s1[0] = '<';
                return { 1, s1 };
            }
            else if (p == 0 && s1[0] == '<') {
                s2[0] = '<';
                return { 2, s2 };
            }
            else if (p == s1.size() - 1 && s1[p] != '>') {
                s1[p] = '>';
                return { 1, s1 };
            }
            else if (p == s1.size() - 1 && s1[p] == '>') {
                s2[p + 1] = '>';
                return { 2, s2 };
            }
        }
        else {
            return { -2, "" };
        }

    }
    else {
        return { -2, "" };
    }
}

void divide(string s, vector<string>& subs) {
    string s1 = s;
    while (!s1.empty()) {
        int size = s1.size();

        int p1 = s1.find("<", 1);
        int p2 = s1.find(">");
        int p3 = s1.find(">", p2 + 1);

        if (!contains(p1, size) && !contains(p2, size)) {
            subs.push_back(s1);
            s1.clear();
        }
        else if (!contains(p2, size)) {
            subs.push_back(s1);
            s1.clear();
        }
        else if (contains(p1, size) && contains(p2, size) && contains(p3, size) && p3 < p1 || !contains(p1, size) && contains(p2, size) && contains(p3, size)) {
            int p4 = s1.find(">", p3 + 1);
            if (s1[p2 + 2] == '/') {
                subs.push_back(s1.substr(0, p2 + 1));
                subs.push_back(s1.substr(p2 + 1, p3 + 1));
                s1 = s1.substr(p3 + 1);
            }
            else if (contains(p4, size) && p4 < p1) {
                subs.push_back(s1.substr(0, p2 + 1));
                s1 = s1.substr(p2 + 1);
            }
            else {
                subs.push_back(s1.substr(0, p3 + 1));
                s1 = s1.substr(p3 + 1);
            }
        }
        else if (contains(p1, size) && contains(p2, size) && p1 < p2) {
            int p4 = s1.find("<", p1 + 1);
            if (s1[p1 + 1] == '/') {
                subs.push_back(s1.substr(0, p1));
                subs.push_back(s1.substr(p1, p2 + 1));
                s1 = s1.substr(p2 + 1);
            } else if (contains(p4, size) && p4<p2){
                subs.push_back(s1.substr(0, p1 + 1));
                s1 = s1.substr(p1 + 1);

            } else  {
                subs.push_back(s1.substr(0, p2 + 1));
                s1 = s1.substr(p2 + 1);
            }

        }
        else {
            subs.push_back(s1.substr(0, p2 + 1));
            s1 = s1.substr(p2 + 1);
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    vector<string> subs;
    divide(s, subs);
    int size = static_cast<int>(subs.size());
    stack<pair<string, int>> st;
    for (int i = 0; i < size; ++i) {
        if (!st.empty()) {
            auto cur = st.top();
            auto d = diff(cur.first, subs[i]);
            if (d.first == 1) {
                subs[cur.second] = d.second;
                break;
            }
            else if (d.first == 2) {
                subs[i] = d.second;
                break;
            }
            else if (d.first == -1) {
                st.pop();
            }
            else {
                st.push({ subs[i], i });
            }
        }
        else {
            st.push({ subs[i], i });
        }
    }
    for (const auto& e : subs) {
        cout << e;
    }

    return 0;
}
