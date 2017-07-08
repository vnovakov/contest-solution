#include <bits/stdc++.h>

using namespace std;

int check_cool (int m) {
    int cool = 1;

    vector<int> seen(10, 0);
    while (m)
    {
        if (seen[m % 10])
        {
            cool = 0;
            break;
        }
        seen[m % 10] = 1;
        m /= 10;
    }

    return cool;
}

const int cutoffs[11] = {
    0,0,10,102,1023,10234,102345,1023456,
    10234567,102345678,1023456789};

const int ITER = 10000000;

int explore_range_slow(int a, int b, int c) {
    
    for (int iter = 0; iter < ITER; iter++) {
        int gen = a + rand() % (b - a);
        if (check_cool(gen) && check_cool(b - gen)) {
            //cout << "FOUND " << gen << " + " << b-gen << endl;
            return 1;
        }
    }
    return 0;
}

int explore(int n, int c) {
    //cout << "EXPLORE " << n << " and " << c << endl;
    vector<int> digits(10);
    if (c < 10)
    {
        for (int i = 0; i < 10; i++)
        {
            digits[i] = i;
        }
    }
    else
    {
        digits.resize(9);
        for (int i = 2; i <= 9; i++)
        {
            digits[i - 2] = i;
        }
        digits[8] = 0;
    }
    for (int iter = 0; iter < ITER; iter++) {
    
        std::random_shuffle(digits.begin(), digits.end());

        int m = (c == 10) ? 1 : 0;
        for (int i = 0; i < (c == 10 ? (c - 1) : c); i++) {
            m = 10*m + digits[i];
        }
        
        if (n > m && check_cool(n - m)) {
            cerr << "2 " << m << " " << n-m << endl;
            return 1;
        }
    }
    return 0;
}

int main()
{
    srand(time(NULL));

    int test_cases = 0;
    cin >> test_cases;

    vector<int> remain;

    while (test_cases--)
    {
        int n;
        cin >> n;

        //vector<int> answer = brute_force(n);

        //cout << answer.size();
        if (check_cool(n)) {
            cerr << "1 " << n << endl; 
            continue;
        } else {
            int d = 10;
            int c = 1;
            
            while (d <= n) {
                c++;
         
                if (d == 1000000000) {
                   
                    break;
                }
                d *= 10;
            }
            //cout << c << endl;
            //cout << cutoffs[c] << endl;     
            
            if (n >= cutoffs[c]) {
                //if (check_cool(n - cutoffs[c])) {
                //    continue;
                //}
                if (explore(n, c)) {
                    continue;
                }
                if (explore(n, c-1)) {
                    continue;
                }
            } else {
                //if (check_cool(n - cutoffs[c-1])) {
                //    continue;
                //}   
                if (explore(n, c-1)) {
                    continue;
                }
            }
    
            remain.push_back(n);
        }
    
    }
    cout << remain.size() << endl;
    for (int i = 0; i < remain.size(); i++) {
        cout << remain[i] << endl;
    }
    return 0;

}