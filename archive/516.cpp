/* @JUDGE_ID: 3207EZ 516 C++ */
#include <iostream.h>
#include <math.h>
#include <string.h>


int isPrime(int n)
{
	int r = 1;
	if (n == 2 || n == 3)	return 1;
	if(n%2==0 || n%3==0) return 0;


	for(int i = 3; i*i <= n; i+=2)
		if(n%i==0)
			{ r = 0; break; }

	return r;
}

main()
{

	int i; int n, w, p, e;
	int nPrimes;
	int primes[2000];
	int powers[2000];
	char s[100];

	e = 0;
	p = 0;

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
		if (e)
			n *= pow(p, e);
		n--;

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
