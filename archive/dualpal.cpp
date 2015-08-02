#include <fstream.h>

ifstream infile("dualpal.in");
ofstream outfile("dualpal.out");

int isPal(long N, int B)
{
	int bits[100];
	int nBits = 0;
	int i;

	while(N)
	{
		bits[nBits++] = N % B;
		N = N / B;
	}

	for (i = 0; i < nBits; i++)
		if (bits[i] != bits[nBits - 1 -i])
			return 0;
	return 1;
}

main()
{
	long a, b;
	int count = 0;
	int i;

	infile >> a >> b;


	while (b--)
	{
		a++;

		while (1)
		{
			count = 0;
			for (i = 2; i <= 10; i++)
				count += isPal(a, i);
			if (count < 2)
				a++;
			else
			{
				outfile << a << endl;
				break;
			}
		}
	}

	return 0;
}
