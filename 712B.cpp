#include <bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin >> s;

  int x = 0, y = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'L') {
      x--;
    } else if (s[i] == 'R') {
      x++;
    } else if (s[i] == 'U') {
      y--;
    } else {
      y++;
    }
  }

  if ((x + y) % 2 != 0) {
    cout << -1 << endl;
  } else {
    cout << abs(x) / 2 + abs(y) / 2 + (x % 2 != 0 || y % 2 != 0) << endl;
  }
  return 0;
}
