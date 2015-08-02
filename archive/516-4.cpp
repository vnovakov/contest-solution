/* @JUDGE_ID: 3207EZ 516 C++ "Pollard Rho O(n^[1/4])" */
#include <iostream.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int nPF;
int primes[100];
int powers[100];

int witness(int a, int n)
{
	 int i, b, bin[30], d;
	 i = 0;
	 b = n - 1;
	 while (b)
	 {
		bin[i++] = b % 2;
		b /= 2;
	 }
	 d = 1;
	 for (i--; i >= 0; i--)
	 {
		d = ((unsigned long)d * d ) % n;
		if (bin[i] == 1)
			d = ((unsigned long)d * a) % n;
	 }

	 if (d == 1)
		return 0;
	 return 1;
}


int isPrime(int n)
{
	int j = 0, s = 1, a;

	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	if (n % 2 == 0)
   	return 0;
	while (1)
	{
		j++;
		s *= 2;
		if (s > n)
			return 1;

		a = random(n - 1) + 1;
		if (witness(a, n))
			return 0;
	}
}

int gcf(int a, int b)
{
	if (!b)
		return a;
	return gcf(b, a % b);
}



void factor(int n)
{
	int x, xx, xxx, y, i, k = 2, d;


	if (n == 1)
		return;
	if (isPrime(n))
	{
		for (i = 0; i < nPF; i++)
		{	if (primes[i] == n)
			{	powers[i]++; return; }
		}
		for (i = nPF - 1; i >= 0 && primes[i] > n; i--)
	  {		primes[i+1] = primes[i]; powers[i+1] = powers[i]; }
		primes[i+1] = n;
		nPF++;
		powers[i+1] = 1;
		return;
	}

	x = random(n);
	y = x;
	i = 1;
	k = 2;
	xx = x;
	x = ((unsigned long)x*x  + x + 31) % n;
	while (1)
	{
		i++;
		xxx = xx;
		xx = x;
		x = ((unsigned long)x*x  + x + 31) % n;
		while (x == xx || x == xxx)
			x = random(n);
		d = gcf(abs(y - x), n);
		if (d != 1 && d != n)
		{	factor(d); factor(n / d); return; }
		if (i == k)
		{	y = x; k = 2*k; }
	}

}





main()
{

	int i; int n, w, p, e;
	char s[100];

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
		factor(n);
		for (i = nPF - 1; i >= 0; i--)
		{
			cout << primes[i] << " " << powers[i];
			if (i)
				cout << " ";
		}
		cout << endl;
	}


	return 0;
}
