#include <bits/stdc++.h>

using namespace std;

long double calculate_log_multinomial(int p, vector<int> z, 
    bool &is_zero) {
    vector<long double> log_sum(p+1, 0);
    log_sum[0] = 0;
    is_zero = false;

    for (int i = 1; i <= p; i++) {
        log_sum[i] = log_sum[i-1] + log((long double)i);
    }

    long double log_answer = log_sum[p];

    for (int j = 0; j < z.size(); j++) {
        log_answer -= log_sum[z[j]];
        p -= z[j];
        if (p < 0) {
            is_zero = true;
            return 0;
        }
    }
    log_answer -= log_sum[p];

    return log_answer;
}

int main()
{ 
    int test_cases = 0;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        vector<int> emojis;
        int a, b, m;
        cin >> n >> a >> b >> m;

        //assert(m != 0);

        for (int i = 0; i < n; i++) {
            int e;
            cin >> e;
            emojis.push_back(e);
        }


        std::sort(emojis.begin(), emojis.end());
        vector<int> card;

        card.push_back(1);

        for (int i = 1; i < emojis.size(); i++)
        {
            if (emojis[i] == emojis[i - 1])
            {
                card.back()++;
            }
            else
            {
                card.push_back(1);
            }
        }

        bool is_zero;
        int sum =  std::accumulate(emojis.begin(), emojis.end(), 0);

        long double sum_multinomial = calculate_log_multinomial(
               sum, emojis, is_zero);

        long double numer = 0.0;
        long double denom = 0.0;
        bool anything = false;

        for (int d = 1; d <= m; d++) {
            long double prob = 0.0;
            long double cond_prob = 0.0;

            // Find cond_prob given d and emojis
            bool is_zero;

            vector<int> card;

            card.push_back(1);

            for (int i = 1; i < emojis.size(); i++) {
                if (emojis[i] == emojis[i-1]) {
                    card.back()++;
                } else {
                    card.push_back(1);
                }
            }

            long double card_multinomial = calculate_log_multinomial(
                d, card, is_zero);

            if (is_zero) {
                continue;
            }

            cond_prob = exp(card_multinomial + sum_multinomial - 
            (long double)sum * log(d)) ;
            prob = cond_prob / m;

            denom += prob;
            if (d >= a && d <= b) {
                numer += prob;
            }
            anything = true;
        }
        if (anything) {
            cout << std::setprecision(12) << numer / denom << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}