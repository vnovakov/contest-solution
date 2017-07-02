#include <bits/stdc++.h>

using namespace std;

int main()
{
  int large, small;
  cin >> large >> small;

  int count = 0;
  int a = small, b = small, c = small;

  while (a != large) {
    int new_c = b + c - 1;
    if (new_c > large) {
      new_c = large;
    }
    a = b;
    b = c;
    c = new_c;
    count++;
  }

  cout << count << endl;

  return 0;
}
