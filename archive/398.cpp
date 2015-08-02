/* @JUDGE_ID: 3207EZ 398 C++ */
#include <iostream.h>

int matrix[26][26];
int n; int maxn;
char names[26];

int getNum(char c)
{
	int i;
	if (n > maxn)
		maxn = n;
	for (i = 0; i < maxn; i++)
		if (names[i] == c)
			return i;
	n++;
	if (n > maxn)
		maxn = n;
	names[n-1] = c;
	return n - 1;
}

main()
{
	int  nn; char c; int i, j, k;
	while (1)
	{
		cin >> nn;
		n = 0;
		maxn = 0;
		if (!nn)
			break;
		cout << "S = {";
		for (i = 0; i < nn; i++)
		{
			cin >> c;
			cout << c;
			if (i != nn - 1)
				cout << ",";
			else
				cout << "}" << endl;
			j = getNum(c);
		}
		for (i = 0; i < nn; i++)
			for (j = 0; j < nn; j++)
			{
				cin >> c;
				k = getNum(c);
				matrix[i][j] = k;
				if (n > nn)
					n--;
			}
		cout << " #|";
		for (i = 0; i < n; i++)
			cout << names[i];
		cout << endl << " -+";
		for (i = 0; i < n; i++)
			cout << "-";
		cout << endl;
		for (i = 0; i < n; i++)
		{
			cout << " " << names[i] << "|";
			for (j = 0; j < n; j++)
				cout << names[matrix[i][j]];
			cout << endl;
		}
		cout << endl;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (matrix[i][j] >= n)
				{
					cout << "NOT A SEMIGROUP: " << names[i] <<
						"#" << names[j] << " = " << names[matrix[i][j]] <<
						"  WHICH IS NOT AN ELEMENT OF THE SET" << endl;
					goto next;
				}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				for (k = 0; k < n; k++)
					if (matrix[matrix[i][j]][k] != matrix[i][matrix[j][k]])
					{
						cout << "NOT A SEMIGROUP: " << "(" << names[i] << "#" <<
						names[j] << ")#" << names[k] << " IS NOT EQUAL TO " <<
						names[i] << "#(" << names[j] << "#" << names[k] << ")" <<
						endl;
						goto next;
					}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (matrix[i][j] != matrix[j][i])
				{
					cout << "SEMIGROUP BUT NOT COMMUTATIVE  (" << names[i] <<
					"#" << names[j] << " IS NOT EQUAL TO " << names[j] << "#" <<
					names[i] << ")" << endl;
					goto next;
				}
		cout << "COMMUTATIVE SEMIGROUP" << endl;

		next:
		;
		cout << "------------------------------" << endl << endl;

	}

	return 0;
}


