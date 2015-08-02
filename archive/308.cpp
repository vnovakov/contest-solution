/* @JUDGE_ID: 3207EZ 308 C++ */

#include <iostream.h>

int grid[100][100];
int minx, miny, maxx, maxy;

main()
{
	int nCuts;
	int cutsX1[100], cutsX2[100], cutsY1[100], cutsY2[100];

	while (1)
	{
		cin >> nCuts;

		if (!nCuts)
			break;
		maxx = 0; maxy = 0; minx = 32000; miny = 32000;
		for (i = 0; i < nCuts; i++)
		{
			cin >> cutsX1[i] >> cutsY1[i] >> cutsX2[i] >> cutsY2[i];
			if (cutsX1[i] > maxx)
				maxx = cutsX1[i];
			if (cutsX2[i] > maxx)
				maxx = cutsX2[i];
			if (cutsX1[i] < minx)
				minx = cutsX1[i];
			if (cutsX2[i] < minx)
				minx = cutsX2[i];
			if (cutsY1[i] > maxy)
				maxx = cutsY1[i];
			if (cutsY2[i] > maxy)
				maxx = cutsY2[i];
			if (cutsY1[i] < miny)
				minx = cutsY1[i];
			if (cutsY2[i] < miny)
				minx = cutsY2[i];
		}
		maxx -= minx;
		maxy -= miny;
		for (i = 0; i < nCuts; i++)
		{
			cutsX1[i] -= minx; cutsX2[i] -= minx;
			cutsY1[i] -= miny; cutsY2[i] -= miny;
		}
		for (i = 0; i <= maxx; i++)
			for (j = 0; j <= maxy; j++)
				grid[i][j] = 0;
		for (i = 0; i < nCuts; i++)
		{
			if (cutsX1[i] == cutsX2[i])
			{	a = cutsY1[i]; b = cutsY2[i];
				if (a > b) 	swap(a, b);
				for (j = a; j < b; j++) {
					grid[cutsX1[i]][j] += 1;
					if (cutsX1[i] >= 1)
						grid[cutsX1[i]-1][j] += 4;
				}
			}
			if (cutsY1[i] == cutsY2[i])
			{	a = cutsX1[i]; b = cutsX2[i];
				if (a > b) 	swap(a, b);
				for (j = a; j < b; j++) {
					grid[j][cutsY1[i]] += 8;
					if (cutsY1[i] >= 1)
						grid[j][cutsX1[i]-1] += 2;
				}
			}
