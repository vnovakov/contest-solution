/* @JUDGE_ID: 3207EZ 116 C++ "DP" */
#include <iostream.h>

long matrix[10][100];
long minSum[10][100];
int link[10][100];

int m, n;

main()
{
	int i, j, jj, k, l, mm;
	long min;
	while (cin >> m >> n)
	{
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++) {
				cin >> matrix[i][j];
				if (j + 1 == n)
					minSum[i][j] = matrix[i][j];

			}

		for (i = n - 2; i >= 0; i--)
			for (j = 0; j < m; j++) {
				min = minSum[j][i+1];
				link[j][i] = j;
				for (k = -1; k <= 1; k++)
				{
					mm = j + k;
					if (mm < 0)
						mm += m;
					if (mm >= m)
						mm -= m;
					if (minSum[mm][i + 1] < min ||
					(mm <= link[j][i] && minSum[mm][i + 1] == min))
					{	min = minSum[mm][i + 1]; link[j][i] = mm; }
				}
				minSum[j][i] = min + matrix[j][i];
			}


		min = minSum[0][0];
      j = 0;
		for (i = 0; i < m; i++)
			if (minSum[i][0] < min)
			{
				min = minSum[i][0];
				j = i;
			}
		cout << j + 1;
		jj = j;
		for (i = 0; i < n - 1; i++)
		{	cout << " " << link[j][i] + 1; j = link[j][i]; }
		cout << endl;
		cout << minSum[jj][0] << endl;
	}

	return 0;
}
