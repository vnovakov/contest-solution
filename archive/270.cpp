/* @JUDGE_ID: 3207EZ 270 C++ */
#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

long x[700], y[700];
int eq[700];
double angle[700];
double TOL = 0.00000000001;
int N;

int cmp(void const *a, void const *b)
{
	double A = *(double *)a;
	double B = *(double *)b;
	if ((A - B) < TOL && (B - A) < TOL)
		return 0;
	return (A > B) ? 1 : -1;
}

main()
{
	int c, stage, i, j, n, max = 2;
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
		stage = 0;
		x[N] = y[N] = 0;
		for (i = 0; i < strlen(S); i++)
		{
		if (S[i] == ' ')
			stage = 1;
			else if (stage)
				y[N] = 10*y[N] + S[i] - '0';
			else
				x[N] = 10*x[N] + S[i] - '0';
		}
		N++;

	}


	for (n = 0; n < N; n++)
	{
		for (i = 0; i < N; i++)
		{	eq[i] = 2;
			if (i == n)
				angle[i] = 2;
			else
				angle[i] = atan2(y[i] - y[n], x[i] - x[n]);

		}
		qsort(angle, N, sizeof(double), cmp);
		for (i = 0; i < N; i++)
		{	j = 0;
			while (i < N - 1 && (angle[i] - angle[i + 1]) < TOL &&
								 (angle[i + 1] - angle[i]) < TOL)
			{
				eq[i - j]++;
				if (eq[i - j] > max)
					max = eq[i - j];

				i++; j++;
			}
		}
	}

	cout << max << endl << endl;

	}

	return 0;
}

