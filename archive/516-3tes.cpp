/* @JUDGE_ID: 3207EZ 516 C++ */
#include <iostream.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int nPF;
int primes[100];
int powers[100];

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

int gcf(int a, int b)
{
	if (!b)
		return a;
	return gcf(b, a % b);
}

int f(int x, int n)
{
	unsigned long X = x*x;
	return (X - 1) % n;
}


void factor(int n)
{
	int x, xx, y, i, k = 2, d;


	if (n == 1)
		return;
	if (isPrime(n))
	{
		for (i = 0; i < nPF; i++)
		{	if (primes[i] == n)
			{	powers[i]++; return; }
		}
		nPF++;
		primes[nPF - 1] = n;
		powers[nPF - 1] = 1;
		return;
	}

	x = random(n);
	y = x;
	i = 1;
	k = 2;

	while (1)
	{
		i++;
		xx = x;
		x = ((unsigned long)x*x  + x + 31) % n;
		if (x == xx)
			x = random(n);
		d = gcf(abs(y - x), n);
		if (d != 1 && d != n)
		{	factor(d); factor(n / d); return; }
		if (i == k)
		{	y = x; k = 2*k; }
	}

	factor(d);
	factor(n/d);
}





main()
{

	int i; int n, w, p, e;
	char s[100];

	time_t time0, time1;

	randomize();

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
		nPF = 0;
		time0 = time(NULL);
		factor(n);
		time1 = time(NULL);
		for (i = nPF - 1; i >= 0; i--)
		{
			cout << primes[i] << " " << powers[i];
			if (i)
				cout << " ";
		}
		cout << endl;
		cout << (double)(difftime(time1,time0)) << endl;
	}


	return 0;
}
