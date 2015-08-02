#include <iostream.h>
#include <stdio.h>

int N, M;
int out[30];
int outNodes[30][30];
int in[30];
int inNodes[30][30];
float save[30][30];
float ohm[30][30];
int order[30];
float total[30];
int start, finish;

float resist(int a, int b)
{
	int i, j;
	float s = 0; float r;
	if (save[a][b] != -1)
		return save[a][b];
	for (i = 0; i < out[a]; i++)
		for (j = 0; j < in[b]; j++)
		{
			if (outNodes[a][i] == b && inNodes[b][j] == a)
				s += 1 / (ohm[a][outNodes[a][i]]);
			else {
				r = resist(outNodes[a][i], inNodes[b][i]);
				if (r != -1)
					s += 1 / (ohm[a][outNodes[a][i]] + ohm[inNodes[b][j]][b] + r);
			}
		}
	if (!s)
		return -1;
	else
	{	save[a][b] = 1 / s;
		return 1 / s; }
}



main()
{
	int i, j, a, b, input = 1;
	float s, o;
	while (1)
	{
		cin >> M >> start >> finish;
		if (!M && !start && !finish)
			break;
		start--; finish--;
		for (i = 0; i < 30; i++)
			in[i] = out[i] = 0;
		for (i = 0; i < M; i++)
		{
			cin >> a >> b >> o;
			if (a > N)	N = a;
			if (b > N) 	N = b;
			a--; b--;
			for (j = 0; j < in[b]; j++)
				if (inNodes[b][j] == a)
				{	ohm[a][b] = 1 / ( 1 / ohm[a][b] + 1 / o); break; }
			if (j == in[b])
			{
				in[b]++;
				inNodes[b][in[b] - 1] = a;
				out[a]++;
				outNodes[a][out[a] - 1] = b;
				ohm[a][b] = o;
			}
		}

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
			{	if (i == j)
					save[i][j] = 0;
				else
					save[i][j] = -1;
			}

		printf("Case %d: %.2f Ohms\n",  input++, resist(start, finish));
	}

	return 0;
}

