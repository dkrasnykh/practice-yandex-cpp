#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
	vector<tuple<int, int, int>> event;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int in, out;
		cin >> in >> out;
		if (out - in >= 5) {
			event.push_back({ in, -1, i });
			event.push_back({ out, 1, i });
		}
	}
	sort(event.begin(), event.end());

	vector<bool> condition1(n, false);

	int max_cnt = 0;
	int time1 = 0;
	int time2 = 0;

	int i_time5 = 0;

	int online1 = 0;

	for (int i = 0; i < static_cast<int>(event.size()); ++i) {
		int timestamp = get<0>(event[i]);
		int state = get<1>(event[i]);
		int id = get<2>(event[i]);

		int max_custom_cnt_j = 0;
		int max_time_j = -1;

		if (state == -1) {
			++online1;
			condition1[id] = true;

			int online2 = online1;
			int k = i;
			while (k < static_cast<int>(event.size()) && get<0>(event[k]) < timestamp + 5) {
				int state1 = get<1>(event[k]);
				int id1 = get<2>(event[k]);
				if (state1==1 && condition1[id1]) {
					--online2;
				}
				++k;
			}

			int onlineInInt = online2;

			if (onlineInInt > 0) {
				vector<bool> cond1(n, false);

				int online1_internal = 0;

				for (int j = i; j <= i_time5; ++j) {

					if (get<1>(event[j]) == -1 && condition1[get<2>(event[j])]==false) {
						cond1[get<2>(event[j])] = true;
						++online1_internal;
					}
					else if (get<1>(event[j]) == 1 && cond1[get<2>(event[j])]) {
						cond1[get<2>(event[j])] = false;
						--online1_internal;
					}
				}

				for (int j = i + 1; j < static_cast<int>(event.size()); ++j) {
					int timestamp_internal = max(timestamp + 5, get<0>(event[j]));
					int state_internal = get<1>(event[j]);
					int id_internal = get<2>(event[j]);

					if (state_internal == -1) {
						++online1_internal;
						cond1[id_internal] = true;
						int online2_internal = online1_internal;
						int h = j;

						while (h < static_cast<int>(event.size()) && (get<0>(event[h]) < (timestamp_internal + 5))) {
							int s1 = get<1>(event[h]);
							int i1 = get<2>(event[h]);
							if (s1==1 && cond1[i1]) {
								--online2_internal;
							}
							++h;
						}
						int current_cnt = online2_internal;
						if (max_custom_cnt_j < current_cnt) {
							max_custom_cnt_j = current_cnt;
							max_time_j = timestamp_internal;
						}
					}
					else if (state_internal == 1 && cond1[id_internal] == true) {
						cond1[id_internal] = false;
						--online1_internal;
					}
				}
			}
			if (onlineInInt + max_custom_cnt_j > max_cnt) {
				max_cnt = onlineInInt + max_custom_cnt_j;
				time1 = timestamp;
				time2 = max_time_j;
			}
		}
		else if (state == 1) {
			condition1[id] = false;
			--online1;
		}
	}
	if (max_cnt == 0) {
		cout << "0 1 6";
	}
	else {
		cout << max_cnt << ' ' << time1 << ' ' << ((time2 == -1 || time2 == 0) ? time1 + 6 : time2);
	}
	return 0;
}
