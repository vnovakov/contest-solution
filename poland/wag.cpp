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

	sort(a.begin(), a.end());
	int total_sum = std::accumulate(a.begin(), a.end(), 0);

	int* grid = new int[2*total_sum + 1];
	int* new_grid = new int[2*total_sum + 1];

	for (int i = 0; i <= 2*total_sum; i++) {
		grid[i] = -1;
		new_grid[i] = -1;
	}

	int* it = grid + total_sum;
	int* new_it = new_grid + total_sum;
	
	it[0] = 0;
	new_it[0] = 0;
	int sum = 0;

	bitset<1000>* neg_bits = new bitset<1000>[2*total_sum + 1];
	bitset<1000>* neg_bits_it = neg_bits + total_sum;
	bitset<1000>* bits = new bitset<1000>[2*total_sum + 1];
	bitset<1000>* bits_it = bits + total_sum;

	//int** neg_bits = new (int *)[2*total_sum + 1];

	for (int i = 0; i < n; i++) {
		int item = a[i];
		int pot = 0;
		//int neg_shift = total_sum - item;
		//int shift = total_sum + item;

		for (int j = -sum; j <= sum; j++) {
			pot = it[j];
			if (pot == -1) {
				continue;
			}
		
			if (new_it[j - item] < pot) {
				new_it[j - item] = pot;

				//neg_bits[i].set(j + neg_shift);
				//neg_bits_it[j - item].set(i);
			}

			pot += item;
			if (new_it[j + item] < pot) {
				new_it[j + item] = pot;
				//bits[i].set(j + shift);
				//bits_it[j + item].set(i);
			}
			
		}
		
		sum += item;
		for (int j = -sum; j <= sum; j++) {
			it[j] = new_it[j];
		}
	}

	return 0;

	if (it[0] <= 0) {
		cout << "0 0" << endl << endl << endl;
	} else {
		vector<int> set_found;
		vector<int> neg_set_found;

		int target = 0;
		
		for (int i = n - 1; i >= 0; i--) {
			if (bits_it[target].test(i)) {
				target -= a[i];
				set_found.push_back(a[i]);
			} else if (neg_bits_it[target].test(i)) {
				target += a[i];
				neg_set_found.push_back(a[i]);
			}
		}

		cout << set_found.size() << " " << neg_set_found.size() << endl;

		for (int i = 0; i < set_found.size(); i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << set_found[i];
		}
		cout << endl;

		for (int i = 0; i < neg_set_found.size(); i++) {
			if (i > 0) {
				cout << " ";
			}
			cout << neg_set_found[i];
		}
		cout << endl;
	}
	return 0;
}
