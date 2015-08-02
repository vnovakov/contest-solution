#include <fstream.h>

ifstream infile("agri.in");
ofstream outfile("agri.out");

int N;
long INF = 100000;

long matrix[100][100];

main()
{
	long totalTree;
	int treeSize = 0;
	long dist[100];
	int inTree[100];
	int parent[100];

	int i, j; long minDist;

	infile >> N;

	for (i = 0; i < N; i++)
	{
		inTree[i] = 0; dist[i] = INF;
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			infile >> matrix[i][j];

	totalTree= 0;
	dist[0] = 0;

	while (treeSize != N)
	{
		minDist = INF;

		for (i = 0; i < N; i++)
			if (!inTree[i] && dist[i] < minDist)
			{	minDist = dist[i]; j = i; }

		treeSize++;
		totalTree += (long)minDist;
		inTree[j] = 1;

		if (j)
		{
			outfile << j  + 1<< ' ' << parent[j] + 1 << endl;
		}

		for (i = 0; i < N; i++)
			if (!inTree[i] && matrix[j][i] < dist[i])
			{
				dist[i] = matrix[j][i];
				if (!dist[i])
					cout << i;
				parent[j] = i;
			}

	}

	outfile << totalTree << endl;

	return 0;
}
