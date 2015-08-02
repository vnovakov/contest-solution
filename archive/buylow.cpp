#include <fstream.h>

ifstream infile("buylow.in");
ofstream outfile("buylow.out");

int N;
unsigned long huge array[5001];
int best[5001];
char huge count[5001][200];
int smaller[5000];



main()
{
	int N, globalBest = 0; char totalCount[200];
	int c;
	int i, j, k, carry;
   char old;

	infile >> N;  for (i = 0; i < N; i++) infile >> array[i];

	array[N++] = 0;
	best[N-1] = 0; count[N-1][0] = 1;
	for (k = 1; k < 200; k++)
   	count[N-1][k] = 0;

	for (i = N - 2; i >= 0; i--)
	{
		best[i] = 0;
		count[i][0] = 0;
		for (k = 1; k  < 200; k++)
      	count[i][k] = 0;
		for (j = i + 1; j < N; j++)
			if (array[j] < array[i] && best[j] + 1 > best[i])
				best[i] = best[j] + 1;
		c = 0;
		for (j = i + 1; j < N; j++)
			if (array[j] < array[i] && best[j] + 1 == best[i])
			{
				smaller[c++] = j;
			}
		for (j = 0; j < c; j++)
		{
			carry = 0;
			for (k = 0; k < 200; k++)
			{
				old = count[i][k];
				count[i][k] = (count[i][k] + count[smaller[j]][k] + carry) % 10;
				carry = (old + count[smaller[j]][k] + carry) / 10;
			}


			while (j < c - 1 && array[smaller[j]] == array[smaller[j+1]])
				j++;
		}
	}
	c = 0;

	for (i = 0; i < N; i++)
		if (best[i] > globalBest)
			globalBest = best[i];
	for (i = 0; i < N; i++)
		if (best[i] == globalBest)
			smaller[c++] = i;

	for (k = 0; k < 200; k++)
		totalCount[k] = 0;

	for (i = 0; i < c; i++)
	{
			carry = 0;
			for (k = 0; k < 200; k++)
			{
				old = totalCount[k];
				totalCount[k] = (totalCount[k] + count[smaller[i]][k] + carry) % 10;
				carry = (old + count[smaller[i]][k] + carry) / 10;
			}
		while (i < c - 1 && array[smaller[i]] == array[smaller[i+1]])
			i++;
	}

	outfile << globalBest << ' ';

	for (k = 199; totalCount[k] == 0 && k >= 0; k--)
		;
	for (; k >= 0; k--)
		outfile << (int)totalCount[k];
	outfile << endl;

	return 0;
}


