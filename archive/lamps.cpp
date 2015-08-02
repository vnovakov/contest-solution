#include <fstream.h>
#include <stdlib.h>

ifstream infile("lamps.in");
ofstream outfile("lamps.out");

int N;
int nOn;
int nOff;
int on[100];
int off[100];
int start[4] = {0,0,1,0};
int diff[4] = {1,2,2,3};
int curr[100];
int C;
int perm[1000];
int huge sol[1000][100];
int nSol = 0;

int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;
	int i;

	for (i = 0; i < N; i++)
		if (sol[A][i] > sol[B][i])
			return 1;
	return -1;
}

main()
{
	int i, j;
	int bits[4];
	int k, l, count;

	infile >> N;
	infile >> C;

	nOn = 0;
	nOff = 0;
	while (1)
	{
		infile >> k;
		if (k == -1)
			break;
		on[nOn++] = k;
	}
	while (1)
	{
		infile >> k;
		if (k == -1)
			break;
		off[nOff++] = k;
	}

	for (i = 0; i < 16; i++)
	{
		for (l = 0; l < N; l++)
			curr[l] = 1;
		k = i;
      count = 0;
		for (j = 0; j < 4; j++)
		{
			bits[j] = k % 2;
         count += bits[j];
			k /= 2;
			if (bits[j])
			{

			for (l = start[j]; l < N; l += diff[j])
				curr[l] = !curr[l];
			}
		}

		if (count <= C && (count - C) % 2 == 0)
			k = 1;
		else
      	k = 0;

		for (j = 0; j < nOn; j++)
			if (curr[on[j]-1] != 1)
				k = 0;
		for (j = 0; j < nOff; j++)
			if (curr[off[j]-1] != 0)
				k = 0;
		if (k)
		{
			for (j = 0; j < N; j++)
				sol[nSol][j] = curr[j];
			nSol++;
		}
	}

	for (i = 0; i < nSol; i++)
		perm[i] = i;

	qsort(perm, nSol, sizeof(int), cmp);

	for (i = 0; i < nSol; i++)
	{
		for (j = 0; j < N; j++)
			outfile << sol[perm[i]][j];
		outfile << endl;
	}

	return 0;
}
