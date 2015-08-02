#include <iostream.h>
#include <string.h>

int huge array[201][201];
char S[400];

int T(int m, int n)
{
	int R;
	if (!m || n > m)
		return 0;
	if (!n)
		return 1;
	if (array[m][n] != -1)
		return array[m][n];
	R = T(m - 1, n) + T(m, n - 1);

	array[m][n] = R;
	return R;
}

void init(int m, int n)
{
	int i, j;

	for (i = 0; i <= m; i++)
		for (j = 0; j <= n; j++)
			array[i][j] = -1;

	array[0][0] = 0;
}

int G(int a, int b, int start, int finish)
{
	if (start > finish || a == b)
		return a;
	if (S[start] == '0')
		return G(a, (a + b) / 2, start + 1, finish);
	else
		return G((a + b) / 2 + 1, b, start + 1, finish);
}

void print(int m, int n, int pos)
{

	if (T(m, n) == 0 || !m)
		return;


main()
{
	int m, n;
	int pos;

	cin >> m >> n;

	init(m, n);
	cin >> S;

	pos = G(1, T(m, n), 2, strlen(S) - 1);

	print(m, n, pos);

	return 0;
}
