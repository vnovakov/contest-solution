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

#include <fstream.h>

ifstream infile("sort3.in");
ofstream outfile("sort3.out");

int array[1000];
int sorted[1000];
int n;


int min(int a, int b)
{
	return (a < b) ? a : b;
}

main()
{
	int i, j, k;
	int count[3] = {0,0,0};
	int matrix[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
	int a, total;

	int nSwaps = 0;

	infile >> n;

	for (i = 0; i < n; i++)
	{
		infile >> k;
		array[i] = k - 1;
	}

	for (i = 0; i < n; i++)
		count[array[i]]++;

	for (i = 0; i < count[0]; i++)
		sorted[i] = 0;

	for (i = count[0]; i < count[0] + count[1]; i++)
		sorted[i] = 1;

	for (i = count[0] + count[1]; i < n; i++)
		sorted[i] = 2;

	for (i = 0; i < n; i++)
		matrix[array[i]][sorted[i]]++;

	total = 0;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (i != j)
			{
				a = min(matrix[i][j], matrix[j][i]);
				matrix[i][j] -= a;
				matrix[j][i] -= a;
				total += a;
			}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 3; k++)
				if (i != j && i != k && j != k)
				{
					a = min(matrix[i][j], min(matrix[j][k], matrix[k][i]));
					matrix[i][j] -= a;
					matrix[j][k] -= a;
					matrix[k][i] -= a;
					total += 2*a;
				}
	outfile << total << endl;

	return 0;
}

//### End
