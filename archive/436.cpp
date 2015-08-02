/* @JUDGE_ID: 3207EZ 436 C++ "FW for the (R,max,*,inf,1) semiring" */
#include <iostream.h>
#include <string.h>

int n;
char names[30][40];
int nameL[30];
int empty[30];
float matrix[30][30];
char s[40], t[40];
float f;

void insert(char s[40])
{
	int i, k = 0;

	for (i = 0; i < strlen(s); i++)
		k += s[i] - 'A';

	k = k % n;

	while (!empty[k])
	{
		k++;
		k = k % n;
	}

	for (i = 0; i < strlen(s); i++)
		names[k][i] = s[i];
	nameL[k] = i;

	empty[k] = 0;

}

int index(char s[40])
{
	int i, k = 0, ok;

	for (i = 0; i < strlen(s); i++)
		k += s[i] - 'A';

	while (1)
	{
		k = k % n;
		if (nameL[k] == strlen(s))
		{
			ok = 1;
			for (i = 0; i < strlen(s); i++)
				if (names[k][i] != s[i])
				{	ok = 0; break; }
			if (ok)
				return k;
		}
		k++;
	}

}

main()
{
	int i, j, k, m, ca = 1;

	while (1)
	{
		cin >> n;
		if (!n)
			break;
		for (i = 0; i < n; i++)
			empty[i] = 1;
		for (i = 0; i < n; i++) {
			cin >> s;
			insert(s);
		}
		cin >> m;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				matrix[i][j] = 0;
		for (i = 0; i < m; i++)
		{
			cin >> s >> f >> t;
			matrix[index(s)][index(t)] = f;
		}
		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{  if (matrix[i][k]*matrix[k][j] > matrix[i][j])
						matrix[i][j] = matrix[i][k]*matrix[k][j];
					if (i == j && matrix[i][j] > 1)
						goto ok;
				}

		cout << "Case " << ca++ << ": No" << endl;

		goto next;

		ok:
		;
		cout << "Case " << ca++ << ": Yes" << endl;

		next:
		;
	}

	return 0;
}
