/* @JUDGE_ID: 3207EZ 544 C++ "O(n^2)" */
#include <iostream.h>
#include <string.h>

int n, m, nn;
char names[200][20];
int nameL[200];
int matrix[200][200];
int maxMin[200];
const int INF = 20000;

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
	return nn - 1;
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

main()
{

	int i, j, k, scen = 1;
	long u, pmax;
	int v, w;
	char S[20], T[20];
	int visited[200], nV;

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
			v = getName(S);
			w = getName(T);
			matrix[v][w] = u;
			matrix[w][v] = u;
		}
		cin >> S >> T;
		v = getName(S);
		w = getName(T);

		for (i = 0; i < n; i++)
		{	maxMin[i] = 0;
			visited[i] = 0;
		}
		maxMin[v] = INF;
		nV = 0;

		while (nV != n)
		{
			pmax = 0;
			for (i = 0; i < n; i++)
				if (visited[i] == 0 && maxMin[i] > pmax)
				{	j = i; pmax = maxMin[i]; }
			visited[j] = 1;
			for (i = 0; i < n; i++)
				if (matrix[j][i] && min(pmax, matrix[j][i]) > maxMin[i])
					maxMin[i] = min(pmax, matrix[j][i]);
			nV++;
			if (j == w)
				break;
		}

		cout << "Scenario #" << scen++ << endl;
		cout << maxMin[w] << " tons" << endl << endl;
	}

	return 0;
}

