/* @JUDGE_ID: 3207EZ 590 C++ "k*n^2 DP" */
#include <iostream.h>

int dayMod[10][10];
int days[10][10][30];
long best[1001][10];

int n, k;

main()
{
	int i, j, l, scen = 1;
	long o, pmin, min;

	while (1)
	{
		cin >> n >> k;
		if (n + k == 0)
			break;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (i != j) {
					cin >> dayMod[i][j];
					for (l = 0; l < dayMod[i][j]; l++)
						cin >> days[i][j][l];
					}
		for (i = 0; i < n; i++)
			best[0][i] = -1;
		best[0][0] = 0;

		for (i = 1; i <= k; i++)
		{
			for (j = 0; j < n; j++)
			{
				min = -1;

				for (l = 0; l < n; l++)
				{
					if (j != l) {
					o = days[l][j][(i - 1) % dayMod[l][j]];
					pmin = o + best[i-1][l];
					if ((o != 0)
						&& (best[i-1][l] != -1) && ((min == -1) || (pmin < min)))
						min = pmin;
					}
				}
				best[i][j] = min;
			}
		}

		cout << "Scenario #" << scen++ << endl;
		if (best[k][n-1] == -1)
			cout << "No flight possible." << endl;
		else
			cout << "The best flight costs " << best[k][n-1] << "." << endl;
		cout << endl;
	}

	return 0;
}


