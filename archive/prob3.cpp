//### Program

#pragma option -O2

/*

Problem: 3
Name: Vladimir Novakovski
Email: vnovakov@lan.tjhsst.edu
School: TJHSST
Grade: 10
Age: 14
CityState: Springfield, VA
Country: USA

*/

typedef long* Larray;
typedef int* Iarray;

#include <fstream.h>
#include <alloc.h>
#include <time.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

const double LIMIT = 4.9;
const long INF = 2000000000;

inline long min (long a, long b)
{

	return (a < b) ? a : b;
}

int nN[400];
Iarray neighbors[400];
Larray dN[400];
int start[2000];
int end[2000];
long dist[2000];

long d[400];
int visited[400];


main()
{

	int i, j, k, l, n = 0, p;
	long minLoop = INF, minD;

	infile >> l;

	for (i = 0; i < l; i++)
	{
		infile >> start[i] >> end[i] >> dist[i];
		start[i]--;
		end[i]--;
		if (start[i] + 1 > n)
			n = start[i] + 1;
		if (end[i] + 1 > n)
			n = end[i] + 1;
	}

	for (i = 0; i < n; i++)
		nN[i] = 0;

	for (i = 0; i < l; i++)
		nN[start[i]]++;

	for (i = 0; i < n; i++)
	{
	neighbors[i] =
	 (Iarray)malloc(nN[i] * sizeof(int));
	dN[i] =
	 (Larray)malloc(nN[i] * sizeof(long));

		j = 0;

		for (k = 0; k < l; k++)
			if (start[k] == i)
			{
			neighbors[i][j] = end[k];
			dN[i][j++] = dist[k];
			}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			visited[j] = 0;

		for (j = 0; j < n; j++)
			d[j] = INF;

		for (j = 0; j < nN[i]; j++)
		d[neighbors[i][j]] = dN[i][j];


		while (1)
		{
		minD = INF;

		k = -1;
		for (j = 0; j < n; j++)
		{
		if (!visited[j] && d[j] < minD)
		{	k = j; minD = d[j]; }
		}
		if (minD == INF || k == -1)
			break;
			visited[k] = 1;

			p = nN[k];

	for (j = 0; j < p; j++)
	{
			l = neighbors[k][j];
		if (d[l] > minD + dN[k][j])
		d[l] = minD + dN[k][j];

			}
		}

		if (d[i] < minLoop)
			minLoop = d[i];

	if ((double)clock() > LIMIT * CLOCKS_PER_SEC)
			break;
	}

	outfile << minLoop << endl;

	return 0;

}



//### End