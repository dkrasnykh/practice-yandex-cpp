//https://contest.yandex.ru/contest/45469/problems/38/
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<vector<int>> maze;
vector<vector<int>> d;

int main() {
	int n, m;
	cin >> n >> m;
	maze = vector<vector<int>>(n);
	d = vector<vector<int>>(n);

	for (int i = 0; i < n; ++i) {
		maze[i].resize(m);
		d[i].resize(m, -1);

		for (int j = 0; j < m; ++j) {
			cin >> maze[i][j];
		}
	}

	d[0][0] = 0;
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, -1 });
	int ans = -1;
	while (!q.empty() && ans == -1) {
		auto p = q.front();
		q.pop();
		int x = get<0>(p);
		int y = get<1>(p);
		int direction = get<2>(p);
		int i, j;

		if (x > 0 && direction!=1) {
			i = x;
			while (true) {
				if (i == 0 || maze[i - 1][y] == 1) {
					break;
				}
				if (maze[i - 1][y] == 2) {
					ans = d[x][y] + 1;
					break;
				}
				--i;
			}

			if (d[i][y] == -1) {
				d[i][y] = d[x][y] + 1;
				q.push({ i, y, 4 });
			}
		}
		if (y > 0 && ans == -1 && direction!=3) {
			j = y;
			while (true) {
				if (j == 0 || maze[x][j - 1] == 1) {
					break;
				}
				if (maze[x][j - 1] == 2) {
					ans = d[x][y] + 1;
					break;
				}
				--j;
			}
			if (d[x][j] == -1) {
				d[x][j] = d[x][y] + 1;
				q.push({ x, j, 2 });
			}
		}
		if (x < n - 1 && ans == -1 && direction!=4) {
			i = x;
			while (true) {
				if (i == n - 1 || maze[i + 1][y] == 1) {
					break;
				}
				if (maze[i + 1][y] == 2) {
					ans = d[x][y] + 1;
					break;
				}
				++i;
			}
			if (d[i][y] == -1) {
				d[i][y] = d[x][y] + 1;
				q.push({ i, y, 1 });
			}
		}
		if (y < m - 1 && ans == -1 && direction!=2) {
			j = y;
			while (true) {
				if (j == m - 1 || maze[x][j + 1] == 1) {
					break;
				}
				if (maze[x][j + 1] == 2) {
					ans = d[x][y] + 1;
					break;
				}
				++j;
			}
			if (d[x][j] == -1) {
				d[x][j] = d[x][y] + 1;
				q.push({ x, j, 3 });
			}
		}

	}
	cout << ans;
	return 0;
}
