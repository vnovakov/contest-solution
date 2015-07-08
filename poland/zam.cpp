#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, e, p, b;
	cin >> n >> m >> e >> p >> b;

	vector<int> values(1, 0);
	for (int i = 0; i < n; i++) {
		int item;
		cin >> item;
		values.push_back(item);
	}

	vector<pair<int, int> > corridors;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		corridors.push_back(pair<int, int>(x, y));
	}

	vector<vector<int> > parent(b, vector<int>(n+1, 0));
	parent[0][e] = -1;

	for (int i = 0; i < b; i++) {
		for (int j = 0; j < m; j++) {
			int x = corridors[j].first;
			int y = corridors[j].second;
			if (parent[i][x] != 0 && i+values[x] < b && parent[i+values[x]][y] == 0) {
				parent[i+values[x]][y] = x; 
			}
			if (parent[i][y] != 0 && i+values[y] < b && parent[i+values[y]][x] == 0) {
				parent[i+values[y]][x] = y; 
			}
		}
	}

	list<int> path;
	path.push_back(p);
	int balance = b - values[p];
	while (parent[balance][path.front()] != -1) {
		path.push_front(parent[balance][path.front()]);
		balance -= values[path.front()];
	}

	for (std::list<int>::iterator it = path.begin(); it != path.end(); it++) {
		if (it != path.begin()) {
			cout << " ";
		}
		cout << *it;
	}
	cout << endl;


	return 0;
}