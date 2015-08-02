#include <fstream.h>

ifstream infile("sprime.in");
ofstream outfile("sprime.out");

int N;

long huge array[10000];
long gen[10000];
int prime[4] = {2,3,5,7};

int isPrime(long n)
{
	 long i;
	 if (n==1) return 1;  /* or 0, if appropriate */
	 if (n==2) return 1;
	 if (n%2==0) return 0;
	 for (i=3; i*i<=n; i+=2)
	 if (n%i==0)
			  return 0;
	 return 1;
}

void generate(int n, int &count)
{
	int old = count;
	long k;
	count = 0;
	int i, j;
	if (n == 1)
	{
		count = 4;
		for (j = 0; j < count; j++)
			array[j] = prime[j];

		return;
	}
	for (i = 0; i < old; i++)
	{
		k = 10*array[i];

		for (j = 1; j <= 9; j += 2)
			if (isPrime(k + j))
			{
				gen[count++] = k + j;
			}
	}

	for (i = 0; i < count; i++)
		array[i] = gen[i];

}

main()
{
	int i, count;

	infile >> N;

	for (i = 1; i <= N; i++)
		generate(i, count);

	for (i = 0; i < count ; i++)
		outfile << array[i] << endl;

	return 0;
}

