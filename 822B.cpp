#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
  string s, t;

  cin >> n >> m;
  cin >> s >> t;

  int best = n + 1;
  vector<int> index_best;

  for (int i = 0; i + n <= m; i++) {
    // shift by i

    int diff = 0;
    vector<int> index_diff;

    for (int j = 0; j < n; j++) {
      if (s[j] != t[i+j]) {
        diff++;
        index_diff.push_back(j + 1);
      }
    }

    if (diff < best) {
      best = diff;
      index_best = index_diff;
    }

  }

  assert(best <= n);

  cout << best << endl;

  for (int i = 0; i < index_best.size(); i++) {
    cout << index_best[i];
    if (i + 1 == index_best.size()) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
