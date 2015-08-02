#include <fstream.h>

ifstream infile("ditch.in");
ofstream outfile("ditch.out");

long huge matrix[200][200];

long min(long a, long b)
{
	if (a < b)
		return a;
	return b;
}

long const INF = 2000000000;

main()
{

	int N, M;
	int i, j, k, l;
	long cap, curMax, curCap, flow = 0;

	int visited[200];
	long maxCap[200];
	int parent[200];


	infile >> M >> N;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			matrix[i][j] = 0;

	while (M--)
	{
		infile >> i >> j >> cap;
		i--;
		j--;
		matrix[i][j] += cap;
	}

	while (1)
	{

		for (i = 0; i < N; i++)
		{
			visited[i] = 0;
			maxCap[i] = 0;
		}
		maxCap[0] = INF;
      parent[0] = -1;


		while (1)
		{
			curMax = 0;
			j = -1;

			for (i = 0; i < N; i++)
				if (!visited[i] && maxCap[i] > curMax)
				{	j = i; curMax = maxCap[i]; }

			if (j  == -1 || curMax == 0)
				break;
			visited[j] = 1;
			for (i = 0; i < N; i++)
			{
				if (min(maxCap[j], matrix[j][i]) > maxCap[i])
				{
					maxCap[i] = min(maxCap[j], matrix[j][i]);
					parent[i] = j;
				}
			}
		}

		if (maxCap[N - 1] == 0)
			break;

		k = N - 1;
		curCap = maxCap[N - 1];

		while (1)
		{
			if (!k)
				break;
			matrix[k][parent[k]] += curCap;
			matrix[parent[k]][k] -= curCap;

			k = parent[k];
		}
		flow += curCap;
	}

	outfile << flow << endl;

	return 0;
}
