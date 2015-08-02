#include <iostream.h>
#include <string.h>
#include <stdlib.h>

int graph[20][20];
int history[20];
int in[20];
char vars[20];

int n;
int num(char c)
{
	int i;
	for (i = 0; i < n; i++)
		if (vars[i] == c)
			return i;
}

void explore(int m)
{
	int i, j, aux[20];
	if (!m)
	{  for (i = 0; i < n; i++)
   		cout << vars[history[i]];
		cout << endl;
		return;
	}
	for (j = 0; j < n; j++)
		aux[j] = 0;

	for (i = 0; i < n; i++)
		if (in[i] == 0)
		{
			in[i] = -1;
			for (j = 0; j < n; j++)
				if (graph[i][j])
				{
					graph[i][j] = 0;
					in[j]--;
					aux[j] = 1;
				 }
			history[n - m] = i;
			explore(m - 1);
			for (j = 0; j < n; j++)
				if (aux[j])
				{
					graph[i][j] = 1;
					in[j]++;
					aux[j] = 0;
				}
			in[i] = 0;
		}
}

int cmp(void const *a, void const *b)
{
	char A = *(char *)a;
	char B = *(char *)b;
	if (A > B)
		return 1;
	return -1;
}

main()
{
	char S[100];
	int i, j;

	while (cin.getline(S, 100))
	{
		if (strlen(S) < 3)
			break;
		n = 0;
		for (i = 0; i < strlen(S); i++)
			if (S[i] >= 'a' && S[i] <= 'z')
			{	vars[n] = S[i];
				n++;
			}
		qsort(vars, n, sizeof(char), cmp);
		for (i = 0; i < n; i++)
		{	in[i] = 0;
			for (j = 0; j < n; j++)
				graph[i][j] = 0;
		}

		cin.getline(S, 100);
		for (i = 0; i < strlen(S); i++)
			if (S[i] >= 'a' && S[i] <= 'z')
			{
				j = i;
				i++;
				while (!(S[i] >= 'a' && S[i] <= 'z'))
					i++;
				graph[num(S[j])][num(S[i])] = 1;
				in[num(S[i])]++;
			}
		explore(n);
		cout << endl;
	}

	return 0;
}




