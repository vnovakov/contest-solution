/* @JUDGE_ID: 3207EZ 562 C++ "Dynamic programming" */
#include <iostream.h>

char array[50001];

int mmin(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int mmax(int a, int b)
{
	if (b < a)
		return a;
	return b;
}

main()
{
	int h, i, j, m, n, s, ss, max, nmax, rmax;
	int values[100];

	cin >> m;

	for (h = 0; h < m; h++)
	{
		cin >> n;
		s = 0;
		for (i = 0; i < n; i++)
		{
			cin >> values[i]; s += values[i]; }
		for (i = 0; 2*i <= s; i++)
			array[i] = 0;
		array[0] = 1;
		max = 0;
		ss = s;
      rmax = 0;
		for (j = 0; j < n; j++)
		{
			nmax = 0;

			for (i = mmin(max, s/2); i >= mmax(0,rmax - ss); i--)
				if (array[i])
				{	array[i + values[j]] = 1;
					if (i + values[j] > nmax)
						nmax = i + values[j];
					if (i + values[j] > rmax && i + values[j] <= s / 2)
						rmax = i + values[j];
				}
			if (nmax > max)
				max = nmax;
			if (array[s/2] == 1)
				break;
			ss -= values[j];
		}
		for (j = s / 2; j >= 0; j--)
		{
			if (array[j])
			{	cout << s - 2*j << endl; break; }
		}
	}

	return 0;
}


