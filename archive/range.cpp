#include <fstream.h>

ifstream infile("range.in");
ofstream outfile("range.out");

int N;
int huge matrix[250][250];
int huge older[250][250];
int huge newer[250][250];

inline int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

main()
{
	int i, j, k;
	long count;
	char S[500];

	infile >> N;
	infile.getline(S, 500);

	for (i = 0; i < N; i++)
	{
		infile.getline(S, 500);
		for (j = 0; j < N; j++)
			older[i][j] = matrix[i][j] = S[j] == '0' ? 0 : 1;
	}

	for (i = 1; i < N; i++)
	{
		count = 0;


		for (j = 0; j < N - 1; j++)
		{
			for (k = 0; k < N - 1; k++)
			{
					older[j][k] = matrix[j][k] && older[j+1][k] &&
				  older[j+1][k+1] &&  older[j][k+1];
					count += older[j][k];
			}
			older[j][N - 1] = 0;
		}
		for (j = 0; j < N; j++)
			older[N - 1][j] = 0;
		if (count)
		{
		outfile << i + 1 << ' ';
		outfile << count << endl;
		}
	}

	return 0;
}
