#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t, l, r;
  int MODULO = 1000000007;

  long long result = 0;
  long long exponent = 1;

  cin >> t >> l  >> r;

  vector<int> prime_divisor(r + 1, 1);

  for (int i = 2; i <= r; i++) {
    if (prime_divisor[i] > 1) {
      continue;
    }
    for (int j = i; j <= r; j += i) {
      if (prime_divisor[j] > 1) {
        continue;
      }
      prime_divisor[j] = i;
    }
  }
  for (int i = l; i <= r; i++) {
    long long f_val = 0;

    int p = i;

    while (p != 1) {
      long long q = prime_divisor[p];
      p /= prime_divisor[p];
      q = (q * (q - 1) / 2) % MODULO;
      f_val = (f_val + q * p) % MODULO;
    }

    long long term = (exponent * f_val) % MODULO;
    result = (result + term) % MODULO;
    exponent = (exponent * t) % MODULO;
  }
  cout << result << endl;

  return 0;
}
