#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <string>

using namespace std;

//https://contest.yandex.ru/contest/45469/problems/2/
int main() {
	int k;
	cin >> k;
	string s;
	cin >> s;
	unordered_map<char, vector<pair<int, int>>> freq(26);
	int size = static_cast<int>(s.size());
	char current = s[0];
	int first = 0;
	for (int i = 1; i < size; ++i) {
		if (s[i] != current) {
			freq[current].push_back({ first, i - 1 });
			current = s[i];
			first = i;
		}
	}
	freq[current].push_back({ first, size - 1 });

	int maxbeauty = 0;

	for (const auto& e : freq) {
		int k1 = k;
		int len = 0;
		int last = 0;
		int size1 = static_cast<int>(e.second.size());
		for (int i = 0; i < size1; ++i) {
			int d = 0;
			if (i==0 || len==0 && i>0 && i < size1-1) {
				d = 0;
			} else if (i == size1 - 1) {
				d = min(k1, size-len);
			} else if (last < size1) {
				d = e.second[last].first - e.second[last-1].second - 1;
			}
			while (last < size1 && d<=k1) {
				len += d;
				k1 -= d;
				len += e.second[last].second - e.second[last].first + 1;

				if (last < size1-1) {
					d = e.second[last + 1].first - e.second[last].second - 1;
				}
				++last;
			}

			int tail = k1;
			len += tail;

			maxbeauty = max(maxbeauty, len);

			len -= tail;
			len -= e.second[i].second - e.second[i].first + 1;
			if (i < size1-1 && len > 0) {
				len -= e.second[i + 1].first - e.second[i].second - 1;
				k1 += e.second[i + 1].first - e.second[i].second - 1;
			}
		}
	}
	cout << maxbeauty << '\n';
	return 0;
}
