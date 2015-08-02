#include <fstream.h>

ifstream infile("clocks.in");
ofstream outfile("clocks.out");

int moves[9][9] =

	{  {1,1,0,1,1,0,0,0,0},
		{1,1,1,0,0,0,0,0,0},
		{0,1,1,0,1,1,0,0,0},
		{1,0,0,1,0,0,1,0,0},
		{0,1,0,1,1,1,0,1,0},
		{0,0,1,0,0,1,0,0,1},
      {0,0,0,1,1,0,1,1,0},
		{0,0,0,0,0,0,1,1,1},
		{0,0,0,0,1,1,0,1,1} };
int clocks[9];
int C[9];

main()
{
	long P, L, M;
	int bits[9], bbits[9];
	int best = 30000, works;
	int pot;
	int i, j, q;
	P = 1;

	for (i = 0; i < 9; i++)
	{
		P *= 4;
		infile >> j;
		j %= 12;
		C[i] = clocks[i] = j / 3;
	}

	for (L = 0; L < P; L++)
	{

		M = L;
		pot = 0;

		for (i = 0; i < 9; i++)
		{	clocks[i] = C[i];
			bits[i] = 0;
		}
		i = 0;
		while (M)
		{
			bits[i] = M % 4;
			pot += bits[i++];
			M /= 4;
		}
		for (i = 0; i < 9; i++)
			for (j = 0; j < 9; j++)
				if (moves[i][j])
					clocks[j] = (clocks[j] + bits[i]) % 4;
		works = 1;
		for (i = 0; i < 9; i++)
			if (clocks[i])
				works = 0;
		if (works && pot < best)
		{
			pot = best;
			for (i = 0; i < 9; i++)
				bbits[i] = bits[i];
		}
	}

	q = 0;
	for (i = 0; i < 9; i++)
		for (j = 0; j < bits[i]; j++)
		{		if (q)
					outfile << ' ' << i + 1;
				else
					outfile << i + 1;
				q = 1;
		}
	outfile << endl;

	return 0;
}


