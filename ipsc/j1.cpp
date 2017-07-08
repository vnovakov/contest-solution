#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_cases = 0;

    cin >> test_cases;

    while (test_cases--) {
      int n;
      cin >> n;
      cout << n - 1 << endl;
      for (int i = 0; i < n - 1; i++) {
        cout << 0 << " " << i << endl;
      }
    }
    return 0;
}