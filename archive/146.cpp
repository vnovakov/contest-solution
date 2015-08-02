/* @JUDGE_ID: 3207EZ 146 C++ "Swap then sort" */
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

int length;
char S[100];

int cmp(void const *a, void const *b)
{
	char A = *(char *)a;
	char B = *(char *)b;
	if (A < B)
		return 1;
	else if (A == B)
		return 0;
	return -1;
}

void least(int m)
{
	int i;
	int a = 0, b = 0, c = 0;
	char last[100];

	for (i = m; i < length; i++)
		last[i - m] = S[i];
	qsort(last, length - 1 - m, sizeof(char), cmp);
	for (i = m; i < length; i++)
   	S[i] = last[i - m];
}

void swap(char &a, char &b)
{
	char c = a;
	a = b;
	b = c;
}

main()
{
	int i, j, k, max, ok;
	char mmax;
	while (1)
	{
		cin.getline(S, 100);

		if (S[0] == '#')
			break;

		length = strlen(S);
		mmax = 'a';

		for (i = 0; i < length; i++)
			if (S[i] > mmax)
				mmax = S[i];

		for (i = length - 2; i >= 0; i--)
			if (S[i] != max)
			{
				ok = 0;
				max = mmax + 1;
				for (j = i + 1; j < length; j++)
					if (S[j] > S[i])
					{
						ok = 1;
						if (S[j] < max)
						{	max = S[j]; k = j; }
					}
				if (ok)
				{	swap(S[i], S[k]);
					break;
				}
			}
		if (i == -1)
			cout << "No Successor" << endl;
		else
		{
			least(i + 1);
			for (j = 0; j < length; j++)
				cout << S[j];
			cout << endl;
		}
	}

	return 0;
}

