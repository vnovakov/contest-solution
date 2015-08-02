/* @JUDGE_ID: 3207EZ 567 C++ "Floyd-Warshall" */
#include <iostream.h>
#include <iomanip.h>

int matrix[20][20];
int dist[20][20];

main()
{
	int a;
	int i, j, k, ca = 1, yes;

	while (!cin.eof())
	{
		for (i = 0; i < 20; i++)
			for (j = 0; j < 20; j++)
				matrix[i][j] = 1000;
		yes = 0;
		for (i = 0; i < 19; i++)
		{
			if (!(cin >> a))
				return 0;
			for (j = 0; j < a; j++)
			{
				yes = 1;
				cin >> k;
				matrix[i][k - 1] = matrix[k - 1][i] = 1;
			}
		}
		if (!yes)
			break;

		for (i = 0; i < 20; i++)

			for (j = 0; j < 20; j++)
				dist[i][j] = matrix[i][j];


		for (k = 0; k < 20; k++)
			for (i = 0; i < 20; i++)
				for (j = 0; j < 20; j++)
					if (dist[i][k] + dist[k][j] < dist[i][j])
					{	dist[i][j] = dist[i][k] + dist[k][j];
						dist[j][i] = dist[i][k] + dist[k][j]; }

		cin >> a;

		cout << "Test Set #" << ca;
		ca++;
		cout << endl;
		for (i = 0; i < a; i++)
		{
			cin >> j >> k;
			cout << setw(2) << j << " to" << setw(3) << k << ": " << dist[j-1][k-1];
			cout << endl;
		}
		cout << endl;
	}

	return 0;
}
