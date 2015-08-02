//### PROGRAM
/*
  ID: vnovako001
  PROG: job
*/
#include <fstream.h>
#include <stdlib.h>

ifstream infile("job.in");
ofstream outfile("job.out");

int a[31];
int b[31];
int c[1000];
int secA[31];
int nA, nB;
int jobs;

int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;
	if (A > B)
		return 1;
	return -1;
}

int fA(int t)
{
	int i;
	int out = 0;

	for (i = 0; i < nA; i++)
		out += t / a[i];

	return out;
}

int fB(int t)
{
	int i;
	int out = 0;

	for (i = 0; i < nB; i++)
		out += t / b[i];

	return out;
}

main()
{
	int i, j;

	infile >> jobs >> nA >> nB;

	for (i = 0; i < nA; i++)
		infile >> a[i];
	for (i = 0; i < nB; i++)
	{
		busyB[i] = 0;
		start[i] = -1;
		infile >> b[i];
	}

	qsort(b, nB, sizeof(int), cmp);

	i = 1;


	i = 1;
   secA[0] = 0;

	for (j = 1; j < fA(1); j++)
		secA[j] = 1;

	while (fA(i) <= jobs)
	{
		secA[fA(i)] = i;
		for (j = fA(i) + 1; j <= fA(i + 1); j++)
			secA[j] = i + 1;
		while (fA(i) == fA(i + 1))
		{
			i++;
			for (j = fA(i) + 1; j <= fA(i + 1); j++)
				secA[j] = i + 1;
		}

		i++;
	}
	outfile << secA[jobs] << ' ';

	i =  1;

	pile = 0;
	done = 0;

	while (done < jobs)
	{
		pile += fA(i) - fA(i - 1);

		for (j = 0; j  < nB; j++)
		{
			if (start[j] != -1 && i - start[j] == b[j] && busyB[j])
			{
				busyB[j] = 0;
				done++;
			}
		}
		for (j = 0; j < nB && pile != 0; j++)
		{
			if (!busyB[j])
			{
				start[j] = i;
				busyB[j] = 1;
				pile--;
			}
		}


		i++;
	}

	outfile << i - 1 << endl;

	return 0;
}

//### END
