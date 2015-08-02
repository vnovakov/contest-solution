/* @JUDGE_ID: 3207EZ 534 C++ "Modified Dijkstra" */
#include <iostream.h>
#include <stdio.h>
#include <math.h>

int n;
double x[200];
double y[200];
double max[200];
int visited[200];

double d(int i, int j)
{
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];

	return sqrt(dx*dx + dy*dy);
}

double mm(double a, double b)
{
	if ( a > b)
		return a;
	return b;
}

main()
{
	int i, v, scen = 1; double min, pmin, pmax;
	while (1)
	{
		cin >> n;
		if (!n)
			break;

		for (i = 0; i < n; i++)
			cin >> x[i] >> y[i];

		for (i = 0; i < n; i++)
		{	visited[i] = 0; max[i] = 2000; }

		max[0] = 0;

		while (1)
		{
			for (i = 0; i < n; i++)
				if (!visited[i])
					goto proceed;
			break;

			proceed:
			;
			min = 2000;
			for (i = 0; i < n; i++)
				if (!visited[i] && max[i] < min)
				{	min = max[i]; v = i; }
			visited[v] = 1;
			for (i = 0; i < n; i++)
				if (!visited[i])
				{
					pmax = mm (max[v], d(i, v));
					if (max[i] > pmax)
						max[i] = pmax;
				}
		}
		cout << "Scenario #" << scen++ << endl;
		cout << "Frog Distance = ";
		printf("%.3f", max[n-1]);
		cout << endl << endl;
	}

	return 0;
}
