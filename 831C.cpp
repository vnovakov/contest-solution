#include <bits/stdc++.h>

using namespace std;

int big_table[8000005];
const int OFFSET = 4000000;

int big_table_trial[8000005];

int main()
{
    int k, n;

    cin >> k >> n;

    vector<int> a;
    vector<int> b;

    for (int t = -OFFSET; t <= OFFSET; t++)
    {
        big_table_trial[t + OFFSET] = 0;
    }

    for (int i = 0; i < k; i++)
    {
        int a_i;
        cin >> a_i;
        a.push_back(a_i);
    }

    for (int j = 0; j < n; j++)
    {
        int b_j;
        cin >> b_j;
        b.push_back(b_j);
    }

    int count = 0;

    // let's try judge i as having the first score
    int partial_sum = a[0];
    for (int i = 0; i < k; i++)
    {
        // trial is the score before any judges go
        int trial = b[0] - partial_sum;

        if (big_table_trial[trial + OFFSET] == 0)
        {
            big_table_trial[trial + OFFSET] = 1;
            for (int j = 0; j < n; j++)
            {
                big_table[OFFSET + b[j]] = 0;
            }

            int trial_partial_sum = 0;
            for (int m = 0; m < k; m++)
            {
                trial_partial_sum += a[m];
                big_table[OFFSET + trial + trial_partial_sum] = 1;
            }
            bool works = true;

            for (int j = 0; j < n; j++)
            {
                if (big_table[OFFSET + b[j]] == 0)
                {
                    works = false;
                    break;
                }
            }

            if (works)
            {
                count++;
            }
        }
        if (i + 1 < k)
        {
            partial_sum += a[i + 1];
        }
    }

    cout << count << endl;

    return 0;
}
