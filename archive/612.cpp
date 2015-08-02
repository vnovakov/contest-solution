/* @JUDGE_ID: 3207EZ 612 C++ */
#include <iostream.h>
#include <stdlib.h>

int m, n;
char S[50][100];
char T[100];
int perm[50];
int inverse[50];

int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;

	if (inverse[A] > inverse[B])
		return 1;
	else if (inverse[A] == inverse[B])
	{
		if (A > B)
			return 1;
		else if (A == B)
			return 0;
		return -1;
	}
	return -1;
}

main()
{
	int i, j, k;

	cin >> m >> n;
	cin.getline(T, 200);

	for (i = 0; i < n; i++)
	{
		inverse[i] = 0;
		perm[i] = i;
		cin.getline(T, 200);
		for (j = 0; j < m; j++)
			S[i][j] = T[j];
	}

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			for (k = j + 1; k < m; k++)
				inverse[i] += (S[i][j] > S[i][k]);

	qsort(perm, n, sizeof(int), cmp);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			cout << S[perm[i]][j];
		cout << endl;
	}

	return 0;
}

