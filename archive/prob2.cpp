### Program

#pragma option -O2

/*

Problem: 2
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

int matrix[100][100];

main()
{
	int N;
	int a[100];
	int b[100];
	int in[100];
	int done[100];
	int i, j, k;
	int topSort[100];
	int best[100];
	int max;

	infile >> N;

	for (i = 0; i < N; i++)
		infile >> a[i] >> b[i];

	for (i = 0; i < N; i++)
	{
		done[i] = 0;
		in[i] = 0;
	}

	for (i = 0; i < N; i++)
	for (j = 0; j < N; j++)
	{
	if ((i != j) && 
	((a[i] <= a[j] && b[i] <= b[j]) ||
	  (a[i] <= b[j] && b[i] <= a[j])))

	{
	if ((a[i] == a[j] && b[i] == b[j]) ||
	  (a[i] == b[j] && b[i] == a[j]))
	matrix[i][j] = (i > j) ? 1 : 0;
	else
	matrix[i][j] = 1;
	}
	else
		matrix[i][j] = 0;

	in[j] += matrix[i][j];
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			if (in[j] == 0 && !done[j])
			{	k = j; break; }
		done[k] = 1;
		topSort[i] = k;
		for (j = 0; j < N; j++)
			if (matrix[k][j])
				in[j]--;
	}



	best[N - 1] = 1;

	for (i = N - 2; i >= 0; i--)
	{
		max = 1;
		for (j = i + 1; j < N; j++)
		if (matrix[topSort[i]][topSort[j]]
			  && (best[j] + 1 > max))
		max = best[j] + 1;
		best[i] = max;
	}

	max = 0;
	for (i = 0; i < N; i++)
	{
		if (best[i] > max)
			max = best[i];
	}

	outfile << max << endl;



	return 0;

}



### End