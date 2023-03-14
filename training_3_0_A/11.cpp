//https://contest.yandex.ru/contest/45469/problems/11/
#include <iostream>
#include <vector>
#include <stack>
#include <limits>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

bool is_equal(double x, double y) {
    return fabs(x - y) < std::numeric_limits<double>::epsilon();
}

int main() {
    int n;
    cin >> n;
    vector<vector<double>> test(n);
    vector<vector<double>> target(n);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        test[i].resize(k);
        target[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> test[i][j];
            target[i][j] = test[i][j];
        }
        sort(target[i].begin(), target[i].end());
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int size = static_cast<int>(test[i].size());
        int next = 0;
        stack<double> stock;
        for (int j = 0; j < size; ++j) {
            if (is_equal(target[i][next], test[i][j])) {
                ++next;
                while (!stock.empty() && is_equal(stock.top(), target[i][next])) {
                    stock.pop();
                    ++next;
                }
            } else {
                stock.push(test[i][j]);
            }
        }
        ans.push_back(stock.empty());
    }
    for (const auto& e : ans) {
        cout << e << '\n';
    }
    return 0;
}
