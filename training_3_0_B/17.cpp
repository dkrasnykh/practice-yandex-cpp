//https://contest.yandex.ru/contest/45468/problems/17/
#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

int main() {
    deque<int> player1;
    deque<int> player2;
    int n;
    for (int i = 0; i < 5; i++) {
        cin >> n;
        player1.push_back(n);
    }

    for (int i = 0; i < 5; i++) {
        cin >> n;
        player2.push_back(n);
    }

    int cnt = 0;
    while (true) {
        if (player1.empty()) {
            cout << "second " << cnt;
            break;
        }
        if (player2.empty()) {
            cout << "first " << cnt;
            break;
        }
        if (cnt == 1000000) {
            cout << "botva";
            break;
        }
        int v1 = player1.front();
        player1.pop_front();
        int v2 = player2.front();
        player2.pop_front();

        if (v1 == 0 && v2 == 9) {
            player1.push_back(v1);
            player1.push_back(v2);
        } else if (v1 == 9 && v2 == 0) {
            player2.push_back(v1);
            player2.push_back(v2);
        } else if (v1 > v2) {
            player1.push_back(v1);
            player1.push_back(v2);
        } else if (v2 > v1) {
            player2.push_back(v1);
            player2.push_back(v2);
        }
        cnt++;
    }
}
