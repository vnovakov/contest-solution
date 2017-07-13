#include <bits/stdc++.h>

using namespace std;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

int main()
{
  int n;
  vector<int> a;

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a_i;
    cin >> a_i;
    a.push_back(a_i);
  }

  int direction = 1;

  bool works = true;
  for (int i = 1; i < n; i++) {
      int change = sgn(a[i] - a[i-1]);
      if (change > direction) {
          works = false;
      }
      direction = change;
  }
  if (works) {
      cout << "YES" << endl;
  } else {
      cout << "NO" << endl;
  }
  return 0;
}
