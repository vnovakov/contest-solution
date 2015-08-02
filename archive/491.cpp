/* @JUDGE_ID: 3207EZ 101 C++ */
#include <iostream.h>
#include <fstream.h>
#include <string.h>

ifstream infile("491.in");

main()
{
	int N, a[1000], i, j, k, max = 0, r;
	int best[1000];
	int parent[1000];
	int b[1000];
	char S[100];

	N = 0;

	while (1)
	{
		r = infile.eof();
		infile.getline(S,100);


		if (strlen(S) == 0 || r == 1)
		{

			max = 0;
			best[0] = 1;
			parent[0] = -1;

		for (i = 1; i < N; i++)
		{
			best[i] = 1;

			for (j = i - 1; j >= 0; j--)
				if (a[i] > a[j] && best[j] + 1 > best[i])
				{
					best[i] = best[j] + 1;
					parent[i] = j;
				}
			if (best[i] == 1)
				parent[i] = -1;
			if (best[i] > max)
			{
				max = best[i];
				k = i;
			}
		}

		N = 0;
		while (k != -1)
		{
			b[N++] = a[k];
			k = parent[k];
		}

		cout << "Max hits: " << max << endl;
		for (i = 0; i < max; i++)
			cout << b[max - 1 - i] << endl;
		cout << endl;

		N = 0;

		}  else {
			a[N] = 0;
			for (i = 0; i < strlen(S); i++)
				a[N] = 10*a[N] + S[i] - '0';
			N++;
		}
		if (r == 1)
			break;

	}
	return 0;
}