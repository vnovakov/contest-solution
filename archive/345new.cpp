/* @JUDGE_ID: 3207EZ 345 C++ "Iterative" */
#include <iostream.h>
#include <stdio.h>

int N, M;
float matrix[60][60];
int used[60][60];
int names[60];
int start, finish;
int visited[60];

int getName(int name)
{
	int i;
	for (i = 0; i < N; i++)
		if (names[i] == name)
			return i;
	names[N] = name;
	N++;
	return N - 1;
}

void setMatrix(int i, int j, float value)
{
	if (matrix[i][j] == -1)
		matrix[i][j] = value;
	else
		matrix[i][j] = 1 / (1 / matrix[i][j] + 1 / value);
}

void explore(int v)
{
	int i;
	visited[v] = 1;
	for (i = 0; i < N; i++)
		if (matrix[i][v] != -1 && !visited[i])
			explore(i);
}


main()
{
	int i, j, k, l, in, out, a, b, input = 1;
   int changes;
	float o;
	while (1)
	{
   	N = 0;
		cin >> M >> start >> finish;
		if (!M && !start && !finish)
			break;
		start = getName(start);
		finish = getName(finish);
		for (i = 0; i < 60; i++)
		{	visited[i] = 0;
			for (j = 0; j < 60; j++)
			{	used[i][j] = 0;
				matrix[i][j] = -1;
			}
		}

		for (i = 0; i < M; i++)
		{
			cin >> a >> b >> o;

			setMatrix(getName(a), getName(b), o);
		}

		explore(finish);

		if (!visited[start])
		{
			for (;;)
				;
		}

		changes = 1;

		while (changes)
		{
			changes = 0;
			for (i = 0; i < N; i++)
				if (visited[i])
				{
					in = 0; out = 0;

					for (j = 0; j < N; j++)
						if (visited[j] && matrix[i][j] != -1 && !used[i][j])
						{	l = j; out++; }
					for (j = 0; j < N; j++)
						if (visited[j] && matrix[j][i] != -1 && !used[i][j])
						{	k = j; in++; }

						if (in == 1 && out == 1)
					{	changes = 1;
						setMatrix(k, l, matrix[i][l] + matrix[k][i]);
						used[i][l] = 1;
						used[k][i] = 1;
				}
			}
		}

		printf("Case %d: %.2f Ohms\n",  input++, matrix[start][finish]);
	}

	return 0;
}

