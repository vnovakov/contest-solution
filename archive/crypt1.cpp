#include <fstream.h>

ifstream infile("crypt1.in");
ofstream outfile("crypt1.out");

int n;
int D[9];
int used[10] = {0,0,0,0,0,0,0,0,0,0};

int works(long p)
{
	int ret =1;
	while (p)
	{
		if (!used[p % 10])
		{
			ret = 0;
			break;
		}
		p /= 10;
	}


	return ret;
}

main()
{
	int a, b, c, d, e;
	int ia, ib, ic, id, ie, i;
	long X, Y;
	long P, Q;
	long nsol = 0;

	infile >> n;

	for (i = 0; i < n; i++)
	{
		infile >> D[i];
		used[D[i]] = 1;
	}

	for (ia = 0; ia < n; ia++)
	for (ib = 0; ib < n; ib++)
	for (ic = 0; ic < n; ic++)
	for (id = 0; id < n; id++)
	for (ie = 0; ie < n; ie++)
	{

		a = D[ia];
		b = D[ib];
		c = D[ic];
		d = D[id];
		e = D[ie];

		X = 100*a + 10*b + c;
		Y = 10*d + e;

		P = e * X;
		Q = d * X;

		if (works(P) && works(Q))
			if (works(10*Q + P) == 1)
			 nsol++;

	}

	outfile << nsol << endl;

	return 0;
}
