/* @JUDGE_ID: 3207EZ 544 C++ "Semiring extension of Floyd Warshall" */
#include <iostream.h>
#include <string.h>

int n, m, nn;
char names[200][20];
int nameL[200];
long matrix[200][200];

int getName(char c[20])
{
	int i, j, ok;
	for (i = 0; i < nn; i++)
		if (strlen(c) == nameL[i])
		{
			ok = 1;
			for (j = 0; j < strlen(c); j++)
				if (names[i][j] != c[j])
				{	ok = 0; break; }
			if (ok)
				return i;
		}
	nameL[nn] = strlen(c);
	for (i = 0; i < strlen(c); i++)
		names[nn][i] = c[i];
	nn++;
	return n - 1;
}

long max(long a, long b)
{
	if (a > b)
		return a;
	return b;
}

long min(long a, long b)
{
	if (a < b)
		return a;
	return b;
}

main()
{

	int i, j, k, scen = 1;
	long u, pmax;
	char S[20], T[20];

	while (1)
	{
		cin >> n >> m;
		nn = 0;
		if (n == 0)
			break;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				matrix[i][j] = 0;
		for (i = 0; i < m; i++)
		{
			cin >> S >> T >> u;
			matrix[getName(S)][getName(T)] = u;
			matrix[getName(T)][getName(S)] = u;
		}
		cin >> S >> T;
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = i + 1; j < n; j++) {
					pmax = min(matrix[i][k],matrix[j][k]);
					if (pmax > matrix[i][j])
						matrix[i][j] = pmax;
					matrix[j][i] = matrix[i][j];
				}
		cout << "Scenario #" << scen++ << endl;
		cout << matrix[getName(S)][getName(T)] << " tons" << endl << endl;
	}

	return 0;
}
