#include <iostream>
#include <cmath>
#include <tuple>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int unasked = n;
	int yes = 0;
	vector<int> asked(n+1, 0);
	vector<string> ans;
	string s;
	while (getline(cin, s)) {
		if (s.empty()) {
			continue;
		}
		if (s=="HELP") {
			/*
			выводить все, которые 2 -> если таких элементов нет, то выводить те, которые 0
			*/
			string a;
			int check = (yes > 0) ? 2 : 0;
			for (size_t i = 1; i <= n; ++i) {
				if (asked[i]==2) {
					a.append(to_string(i));
					a.append(" ");
				}
			}
			if (a.empty()) {
				for (size_t i = 1; i <= n; ++i) {
					if (asked[i] == 0) {
						a.append(to_string(i));
						a.append(" ");
					}
				}

			}
			ans.push_back(a);
			break;
		}
		vector<int> ask;
		stringstream ss(s);
		int v;
		while (ss>>v) {
			if (asked[v]==0 || asked[v]==2) {
				ask.push_back(v);
			}
		}
		if (ask.size()<=unasked/2) {
			ans.push_back("NO");
			for (const auto& e : ask) {
				unasked--;
				asked[e] = 1;
			}

		} else {
			ans.push_back("YES");
			for (const auto& e : ask) {
				yes++;
				//unasked--;
				asked[e] = 2;
			}
		}
	}

	for (const auto& e : ans) {
		cout << e << '\n';
	}
	return 0;
}
