#include <fstream.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

ifstream infile("cowtour.in");
FILE* outfile;

double huge path[150][150];
int N;
double INF = 1000000000;
double farthest[150];
double X[150], Y[150];
double diameter[150];

double max(double a, double b)
{
	return (a > b) ? a : b;
}

main()
{
	int i, j, k, l;
	char S[200];

	double min;
	double pot;

	infile >> N;

	for (i = 0; i < N; i++)
		infile >> X[i] >> Y[i];

	//infile.getline(S, 200);

	/*
	for (i = 0; i < N; i++)
	{
		infile.getline(S, 200);
		l = 0;
		for (j = 0; j < strlen(S); j++)
			if (S[j] == '0' || S[j] == '1')
			{

			k = S[j] - '0';

			if (!k)
				path[i][l] = INF;
			else
				path[i][l] =
						sqrt(  (X[i] - X[l]) * (X[i] - X[l]) +
								 (Y[i] - Y[l]) * (Y[i] - Y[l]) );
			l++;
			}
	} */

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)

		{

			infile >> k;

			if (!k)
				path[i][j] = INF;
			else
				path[i][j] =
						sqrt(  (X[i] - X[j]) * (X[i] - X[j]) +
								 (Y[i] - Y[j]) * (Y[i] - Y[j]) );

			}
	} 

	for (k = 0; k < N ; k++)
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (i != j)
					if (path[i][k] + path[k][j] < path[i][j])
						path[i][j] = path[i][k] + path[k][j];


	for (i = 0; i < N; i++)
	{
		farthest[i] = 0;
		for (j = 0; j < N; j++)
			if (2*path[i][j] < INF && path[i][j] > farthest[i])
				farthest[i] = path[i][j];
	}

	if (N != 1)
		min = INF;
	else
		min = 0;

	for (i = 0; i < N; i++)
	{
		diameter[i] = 0;
		for (j = 0; j < N; j++)
			if (2*path[i][j] < INF && farthest[j] > diameter[i])
				diameter[i] = farthest[j];
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (i != j)
			{
				pot = max ( 	farthest[i] + farthest[j] +
						sqrt(  (X[i] - X[j]) * (X[i] - X[j]) +
							 (Y[i] - Y[j]) * (Y[i] - Y[j]) ),
							  max (diameter[i], diameter[j]) );

			if (path[i][j] > 0.9 * INF &&

				pot 	 < min)
				  min =	pot;
			 }
	outfile = fopen("cowtour.out", "w");

	fprintf(outfile, "%.6f\n", min);

	return 0;
}




