#include <iostream.h>

/*
unsigned long cn[500][20];

unsigned long c(int n, int m)
{
	if (m < 0 || m > n)
	{
		return 0; }
	else if (cn[n][m] != 0)
	{  	return cn[n][m]; }

	else if (n == 0)
	{	cn[n][m] = 1;

		return 1;

	} else { cn[n][m] = c(n-1,m) + c(n-1,m-1);

				return cn[n][m]; }
}
*/

unsigned long gcf(unsigned long a, unsigned long b)
{
	if (b == 0)
		return a;
	else
		return gcf(b, a % b);
}

main()
{
	int i, j, n, m; unsigned long p, q, r, s, t;

	while (1)
	{
		cin >> n >> m;

		if (n == 0 && m == 0)
			return 0;
		if (n - m < m)
			m = n - m;
		p = 1; r = 1;
		for (i = 0; i < m; i++)
		{	q = n - i;
			r *= (i + 1);
			s = gcf(q, r);
			r /= s;
			t = gcf(p, r);
			p /= t;
			q /= s;
         r /= t;
			p *= q;
		}
		cout << p << endl;
	}

   return 0;
}





