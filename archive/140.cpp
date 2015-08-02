/* @JUDGE_ID: 3207EZ 140 C++ */
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

int graph[8][8];
char names[8];
int n;
int minBand;
int lexy[8];
int order[8];
int best[8];
int used[8];


void explore(int p)
{
	int i, j, max;


	max = 0;
	for (i = 0; i < n - p - 1; i++)
		if (graph[order[n - p - 1]][order[i]])
			if (n - p - 1 - i > max)
				max = n - p - 1 - i;
	if (max >= minBand)
		return;

	for (i = 0; i < n; i++)
	{
		j = lexy[i];
		if (!used[j])
		{
			used[j] = 1;
			order[n - p] = j;
			explore(p - 1);
			used[j] = 0;
		}
	}
	if (p == 0)
	{
		max = 0;
		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
				if (graph[order[i]][order[j]])
					if (j - i > max)
						max = j - i;
		if (max < minBand)
		{
			minBand = max;
			for (i = 0; i < n; i++)
				best[i] = order[i];
		}
	}
}

int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;
	if (names[A] > names[B])
		return 1;
	return -1;
}

int num(char c)
{
	int i;
	for (i = 0; i < n; i++)
		if (names[i] == c)
			return i;
	names[n] = c;
	n++;
	return n - 1;
}

main()
{
	int i, j, u, v;
	char S[50];

	while (cin.getline(S, 50))
	{
		if (S[0] == '#')
			break;
		n = 0;
		u = num(S[0]);

		for (i = 0; i < 8; i++)
		{	used[i] = 0;
			lexy[i] = i;
			for (j = 0; j < 8; j++)
				graph[i][j] = 0;
		}

		for (i = 2; i < strlen(S); i++)
			if (S[i] == ';')
			{
				i += 2;
				u = num(S[i - 1]);
			}
			else {
				v = num(S[i]);
				graph[u][v] = graph[v][u] = 1;
			}
		minBand = 100;
		qsort(lexy, n, sizeof(int), cmp);
		explore(n);

		for (i = 0; i < n; i++)
			cout << names[best[i]] << " ";
		cout << "-> ";
		cout << minBand;
		cout << endl;
	}

	return 0;
}

