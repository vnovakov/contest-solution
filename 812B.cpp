#include <bits/stdc++.h>

using namespace std;

const long long inf = (long long) 1e18;
const int infint = (int) 2e9;

int main() {
  int m, b;
  scanf("%d %d", &m, &b);

  // y = -x/m + b

  long long ans = 0;
  for (int x = 0; x <= m*b; x++) {
      int y = 0;
      if (x % m == 0) {
        y = max(y, -x/m + b);
      } else {
        y = max(y, -x/m + b - 1);
      }
      ans = max(ans, (long long)(x + y)*(x+1)*(y+1)/2);
  }

  cout << (ans == inf ? -1LL : ans) << endl;
  return 0;
}
