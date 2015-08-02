#include <iostream.h>
#include <stdlib.h>

int prime[20000];

int gcf(int a, int b)
{
	if (a == 0)
		return b;
	if (b == 0)
		return a;
	if (a < 0)
		a = -a;
	if (b < 0)
   	b = -b;
	return gcf(b, a % b);
}

int isPrime(int n)
{
	int r = 1;
	if (n == 1)
   	return 0;
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

void pollardRho(int n)
{
	int i = 1;
   int x = rand() % n; int d;
	int primes[1000];
	int powers[1000];
	int nPrimes = 0;
	int y = x;
	int k = 1;

	while(1)
	{
		i++;
		x = ((long)x^2 - 1) % n;
		d = gcf(y - x, n);
		if (isPrime(d))
		{
			primes[nPrimes] = d;
			powers[nPrimes] = 0;
			while(n % d == 0)
			{
				powers[nPrimes]++;
				n /= d;
			}
			nPrimes++;
		}
		if (n == 1)
			break;
		if (i == k)
			{  y = x; k *= 2; }
	}


		for (i = nPrimes - 1; i >= 0; i--)
		{
			cout << primes[i] << " " << powers[i];
			if (i)
				cout << " ";
		}
		cout << endl;
}

main()
{
	for (int i = 0; i < 20000; i++)
		prime[i] = -1;

	pollardRho(22);
}
