
#pragma option -O2

#include <fstream.h>

ifstream infile("run.in");
ofstream outfile("run.out");

int isRR(long N)
{
	int i, j;
   int covered[10];
	int digits[10];
	int nD = 0;
	int pos;
   int totalCover;

	for (i = 0; i < 10; i++)
		covered[i] = 0;

	while (N)
	{
		digits[nD++] = N % 10;
		if (covered[N % 10])
			return 0;
		covered[N % 10] = 1;
		N = N / 10;
	}

	pos = nD - 1;
	totalCover = 0;

	while (1)
	{
		if (!covered[digits[pos]])
		{
			if (totalCover == nD && pos == nD - 1)
				return 1;
			return 0;
		}
		covered[digits[pos]] = 0;
		totalCover++;

		pos = (pos - digits[pos] + 2*nD) % nD;
	}

}

main()
{
	long k;

	infile >> k;
   k++;

	while (!isRR(k))
		k++;

	outfile << k << endl;

	return 0;
}
