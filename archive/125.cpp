/* @JUDGE_ID: 3207EZ 125 "Kleene's Algorithm" */
#include <iostream.h>

int c[31][30][30];
const int INF = -1;

main()
{
	int nCity = 0, n, m, i, j, k;

	while (cin >> m)
	{
		n = 0;
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
				c[0][i][j] = 0;
		for (i = 0; i < m; i++)
		{	cin >> j >> k;
			if (j + 1 > n) n = j + 1;
			if (k + 1 > n) n = k + 1;
			c[0][j][k] = 1;
		}
		for (k = 1; k <= n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (c[k-1][i][j] == INF ||
						(c[k-1][i][k-1] == INF && c[k-1][k-1][j] != 0) ||
						(c[k-1][i][k-1] != 0 &&	c[k-1][k-1][j] == INF) ||
						(c[k-1][i][k-1] != 0 && c[k-1][k-1][j] != 0 &&
						 c[k-1][k-1][k-1] != 0)) 
						c[k][i][j] = INF;
					else
						c[k][i][j] = c[k-1][i][j] + c[k-1][i][k-1]*c[k-1][k-1][j];
				}
		cout << "matrix for city " << nCity++ << endl;

		for (i = 0; i < n; i++)
		{
			cout << c[n][i][0];
			for (j = 1; j < n; j++)
				cout << " " << c[n][i][j];
			cout << endl;
		}

	}

	return 0;
}
