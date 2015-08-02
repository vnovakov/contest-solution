#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

ifstream infile("INPUT.TXT");

long x[700], y[700];
int N;

double d(int i, int j)
{
	double dx = x[i] - x[j];
	double dy = y[i] - y[j];

	return sqrt(dx*dx + dy*dy);
}

int eq(double a, double b)
{
	if ((a - b) < 0.0001 && (b - a) < 0.0001)
		return 1;
	else
		return 0;
}

main()
{
	int  stage, i, j, n, k, l, max;
	int nInput;
	char S[20];
	n = 0;

	infile >> nInput;
	infile.getline(S, 20);
	infile.getline(S, 20);

	while (nInput--)
	{
		max = 2;
		N = 0;
	while (1)
	{
		infile.getline(S, 20);

		if (strlen(S) == 0 || infile.eof())
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

		N++;

	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (i != j)
			{
				l = 0;
				for (k = 0; k < N; k++)
					if (eq(d(i, k) + d(k, j), d(i, j)))
						l++;
				if (l > max)
				{
					cout << max << endl << endl;
					max = l;
				}
			}

	cout << max << endl << endl;

	}

	return 0;
}
