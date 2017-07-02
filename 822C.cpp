#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, x;
  cin >> n >> x;

  vector<pair<int, pair<int, int> > > voucher;
  vector<pair<int, pair<int, int> > > voucher_rev;

  vector<int> best_at_duration(x+1, -1);

  for (int i = 0; i < n; i++) {
    int s, e, c;
    cin >> s >> e >> c;
    voucher.push_back(pair<int, pair<int, int> >(s, pair<int, int>(e, c)));
    voucher_rev.push_back(pair<int, pair<int, int> >(e, pair<int, int>(s, c)));

  }

  sort(voucher.begin(), voucher.end());
  sort(voucher_rev.begin(), voucher_rev.end());

  int j = 0;
  int best_total = -1;

  for (int i = 0; i < n; i++) {
    // second trip begins at voucher[i].first
    while (j < n && voucher_rev[j].first < voucher[i].first) {
      int cost = voucher_rev[j].second.second;
      int duration = voucher_rev[j].first - voucher_rev[j].second.first + 1;
      if (duration <= x &&
        (best_at_duration[duration] == -1 || best_at_duration[duration] > cost))
      {
        best_at_duration[duration] = cost;
      }
      j++;
    }

    int duration = voucher[i].second.first - voucher[i].first + 1;
    int cost = voucher[i].second.second;

    if (duration <= x) {
      if (best_at_duration[x - duration] != -1 &&
        (best_total == -1 || best_at_duration[x - duration] + cost < best_total)) {
          best_total = best_at_duration[x - duration] + cost;
        }
    }

  }

  cout << best_total << endl;

  return 0;
}
