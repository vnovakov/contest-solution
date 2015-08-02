### PROGRAM
/*
ID: vnovako001
PROG: barn1
*/

#include <fstream.h>


void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

main()
{
	int j, m, s, c, t, max = 0, min = 201, ii;
	int i;
	int a[200];
	int b[199];
	ifstream infile("barn1.in");
	ofstream outfile("barn1.out");
	infile >> m >> s >> c;

	for (i = 0; i < c; i++)
	{	infile >> a[i]; if (a[i] > max) max = a[i];
							 if (a[i] < min) min = a[i];
	}
	// sort a

	for (i = 0; i < c - 1; i++)
	{  ii = i;
		for (j = i; j < c; j++)
			if (a[j] < a[ii]) ii = j;
		swap(a[i], a[ii]);
	}

	for (i = 0; i < c - 1; i++)
		b[i] = a[i+1] - a[i];

	t = max - min + 1;

	ii = 0;

	while (m > 1 && ii != -1)
	{
		m--;
		max = 0;
		ii = -1;
		for (i = 0; i < c - 1; i++)
			if (b[i] > max) { max = b[i]; ii = i; }
		if (ii != -1)
		{  t -= b[ii] - 1;
			b[ii] = 0;
		}
	}

	outfile << t << endl;
}

### END


