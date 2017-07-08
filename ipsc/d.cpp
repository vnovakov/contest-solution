#include <bits/stdc++.h>

using namespace std;

vector<int> brute_force(int n) {
    vector<int> answer(0);
    vector<int> cool(10001, 1);

    for (int i = 0; i < 10000; i++) {
        vector<int> seen(10, 0);
        int m = i;
        while (m) {
            if (seen[m % 10]) {
                cool[i] = 0;
                break;
            }
            seen[m % 10] = 1;
            m /= 10;
        }
    }

    vector<vector<int> > best(10001, vector<int>(0));

    for (int i = 0; i <= n; i++) {
        if (cool[i]) {
            best[i].push_back(i);
        }
    }

    if (cool[n]) {
        return best[n];
    }

    while (1) {

        for (int i = n; i >= 0; i--) {
            if (best[i].size() != 0) {
                continue;
            }
            int best_index = -1;

            for (int j = 0; j < i; j++) {
                if (cool[i - j] && best[j].size() 
                && (best_index == -1 ||
                    best[j].size() < best[best_index].size())) {
                        best_index = j;
                    }
            }

            if (best_index != -1) {
                for (int k = 0; k < best[best_index].size(); k++) {
                    best[i].push_back(best[best_index][k]);
                    best[i].push_back(i - best_index);
                }
            }
        }

        if (best[n].size() != 0) {
            return best[n];
        }
    }
}

map<int, int> pre_computed_results;

vector<int> pre_computed(int n) {
    assert(pre_computed_results.find(n) != pre_computed_results.end());

    int b = pre_computed_results[n];

    if (b == 0) {
        vector<int> answer(1, n);
        return answer;
    } else {
        vector<int> answer(2, n - b);
        answer[1] = b;
        return answer;
    }
}

int main()
{
    ifstream infile("d2.out_full");

    int num_answer;
    while (infile >> num_answer) {
        int a, b = 0;
        infile >> a;
        if (num_answer == 2)
        {
            infile >> b;
        }
        pre_computed_results[a+b] = b;
    }
    infile.close();

    int test_cases = 0;
    cin >> test_cases;

    while (test_cases--) {
       int n;
       cin >> n;

       vector<int> answer;
       
       if (n <= 10000) {
           answer = brute_force(n);
       } else {
           answer = pre_computed(n);
       }
       cout << answer.size();

       for (int i = 0; i < answer.size(); i++) {
           cout << " " << answer[i];
       }

       cout << endl;

    }
    return 0;
}