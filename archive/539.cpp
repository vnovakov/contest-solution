/* @JUDGE_ID: 3207EZ 539 C++ */
#include <iostream.h>

int e, v;
int matrix[25][25];
int curr, visit[25];

int longest(int u)
{
	int max = 0, back, pmax, i;

	for (i = 0; i < v; i++)
		if (matrix[i][u])
		{
			back = matrix[i][u];
			matrix[i][u] = 0;
			matrix[u][i] = 0;
			curr++;
			visit[curr] = i;
			pmax = longest(i) + 1;
         curr--;
			if (pmax > max)
				max = pmax;
			matrix[i][u] = back;
			matrix[u][i] = back;
		}

	return max;
}

main()
{
	int i, j, a, b, max, pmax;
	while(1)
	{
		cin >> v >> e;
		if (v + e == 0)
			break;

		for (i = 0; i < v; i++)
			for (j = 0; j < v; j++)
				matrix[i][j] = 0;

		for (i = 0; i < e; i++)
		{
			cin >> a >> b;
			matrix[a][b] = 1;
			matrix[b][a] = 1;
		}

		max = 0;

		for (i = 0; i < v; i++)
		{
			curr = 0;
			visit[0] = i;
			pmax = longest(i);
			if (pmax > max)
				max = pmax;
		}

		cout << max << endl;

	}

	return 0;
}
