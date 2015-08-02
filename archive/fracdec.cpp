//### PROGRAM
/*
ID: vnovako001
PROG: fracdec
*/

#include <stdio.h>
#include <fstream.h>
#include <math.h>

ifstream infile("fracdec.in");
FILE* outfile;

int huge used[100000];
long huge when[100000];
int huge digit[100000];



main()
{
	long N, D; long q = 0;
	long i, j = 0, k;
	int end = 1;

	outfile = fopen( "fracdec.out", "w");

	infile >> N >> D;

	fprintf(outfile, "%d", N / D);
	fprintf(outfile, ".");
	if (N / D == 0)
		q = 1;
	else
		q = (long)log(N / D) / log (10) + 1;
	q++;



	N %= D;

	for (i = 0; i < D; i++)
		used[i] = 0;

	N = 10*N;


		while (!(used[N % D] && digit[when[N % D]] == N / D))
		{
			used[N % D] = 1;
			when[N % D] = j;
			digit[j++] = N / D;
			N = N % D;
			if (!N)
			{
					end = 0;
				break;
			}
			used[N] = 1;
			N = 10*N;
		}


	if (end)
	{
			k = when[N % D];
			for (i = 0; i < k; i++)
			{


				if (q && !(q % 76))
					fprintf(outfile, "\n");
				q++;
				fprintf(outfile, "%d",  digit[i]);
			}

			if (q && !(q % 76))
					fprintf(outfile, "\n");
			q++;
					fprintf(outfile, "(");

			for (i = k; i < j; i++)
			{

				if (q && !(q % 76))
					fprintf(outfile, "\n");
				q++;
					fprintf(outfile, "%d", digit[i]);
			}

			if (q && !(q % 76))
					fprintf(outfile, "\n");

			q++;
					fprintf(outfile, ")\n");
	} else {

	for (i = 0; i < j; i++)
	{

		if (q && !(q % 76))
					fprintf(outfile, "\n");
		q++;
					fprintf(outfile, "%d", digit[i]);
	}
					fprintf(outfile, "\n");

	}


	return 0;
}
