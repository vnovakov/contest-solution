/* @JUDGE_ID: 3207EZ 516 C++ */
#include <iostream.h>
#include <math.h>
#include <string.h>
#include <time.h>

int prime[20000];

int isPrime(int n)
{
	int r = 1;
	if (n == 2 || n == 3)	return 1;
	if(n%2==0 || n%3==0) return 0;
	if (prime[(n - 1)/2] != -1)
		return prime[(n - 1)/2];


	for(int i = 5; i*i <= n; i+=6)
		if(n%i==0 || n%(i+2)==0)
			{ r = 0; break; }
	prime[(n - 1)/2] = r;
	return r;
}

main()
{

	int i; int n, w, p, e; double t0, t1;
	int nPrimes;
	int primes[2000];
	int powers[2000];
	char s[100];

	for (i = 0; i < 20000; i++)
			prime[i] = -1;

	while(1)
	{
		cin.getline(s, 100);

		n = 1; w = 0; p = 0; e = 0;
		if (s[0] == '0')
			break;
		for (i = 0; i < strlen(s); i++)
		{
			if (s[i] == ' ')
			{  	w = 1 - w; if (w == 0) { n *= pow(p, e); p = 0; }
									else e = 0;
			}
			else
			{	if (w == 0) { p = 10*p + (s[i] - '0'); }
				else { e = 10*e + (s[i] - '0'); }
			}
		}
		n *= pow(p, e);
		n--;
		t0 = clock() / CLOCKS_PER_SEC;
		nPrimes = 0;

		for (i = 2; ; i++)
		{
			if (n == 1)
				break;
			if (n < 20000 && isPrime(n))
			{
				primes[nPrimes] = n;
				powers[nPrimes] = 1;
				nPrimes++;
				break;
			}
			if (isPrime(i) && n % i == 0)
			{
				primes[nPrimes] = i;
				powers[nPrimes] = 0;
				while(n % i == 0)
				{
					powers[nPrimes]++;
					n /= i;
				}
				nPrimes++;
			}
		}
		t1 = clock() / CLOCKS_PER_SEC;
      cout << t1 - t0 << endl;
		for (i = nPrimes - 1; i >= 0; i--)
		{
			cout << primes[i] << " " << powers[i];
			if (i)
				cout << " ";
		}
		cout << endl;
	}


	return 0;
}
