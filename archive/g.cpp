#include <iostream.h>
#include <stdlib.h>

int cost[1000];
int N;
int ttime[1000];

int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;

	if (ttime[A]*cost[B] > ttime[B]*cost[A])
		return 1;
	else if (ttime[A]*cost[B] > ttime[B]*cost[A])
		return -1;
	else if (A > B)
		return 1;
	else
		return -1;
}

main()
{
	int nCase;
	int i;
	int perm[1000];

	cin >> nCase;

	while (nCase--)
	{
		cin >> N;

		for (i = 0; i < N; i++)
		{
			perm[i] = i;
			cin >> ttime[i] >> cost[i];
		}

		qsort(perm, N, sizeof(perm[0]), cmp);
		cout << 1 + perm[0];
		for (i = 1; i < N; i++)
			cout << ' '<<  1 + perm[i];
		cout << endl;
		if (nCase)
		cout << endl;
	}
	return 0;
}



