#include <bits/stdc++.h>

using namespace std;

int big_table[8000005];
const int OFFSET = 4000000;

int big_table_trial[8000005];

int main()
{
    int n, k, p;

    cin >> n >> k >> p;

    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++) {
        int a_i;
        cin >> a_i;
        a.push_back(a_i);
    }

    for (int j = 0; j < k; j++) {
        int b_j;
        cin >> b_j;
        b.push_back(b_j);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> person_done(a.size(), 0);
    vector<int> key_used(b.size(), 0);

    int total_time = 0;
    int total_done = 0;

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > p) {
            break;
        }

        while (j < k && key_used[j]) {
            j++;
        }
        
        if (j >= k || b[j] > p) {
            break;
        }

        total_time += abs(a[i] - b[j]) + abs(b[j] - p);
        person_done[i] = 1;
        key_used[j] = 1;
        total_done++;
    }

    cout << total_done << endl;
    cout << total_time << endl;

    return 0;
}
