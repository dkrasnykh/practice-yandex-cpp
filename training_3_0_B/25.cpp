//https://contest.yandex.ru/contest/45468/problems/25/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> notused(n + 1, 10100);
    vector<int> used(n + 1);
    used[0] = 0;
    used[1] = 0;
    used[2] = a[2] - a[1];
    for (int i = 3; i < n; ++i) {
        used[i] = min(used[i - 1] + a[i] - a[i - 1], notused[i - 1] + a[i] - a[i - 1]);
        notused[i] = used[i - 1];
    }
    int ans = a[n] - a[n - 1] + min(used[n - 1], notused[n - 1]);
    cout << ans;
	return 0;
}

