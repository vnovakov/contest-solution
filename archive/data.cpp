#include <iostream.h>
#include <fstream.h>

ofstream outfile("DATA.TXT");

int isPrime(int n)
{
	if (n == 2)
		return 1;
	if (n < 2)
		return 0;
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

main()
{
	for (int i = 0; i < 1000; i++)
		outfile << isPrime(i) << "," << endl;

	return 0;
}
