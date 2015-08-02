#include <fstream.h>
#include <stdlib.h>

ofstream outfile("cowtour.in");

int N;
int matrix[150][150];
main()
{
	N = 150;
   randomize();

	outfile << N << endl;

	int i, j;

	for (j = 0; j < N; j++)
		for (i = 0; i < j; i++)
			if (!( (i < N / 3 && j < N / 3) || (i >= N / 3 && i < 2*N / 3 &&
															j >= N/3 && j < 2*N/3)||
														 (i >= 2*N/3 && j >= 2*N/3) ))
				matrix[i][j] = matrix[j][i] = matrix[i][i] = 0;
			else
			{
				matrix[i][j] = matrix[j][i] = (rand() % 5 == 0);
				matrix[i][i] = 0;
			}
	for (i = 0; i < N; i++)
		outfile << rand() % 10000 << ' ' << rand() % 10000 << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)

				outfile << matrix[i][j] << ' ';
		outfile << endl;
	}

	return 0;
}


