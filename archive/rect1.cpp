#include <fstream.h>
#include <stdlib.h>

ifstream infile("rect1.in");
ofstream outfile("rect1.out");

int huge color[800][800];
int M, N, C;
int size[100];
int perm[100];

int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;

	if (size[A] > size[B])
		return 1;
	return -1;
}

main()
{
	int i, j, a, b, x, y, c;


	infile >> M >> N >> C;

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)

			color[i][j] = 1;

	for (i = 0; i < 100; i++)
	{ perm[i] = i; size[i] = 0; }
	for (i = 1; i <= C; i++)
	{
		infile >> a >> b >> x >> y >> c;


		for (; a < x; a++)
			for (j = b; j < y; j++)
				color[a][j] = c;
	}

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			size[color[i][j] - 1]++;

	qsort(perm, 100, sizeof(int), cmp);

	for (i = 0; i < 100; i++)
   	if (size[perm[i]])
		outfile << perm[i] + 1 << ' ' << size[perm[i]] << endl;

	return 0;
}


