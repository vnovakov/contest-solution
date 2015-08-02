#include <iostream.h>

int K, a[100], b[100];
int matrix[100][100];

int min(int x, int y)
{
	return (x < y) ? x : y;
}

main()
{
	int nInp;
	int M, N;
   int i, j;
	cin >> nInp;

	while (nInp--)
	{
		cin >> K;
		for (i = 0; i < K; i++)
			cin >> a[K - 1 - i];
		for (i = 0; i < K; i++)
			cin >> b[i];

		M = 0;
		N = 0;
		for (i = 0; i < K; i++)
			for (j = 0; j < K; j++)
			{	matrix[i][j] = 0;
				N += min (a[i], b[j]);
			}
		for (i = 0; i < K; i++)
		{
			for (j = 0; j < K; j++)
				if (a[i] == b[j])
				{	matrix[i][j] = a[i]; break; }
			if (j == K)
			{
				for (j = 0; j < K; j++)
					if (a[i] <= b[j])
					{	matrix[i][j] = a[i]; break; }
			}
		}
		for (i = 0; i < K; i++)
		{
			for (j = 0; j < K; j++)
				if (b[i] == a[j])
				{	matrix[j][i] = b[i]; break; }
			if (j == K)
			{
				for (j = 0; j < K; j++)
					if (b[i] <= a[j])
					{	matrix[j][i] = b[i]; break; }
			}
		}
		for (i = 0; i < K; i++)
			for (j = 0; j < K; j++)
         	M += matrix[i][j];

		cout << "Matty needs at least " <<
					M << " blocks, and can add at most "
					<< N - M << " extra blocks." << endl;
	}

	return 0;
}
