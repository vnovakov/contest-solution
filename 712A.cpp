#include <bits/stdc++.h>

using namespace std;

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

  vector<int> b(n);
  b[n - 1] = a[n - 1];

  for (int i = n - 2; i >= 0; i--) {
    b[i] = a[i] + a[i + 1];
  }

  for (int i = 0; i < n; i++) {
    cout << b[i];
    if (i < n - 1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }
  return 0;
}
