/* @JUDGE_ID: 3207EZ 534 C++ "Modified Floyd-Warshall" */
#include <iostream.h>
#include <stdio.h>
#include <math.h>

int n;
double x[200];
double y[200];
double matrix[20][20];

double d(int i, int j)
{
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];

	return sqrt(dx*dx + dy*dy);
}

double max(double a, double b)
{
	if (a > b)
		return a;
	return b;
}

double min(double a, double b)
{
	if (a > b)
		return b;
	return a;
}

main()
{
	int i, j, k, scen = 1;
	while (1)
	{
		cin >> n;
		if (!n)
			break;

		for (i = 0; i < n; i++)
			cin >> x[i] >> y[i];
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				matrix[i][j] = d(i, j);
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = i + 1; j < n; j++)
					matrix[i][j] = min(matrix[i][j], max(matrix[i][k],matrix[k][j]));

		cout << "Scenario #" << scen++ << endl;
		cout << "Frog Distance = ";
		printf("%.3f", matrix[0][n-1]);
		cout << endl << endl;
	}

	return 0;
}


