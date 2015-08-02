#include <fstream.h>
#include <stdlib.h>

ifstream infile("pprime.in");
ofstream outfile("pprime.out");

int lcmp(void const *a, void const *b)
{
	long A = *(long *)a;
	long B = *(long *)b;

	if (A > B)
		return 1;
	else
		return -1;
}


int isPrime(long n)
{
	 long i;
	 if (!n) return 0;
	 if (n==1) return 0;
	 if (n==2) return 1;
	 if (n%2==0) return 0;
	 for (i=3; i*i<=n; i+=2)
	 if (n%i==0)
			  return 0;
	 return 1;
}

long pprimes[1000];
long count = 0;

long reverse(long a, int d)
{
	int dig[10], e = 0;
	long b = 0;
	for (e = 0; e < d; e++)
		dig[e] = 0;
  	e = 0;
	while (a)
	{
		dig[e++] = a % 10;
		a /= 10;
	}
	for (e = 0; e < d; e++)
	{
		b *= 10;
		b += dig[e];

	}

	return b;
}

main()
{

	long a, b;
	int d;
	int i;
	long j, l;
	long power = 1;

	infile >> a >> b;

	count = 2;
	pprimes[0] = 5;
   pprimes[1] = 7;

	for (d = 2; d <= 8; d++)
	{
		if (d % 2 == 1)
		{
			for (i = 0; i < 10; i++)
				for (j = 1; j < power; j++)
					if (j % 10)
					{
						l = j + power * i + 10*power*reverse(j, d / 2);
						if (isPrime(l))
							pprimes[count++] = l;
					}
		} else {
			power *= 10;
			for (j = 1; j < power; j++)
				if (j % 10)
				{
					l = j + power*reverse(j, d / 2);
						if (isPrime(l))
							pprimes[count++] = l;
				}

		}
	}

	qsort(pprimes, count, sizeof(long), lcmp);

	for (i = 0; i < count; i++)
	{
		if (pprimes[i] >= a && pprimes[i] <= b)
			outfile << pprimes[i] << endl;
	}

	return 0;
}
