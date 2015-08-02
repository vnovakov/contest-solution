#include <fstream.h>
#include <string.h>

ifstream infile("gift1.in");
ofstream outfile("gift1.out");


int n;
int people[10];
int nameL[10];
char names[10][12];

int lookup(char S[12])
{
	int j, k, same;
	for (j = 0; j < n; j++)
	{
		if (strlen(S) == nameL[j])
		{
			same = 1;
			for (k = 0; k < nameL[j]; k++)
			{
				if (names[j][k] != S[k])
				{	same = 0; break; }
			}
			if (same)
				return j;
		}
	}
}

main()
{
	int i, j, m, f, a, b;
	char S[12]; char T[12];

	  infile >> n;

		for (i = 0; i < n; i++)
		{
			people[i] = 0;
			infile >> S;
			nameL[i] = strlen(S);
			for (j = 0; j < nameL[i]; j++)
				names[i][j] = S[j];
		}
		for (i = 0; i < n; i++)
		{
			infile >> S;
			a = lookup(S);
			infile >> m;
			infile >> f;
			if (f) {
			m -= m % f;
			people[a] -= m;
			m /= f;
			for (j = 0; j < f; j++)
			{
				infile >> T;
				b = lookup(T);
				people[b] += m;
			} }
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < nameL[i]; j++)
				outfile << names[i][j];
			outfile << " ";
			outfile << people[i] << endl;
		}


	return 0;
}
