//https://contest.yandex.ru/contest/45469/problems/24/
#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int SECONDS_PER_HOUR = 3600;

bool comp(pair<int, int> first, pair<int, int> second) {
	return first.second < second.second;
}

int count(int start, int end, vector<pair<int, int>>& schedule) {
	vector<pair<int, int>> events;
	int size = static_cast<int>(schedule.size());
	for (int i = 0; i < size - 1; ++i) {
		int timestamp = schedule[i].first;
		int duration = schedule[i].second;
		int timestamp1 = schedule[i + 1].first;
		for (int j = timestamp; j < timestamp1; ++j) {
			if (start <= j && j + duration <= end) {
				events.push_back({ j, j + duration });
			}
		}
	}
	if (schedule[size - 1].first < end) {
		int timestamp = schedule[size - 1].first;
		int duration = schedule[size - 1].second;
		for (int i = timestamp; i < end; ++i) {
			if (start <= i && i + duration <= end) {
				events.push_back({ i, i + duration });
			}
		}
	}
	sort(events.begin(), events.end(), comp);
	int res = 0;
	int finish = -1;
	for (const auto& e : events) {
		if (finish <= e.first) {
			finish = e.second;
			++res;
		}
	}
	return res;
}


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> schedule;
	for (int i = 0; i < n; ++i) {
		int hh, mm, ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		int leadtime;
		cin >> leadtime;
		schedule.push_back({ SECONDS_PER_HOUR * hh + 60 * mm + ss, leadtime });
	}
	int start = SECONDS_PER_HOUR * 9;
	int end = SECONDS_PER_HOUR * 13;
	int cnt = count(start, end, schedule);
	start = SECONDS_PER_HOUR * 14;
	end = SECONDS_PER_HOUR * 18;
	cnt += count(start, end, schedule);
	cout << cnt;
	return 0;
}

