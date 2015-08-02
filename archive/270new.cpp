/* @JUDGE_ID: 3207EZ 270 C++ */
#include <iostream.h>
#include <stdlib.h>
#include <string.h>

long x[700], y[700];
long X, Y;
int perm[700];
int N;

int cmp(int i, int j)
{
	long A = (y[i] - Y)*(x[j] - X);
	long B = (y[j] - Y)*(x[i] - X);
	if (i == j)
		return 0;
	if (A > B)
		return 1;
	else if (A == B)
		return 0;
	else
		return -1;
}


int Qcmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;

   return cmp(A, B);
}

main()
{
	int c, stage, i, j, n, eq, max;
	int nInput;
	char S[20];
	n = 0;

	cin >> nInput;
	cin.getline(S, 20);
	cin.getline(S, 20);

	while (nInput--)
	{
		max = 2;
		N = 0;
	while (1)
	{
		cin.getline(S, 20);

		if (strlen(S) == 0 || cin.eof())
			break;

		stage = -1;
		x[N] = y[N] = 0;
		for (i = 0; i < strlen(S); i++)
		{
		if (S[i] == ' ' && stage == 0)
			stage = 1;
		else if (S[i] >= '0' && S[i] <= '9')
		{
			if (stage == -1)
         	stage = 0;
			if (stage)
				y[N] = 10*y[N] + S[i] - '0';
			else
				x[N] = 10*x[N] + S[i] - '0';
		}
		}

		if (x[N] > 40000 || y[N] > 40000)
		{
			for(;;)
				;
		}
		N++;

	}


	for (n = 0; n < N; n++)
	{
		for (i = 0; i < N; i++)
		{
			if (i < n)
				perm[i] = i;
			else if (i > n)
				perm[i - 1] = i;
		}
		X = x[n];
      Y = y[n];
		qsort(perm, N - 1, sizeof(int), Qcmp);
		eq = 1;
		for (i = 0; i < N - 2; i++)
		{
			if (cmp(perm[i], perm[i + 1]) == 0)
				eq++;
			else
				eq = 1;
			if (eq + 1 > max)
				max = eq + 1;
		}
	}

	cout << max << endl << endl;

	}

	return 0;
}

