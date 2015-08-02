#include <fstream.h>

ifstream infile("game1.in");
ofstream outfile("game1.out");

int  best[100][100];
char set[100][100];
int array[100];
int N;

int max(int a, int b)
{
	if (a > b) return a;
	return b;
}

int min(int a, int b)
{	if (a < b) return a;
	return b;
}


int compute1(int a, int b)
{
	int p, q;
	if (set[a][b])
		return best[a][b];
	else if (a > b)
		return 0;
	else if (a == b)
   	return array[a];
	else {
		p = array[a] + min ( compute1(a+2,b), compute1(a+1,b-1));
		q = array[b] + min ( compute1(a,b-2), compute1(a+1,b-1));
		set[a][b] = 1;
		best[a][b] = max(p, q);
		return best[a][b];
	}
}


main()
{
	int i, j, sum = 0;

	infile >> N;

	for (i = 0; i < N; i++)
	{
		infile >> array[i];
		sum += array[i];
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
		{
			set[i][j] = 0;
			best[i][j] = 0;
		}
	outfile << compute1(0, N - 1) << ' ';

	outfile << sum - compute1(0, N - 1) << endl;

	return 0;
}


