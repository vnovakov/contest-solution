#include <iostream.h>
#include <stdlib.h>

int n;
int matrix[100][100];
int aux[100][100];
int curr[100];

main()
{
	 int i, j, k, m = -128;

	 cin >> n;

	 for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			{	cin >> matrix[i][j]; aux[i][j] = 0; }

	 for (i = n - 1; i >= 0; i--)
	 {
		for (j = i; j < n; j++)
			for (k = 0; k < n; k++)
				aux[j][k] += matrix[i][k];
		for (j = i; j < n; j++)
		{
			curr[0] = aux[j][0];
			if (curr[0] > m)
				m = curr[0];
			for (k = 1; k < n; k++) {
				curr[k] = max(curr[k-1]+aux[j][k], aux[j][k]);
				if (curr[k] > m)
					m = curr[k];
			}
		}
	 }

	 cout << m << endl;
}



