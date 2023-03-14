//https://contest.yandex.ru/contest/45469/problems/4/
#include <iostream>

using namespace std;

pair<int, int> getposition(int n2) {
	if (n2 % 2 == 0) {
		return { n2/2, 2 };
	} else {
		return { n2/2+1, 1 };
	}
}

int main() {
	int n, k, table, pos;
	cin >> n >> k >> table >> pos;
	int n1 = (table - 1) * 2 + pos;

	int nbehind = n1 + k;
	auto behind = getposition(nbehind);
	int nahead = n1 - k;
	auto ahead = getposition(nahead);

	if (nbehind > n && nahead <= 0) {
		cout << -1 << '\n';
	} else if (nbehind > n) {
		cout << ahead.first << ' ' << ahead.second << '\n';
	} else if (nahead <=0) {
		cout << behind.first << ' ' << behind.second << '\n';
	} else if (behind.first-table == table - ahead.first) {
		cout << behind.first << ' ' << behind.second << '\n';
	} else if (table - ahead.first < behind.first - table) {
		cout << ahead.first << ' ' << ahead.second << '\n';
	} else {
		cout << behind.first << ' ' << behind.second << '\n';
	}
	return 0;
}
