//### PROGRAM
/*
ID: vnovako001
PROG: kimbits
*/
#include <fstream.h>

ifstream infile("kimbits.in");
ofstream outfile("kimbits.out");

typedef unsigned long u32;

u32 Snumber[33][33];
int store[33][33];

u32 number(int a, int b)
{
	u32 stored;

	if (store[a][b])
		return Snumber[a][b];

	if (!a)
   	stored = 0;
	if (!b)
		stored = 1;
	else if (a == b)
		stored = 2 * number(a - 1, b - 1);
	else
		stored = number(a - 1, b) + number(a - 1, b - 1);

	store[a][b] = 1;
	Snumber[a][b] = stored;

	return stored;
}

void print(int n, int m, u32 index)
{
	u32 with0;
	u32 with1;

	if (!n)
		return;

	if (!m)
	{
		while (n--)
			outfile << 0;
		return;
	}

	if (m != n)
		with0 = number(n - 1,m);
	else
		with0 = number(n - 1,n - 1);
	with1 = number(n - 1, m - 1);



	if (index <= with0)
	{
		outfile << 0;
		if (m != n)
			print (n - 1, m, index);
		else
			print(n - 1, n - 1, index);
	} else
	{
		outfile << 1;
		print (n - 1, m - 1, index - with0);
	}
}

main()
{

	int N, M;
   int i, j;
	u32 index;

	infile >> N >> M >> index;

	for (i = 0; i <= N; i++)
		for (j = 0; j <= i; j++)
			store[i][j] = 0;

	print(N, M, index);

   outfile << endl;

	return 0;
}

//### END
