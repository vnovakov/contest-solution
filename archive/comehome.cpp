### PROGRAM
/*
ID: vnovako001
PROG: comehome
*/

#include <fstream.h>

ifstream infile("comehome.in");
ofstream outfile("comehome.out");

int N = 52;
long graph[52][52];

long lINF = 20000000;

inline int index(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	else
		return 26 + c - 'A';
}

main()
{
	long d[52], min;
	int visited[52];
	int i, j, l;
	char a, b;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			graph[i][j] = lINF;

	infile >> i;

	while (infile >> a >> b >> l)
	{
		if (l < graph[index(a)][index(b)])
		graph[index(a)][index(b)] =
		graph[index(b)][index(a)] = l;
	}

	for (i = 0; i < N; i++)
	{	visited[i] = 0;
		d[i] = lINF;
	}

	d[N - 1] = 0;

	while (1)
	{
		min = lINF;

		for (i = 0; i < N; i++)
			if (!visited[i] && d[i] < min)
			{	j = i; min = d[i]; }

		if (min == lINF)
			break;

		visited[j] = 1;

		for (i = 0; i < N; i++)
			if (d[i] > d[j] + graph[i][j])
				d[i] = d[j] + graph[i][j];

	}

	min = lINF;

	for (i = 26; i < 51; i++)
	{
		if (d[i] < min)
		{	min = d[i]; j = i; }
	}

	outfile << (char)(j - 26 + 'A') << ' '  << min << endl;

	return 0;
}

//### END
