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
	int sum = std::accumulate(a.begin(), a.end(), 0);

	for (int i = 0; 2*i < n; i++) {
		sum += a[n-1-i] - a[i];
	}

	cout << sum << endl;

	return 0;
}