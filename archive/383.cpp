/* @JUDGE_ID: 3207EZ 383 C++ "Floyd" */

#include <iostream.h>
#include <iomanip.h>
#include <string.h>

int matrix[30][30];
char names[30][3];
int n;

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int getName(char c[3])
{
	int i, j, ok;
	for (i = 0; i < n; i++)
		if (strlen(c) == strlen(names[i])) {
			ok = 1;
			for (j = 0; j < strlen(c); j++)
				if (names[i][j] != c[j])
					ok = 0;
			if (ok)
				return i;
		}
}

main()
{
	int inp, s, m, p, i, j, e, k; char c[3], d[3];

	cin >> inp;
	cout << "SHIPPING ROUTES OUTPUT" << endl << endl;

	for (s = 1; s <= inp; s++)
	{
		cout << "DATA SET" << setw(2) << s << endl << endl;

		cin >> n >> m >> p;

		for (i = 0; i < n; i++)
		{
			cin >> c;
			for (j = 0; j < strlen(c); j++)
				names[i][j] = c[j];
		}

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				matrix[i][j] = 10000;

		for (i = 0; i < m; i++)
		{
			cin >> c >> d;
			matrix[getName(c)][getName(d)] = 1;
			matrix[getName(d)][getName(c)] = 1;
		}

		for (k = 0; k < n; k++)
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++) {
					matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
					matrix[j][i] = matrix[i][j];
				}

		for (k = 0; k < p; k++)
		{
			cin >> e >> c >> d;
			i = getName(c);
			j = getName(d);
			if (matrix[i][j] >= 10000)
				cout << "NO SHIPMENT POSSIBLE" << endl;
			else
				cout << "$" << (long)100*e*matrix[i][j] << endl;
		}

		cout << endl;
	}

	cout << "END OF OUTPUT" << endl;
	return 0;
}


