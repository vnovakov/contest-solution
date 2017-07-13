#include <bits/stdc++.h>

using namespace std;

int main()
{
  string a, b, c;
  cin >> a >> b >> c;

  map<char, char> apply;

  for (int i = 0; i < a.length(); i++) {
    apply[a[i]] = b[i];
  }

  for (int i = 0; i < c.length(); i++) {
    char p = c[i];
    if (p >= '0' && p <= '9') {
      cout << p;
    } else if (p >= 'A' && p <= 'Z') {
      cout << (char)('A' - 'a' + apply[p - 'A' + 'a']);
    } else {
      cout << apply[p];
    }

  }
  cout << endl;

  return 0;
}
