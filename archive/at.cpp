#include <fstream.h>
#include <stdlib.h>

ofstream outfile("agri.in");

int matrix[100][100];

main()
{
	int i, j;
	int N = 100;

	randomize();

	for (i = 0; i < N; i++)
		for (j = 0; j < i; j++)
			matrix[i][j] = matrix[j][i] = rand() % 32000;
//			matrix[i][j] = matrix[j][i] = ((rand() % 5) + 1) * 1000;

	for (i = 0; i < N; i++)
		matrix[i][i] = 0;

	outfile << N << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			outfile << matrix[i][j] << ' ';
		outfile << endl;
	}

	return 0;
}

