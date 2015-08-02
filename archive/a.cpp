#include <iostream.h>

int left[1000];
int right[1000];
int newl[1000];
int newr[1000];

main()
{
	int M;
	int N;
	int Ncase;
	int i;
	int L;
   int count, good, best, j, jj;

	cin >> Ncase;

	for (i = 0; i < Ncase; i++)
	{
		N = 0;
		L = 0;
		cin >> M;
		while (1)
		{
			cin >> left[N] >> right[N];

			if (left[N] == 0 && right[N] == 0)
				break;
			N++;
		}
      count = 0;

		while(1)
		{
			good = 0;
			best = 0;
			jj = -1;

			for (j = 0; j < N; j++)
			{
				if (left[j] <= L && right[j] > best)
				{	good = 1; best = right[j]; jj = j; }
			}
			if (!good)
				break;
			newl[count] = left[jj];
			newr[count++] = right[jj];
			L = right[jj];
			if (L >= M)
				break;
		}

		if (L < M)
			cout << 0 << endl << endl;
		else {
			cout << count << endl;
			for (j = 0; j < count; j++)
				cout << newl[j] << ' ' << newr[j] << endl;
			cout << endl;
		}
	}

	return 0;
}

