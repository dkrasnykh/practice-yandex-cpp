#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<vector<int>> board(10);
	for (int i = 0; i < 10; ++i) {
		board[i].resize(10, 1);
	}
	int p = 0;

	int n;
	cin >> n;
	for (int k = 0; k < n; ++k) {
		int i, j;
		cin >> i >> j;
		board[i][j] = 0;
	}
	for (int i = 1; i < 9; ++i) {
		for (int j = 1; j < 9; ++j) {
			if (board[i][j] == 0) {
				p += board[i - 1][j] + board[i + 1][j] + board[i][j - 1] + board[i][j + 1];
			}
		}
	}
	cout << p;
	return 0;
}
