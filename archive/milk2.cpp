#include <fstream.h>

ifstream infile("milk2.in");
ofstream outfile("milk2.out");

int N;
char huge array[1000000];

main()
{
	int i;
	long j, maxI, I, maxM, M;
	long a, b;
	long A = 1000000, B = 0;

	for (j = 0; j < 1000000; j++)
		array[j] = 0;

	infile >> N;

	for (i = 0; i < N; i++)
	{
		infile >> a >> b;
		if (a < A)
			A = a;
		for (j = a; j < b; j++)
			array[j] = 1;
		if (b > B)
			B = b;
	}

	maxM = 0;  M = 0;
	maxI = 0; I = 0;

	for (j = A; j < B; j++)
	{
		if (((j == A) && (array[j] == 1)) || ( (array[j] == 1 )&&( array[j - 1] == 0)))
		{
			if (I > maxI)
				maxI = I;
			I = 0;
			M = 0;
		}
		if (((j == A) && (array[j] == 0)) || (( array[j] == 0) && (array[j - 1] == 1)))
		{
			if (M > maxM)
				maxM = M;
			I = 0;
			M = 0;
		}
		if (array[j] == 1)
			M++;
		else
			I++;

	}
			if (M > maxM)
				maxM = M;
			if (I > maxI)
         	maxI = I;
		outfile << maxM << ' ' << maxI << endl;

		return 0;

}
