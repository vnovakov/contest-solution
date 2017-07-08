#include <bits/stdc++.h>

using namespace std;

int main()
{
    int test_cases = 0;

    cin >> test_cases;

    while (test_cases--) {
        int r, c;
        cin >> r >> c;

        int ans = min(r, c) + (max(r, c) - min(r, c) + 1) / 2;

        cout << ans << endl;

        for (int i = 0; i < min(r, c); i++) {
            cout << i << " " << i << endl;
        }
        for (int i = min(r, c) + 1; i <= max(r, c); i += 2) {
            cout << min(r - 1, i) << " " << min(i, c - 1) << endl; 
        }
    }
    return 0;
}