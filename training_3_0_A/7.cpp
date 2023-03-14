//https://contest.yandex.ru/contest/45469/problems/7/
#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int SECONDS_PER_DAY = 86400;
const int SECONDS_PER_HOUR = 3600;

int seconds(int hh, int mm, int ss) {
	return hh * 3600 + mm * 60 + ss;
}

int diff(int a, int c) {
	return (c < a) ? (SECONDS_PER_DAY - a + c) : (c - a);
}

int main() {
	int hh, mm, ss;
	scanf("%d:%d:%d", &hh, &mm, &ss);
	int a = seconds(hh, mm, ss);
	scanf("%d:%d:%d", &hh, &mm, &ss);
	int b = seconds(hh, mm, ss);
	scanf("%d:%d:%d", &hh, &mm, &ss);
	int c = seconds(hh, mm, ss);

	int exact = (b + static_cast<int>(static_cast<long double>(diff(a, c)) / 2 + 0.5)) % SECONDS_PER_DAY;

	printf("%02d:%02d:%02d", exact / SECONDS_PER_HOUR, (exact % SECONDS_PER_HOUR) / 60, (exact % SECONDS_PER_HOUR) % 60);

	return 0;
}
