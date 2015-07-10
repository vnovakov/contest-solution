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
	int sum;
	cin >> sum;

	int p = n / 2;
	int q = n - p;
	set<pair<int, int> > p_sums;
	set<pair<int, int> > q_sums;

	for (int i = 0; i < (1 << p); i++) {
		bitset<20> m = bitset<20>(i);
		int partial_sum = 0;
		for (int j = 0; j < p; j++) {
			if (!m[j]) {
				continue;
			}
			partial_sum += a[j];
		}
		p_sums.insert(pair<int, int>(partial_sum, i));
	}

	for (int i = 0; i < (1 << q); i++) {
		bitset<20> m = bitset<20>(i);
		int partial_sum = 0;
		for (int j = 0; j < q; j++) {
			if (!m[j]) {
				continue;
			}
			partial_sum += a[p + j];
		}
		q_sums.insert(pair<int, int>(partial_sum, i));
	}

	set<pair<int, int> >::iterator p_index = p_sums.begin();
	set<pair<int, int> >::reverse_iterator q_index = q_sums.rbegin();
	
	while (p_index != p_sums.end() && q_index != q_sums.rend()) {
		int diff = p_index->first + q_index->first - sum;
		if (diff == 0) {
			break;
		} else if (diff > 0) {
			q_index++;
		} else {
			p_index++;
		}
	}

	string p_string = bitset<20>(p_index->second).to_string().substr(20 - p);
	string q_string = bitset<20>(q_index->second).to_string().substr(20 - q);
	std::reverse(p_string.begin(), p_string.end());
	std::reverse(q_string.begin(), q_string.end());

	cout << p_string << q_string << endl;

	return 0;
}