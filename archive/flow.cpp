//### Program

#pragma option -O2

/*

Problem: 1
Name: Vladimir Novakovski
Email: vnovakov@lan.tjhsst.edu
School: TJHSST
Grade: 10
Age: 14
CityState: Springfield, VA
Country: USA

*/


#include <fstream.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

unsigned char huge matrix[202][202];
int nN[202];
unsigned char neighbors[202][202];

inline int min (int a, int b)
{

	return (a < b) ? a : b;
}

const INF = 30000;

main()
{
	int C, G;
	int N;
	int c, g, i, j, id, p;
	int gifts[100];
	int flow[202];
	int prev[202];
	int visited[202];
	int pathCap, maxFlow, maxLoc, curr, next;
	int nGifts;
	int totalFlow;

	infile >> C >> G;

	for (g = 0; g < G; g++)
		infile >> gifts[g];

	N = 2 + C + G;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			matrix[i][j] = 0;

	for (i = 0; i < C; i++)
		matrix[0][1 + i] = 1;

	for (i = 0; i < G; i++)
		matrix[1 + C + i][N - 1] = 1;

	for (c = 0; c < C; c++)
	{
		infile >> nGifts;

		for (i = 0; i < nGifts; i++)
		{
			infile >> id;
			for (g = 0; g < G; g++)
				if (gifts[g] == id)
				{
					matrix[1+c][1+C+g] = 1;
				}
		}
	}



	for (i = 0; i < N; i++)
		nN[i] = 0;

	for (i = 0; i < N; i++)
		for (g = 0; g < N; g++)
			if (matrix[i][g])
			{
				neighbors[i][nN[i]++] = g;
				neighbors[g][nN[g]++] = i;
			}


	totalFlow = 0;

	while (1)
	{
		for (i = 0; i < N; i++)
		{
			prev[i] = -1;
			flow[i] = 0;
			visited[i] = 0;
		}

		flow[0] = INF;

		while (1)
		{
			maxFlow = 0;
			maxLoc = -1;

			for (i = 0; i < N; i++)
				if ((flow[i] >= maxFlow) && !visited[i])
				{	maxFlow = flow[i];
					maxLoc = i;
				}



			if (maxLoc == -1)
				break;
			if (maxLoc == N - 1)
				break;

			visited[maxLoc] = 1;

			p = nN[maxLoc];
			for (j = 0; j < p; j++)
			{
				i = neighbors[maxLoc][j];

				if (flow[i] < min(maxFlow, matrix[maxLoc][i]))
				{
					prev[i] = maxLoc;
					flow[i] = min(maxFlow, matrix[maxLoc][i]);
				}
			}

		}

		if (maxFlow == 0 || maxLoc == -1)
			break;

		pathCap = flow[N - 1];

		totalFlow += pathCap;

		curr = N - 1;

		while (curr)
		{
			next = prev[curr];
			matrix[next][curr] -= pathCap;
			matrix[curr][next] += pathCap;

			curr = next;
		}

	}


	outfile << totalFlow << endl;

	return 0;

}



//### End