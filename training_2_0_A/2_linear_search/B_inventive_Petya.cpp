#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string s) {
	string ans;
	int size = static_cast<int>(s.size());
	for (int i = size-1; i >= 0; --i) {
		ans.push_back(s[i]);
	}
	return ans;
}

string match(string x, string z) {
	int size_z = static_cast<int>(z.size());
	int size_x = static_cast<int>(x.size());

	string reverse_x = reverse(x);
	string reverse_z = reverse(z);

	int entry = reverse_z.find(reverse_x);
	string reverse_tail;
	string reverse_head;
	if (entry >= 0 && entry < size_z) {
		reverse_tail = reverse_z.substr(0, entry);
		reverse_head = reverse_z.substr(entry + size_x);
		entry += size_x;

		while (true) {
			int p = reverse_head.find(reverse_x);
			if (p == 0) {
				reverse_head = reverse_head.substr(size_x);
				entry += size_x;
			} else if (p > 0 && p < static_cast<int>(reverse_head.size())) {
				entry += p;
				reverse_tail = reverse_z.substr(0, entry);
				reverse_head = reverse_z.substr(entry + size_x);
			} else if (static_cast<int>(reverse_head.size()) < size_x) {
				int size_head = static_cast<int>(reverse_head.size());
				if (reverse_x.substr(0, size_head) != reverse_head) {
					reverse_tail = reverse_z;
				}
				break;
			} else {
				reverse_tail = reverse_z;
				break;
			}
		}
		return reverse(reverse_tail);
	} else {
		for (int i = 0; i < size_x; ++i) {
			if (x[i] == z[0]) {
				string mm1 = z.substr(0, size_x - i);
				string mm2 = x.substr(i);
				if (mm1 == mm2) {
					return z.substr(mm1.size());
				}
			}
		}
	}
	return z;
}

int main() {
	string x, z;
	cin >> x >> z;
	cout << match(x, z);
	//cout<<match("kit", "kitkitkitkitart");
	//cout << match("kit", "itkitkitart");
	//cout << match("mama", "amamam");
	//cout << match("ttt", "ttttttttar");
	//cout << match("kit", "itar");
	//cout << match("DGDG", "akakak");
	return 0;
}
