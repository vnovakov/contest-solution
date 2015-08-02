#include <iostream.h>
#include <fstream.h>

ofstream outfile("PRIMES.TXT");

long isPrime(long n)
{
	long i;

	if (n == 2 || n == 3)
		return 1;
	if (n % 2 == 0)
		return 0;

	for (i = 3; i*i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

main()
{
	long i;
	long r = 1;

	cout << isPrime(37319) << endl;
	return 0;
}

