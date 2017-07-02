#include <bits/stdc++.h>

using namespace std;

const int MODULO = 1000000007;
const int BUFFER = 200000;

int main()
{
  int a, b, k, t;
  cin >> a >> b >> k >> t;

  vector<int> grid(2 * BUFFER + 1, 0);
  vector<int> new_grid(2 * BUFFER + 1, 0);

  grid[a - b + BUFFER] = 1;

  int range_begin = a - b;
  int range_end = a - b;

  for (int i = 0; i < t + t; i++) {
    range_begin -= k;
    range_end += k;

    for (int j = range_begin; j <= range_end; j++) {
      new_grid[j + BUFFER] = ((unsigned int)new_grid[j + BUFFER - 1] +
        grid[j + BUFFER + k] - grid[j + BUFFER - k - 1]) % MODULO;
    }

    for (int j = range_begin; j <= range_end; j++) {
      grid[j + BUFFER] = new_grid[j + BUFFER];
      new_grid[j + BUFFER] = 0;
    }
  }

  int total = 0;

  for (int j = 1; j <= range_end; j++) {
    total = ((unsigned int)total + grid[j + BUFFER]) % MODULO;
  }

  cout << total << endl;

  return 0;
}
