/* @JUDGE_ID: 3207EZ 119 C++ */

#include <iostream.h>
#include <string.h>

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
	int i, j, m, f, a;
	char S[12];
	while (cin >> n)
	{
		for (i = 0; i < n; i++)
		{
			people[i] = 0;
			cin >> S;
			nameL[i] = strlen(S);
			for (j = 0; j < nameL[i]; j++)
				names[i][j] = S[j];
		}
		for (i = 0; i < n; i++)
		{
			cin >> S;
			a = lookup(S);
			cin >> m;
			cin >> f;
			if (f) {
			m -= m % f;
			people[a] -= m;
			m /= f;
			for (j = 0; j < f; j++)
			{
				cin >> S;
				a = lookup(S);
				people[a] += m;
			} }
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < nameL[i]; j++)
				cout << names[i][j];
			cout << " ";
			cout << people[i] << endl;
		}

		cout << endl << endl;
	}

	return 0;
}
