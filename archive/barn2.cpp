#include <fstream.h>

ifstream infile("barn2.in");
ofstream outfile("barn2.out");

unsigned char huge best[200][200];
unsigned char huge tree[200][200];

int N;

int min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	return c;
}

int main()
{
	int i, j, M, a, b, max = 0;

	infile >> N >> M;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			tree[i][j] = 0;

	for (i = 0; i < M; i++)
	{
		infile >> a >> b;
		tree[a - 1][b - 1] = 1;
	}

	for (i = 0; i < N; i++)
	{
		best[N - 1][i] = 1 - tree[N - 1][i];
		best[i][N - 1] = 1 - tree[i][N - 1];
	}

	for (i = N - 2; i >= 0; i--)
		for (j = N - 2; j >= 0; j--)
			best[i][j] = (tree[i][j]) ?
				 0 : (1 + min(best[i][j+1],best[i+1][j],best[i+1][j+1]));

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (best[i][j] > max)
				max = best[i][j];

	outfile << max << endl;

	return 0;
}







