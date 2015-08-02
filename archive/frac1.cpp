#include <fstream.h>

ifstream infile("frac1.in");
ofstream outfile("frac1.out");


int N;

int gcf(int a, int b)
{
	if (!b)
		return a;
	return gcf(b, a % b);
}

int solve(int a, int b)
{
	long sol = 1;
   int count = -1;
	int i;
	// solves ax = 1 (mod b)
	// finds a^(phi(b) - 1)
	for (i = 1; i <= b; i++)
	{
		if (gcf(i, b) == 1)
		{
			count++;
			if (count)
			{
				sol *= (long)a;
				sol = sol % b;
			}
		}
	}

	return sol;
}

float TOL = 0.000001;

main()
{

	infile >> N;

	int a, b, m, n, useM, useN;
	float diff, bestDiff;

	a = 0;
	b = 1;
	m = 1;
	n = N;

	outfile << a << '/' << b << endl;
	outfile << m << '/' << n << endl;

	a = m;
	b = n;

	while (a != b)
	{

		n = solve(b - a, b);
		m = (a*n + 1) / b;

		diff = ((float)m / n - (float)a / b);
		if (diff > TOL)
		{
			useM = m;
			useN = n;
			bestDiff = diff;
		}
		else
			bestDiff = 1.0;

		while (n + b <= N)
		{
			m += a;
			n += b;

			diff = ((float)m / n - (float)a / b);
			if (diff > TOL && diff < bestDiff)
			{
				useM = m;
				useN = n;
				bestDiff = diff;
			}
		}

		m = useM;
		n = useN;

		outfile << m << '/' << n << endl;

		a = m;
		b = n;
	}

	return 0;
}
