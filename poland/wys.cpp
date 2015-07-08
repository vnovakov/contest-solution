#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int item;
		cin >> item;
		a.push_back(item);
	}

	int sum = std::accumulate(a.begin(), a.end(), 0);
	int best = 0;

	int begin_pointer = 0;
	int end_pointer = 0;

	int cumulative_sum = 0;
	for (int begin_pointer = 0, end_pointer = 0; begin_pointer < n; begin_pointer++) {
		while (2*(cumulative_sum + a[end_pointer % n]) <= sum) {
			cumulative_sum += a[end_pointer % n];
			if (best < cumulative_sum) {
				best = cumulative_sum;
			}
			end_pointer++;
		}

		cumulative_sum -= a[begin_pointer];
	}

	cout << best << endl;

	return 0;
}