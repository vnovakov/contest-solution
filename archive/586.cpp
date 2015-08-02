/* @JUDGE_ID: 3207EZ 586 C++ */
#include <iostream.h>
#include <string.h>

main()
{
	char S[100], T[100];
	int n; int i, j, l;
	int coef[11];
	int consts[11];
	int cconst;
	int cexp;
	int level;

	int temp; int zero;
	int last[20]; int nl;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		nl = 0;
		for (j = 0; j < 11; j++)
		{ consts[j] = 0;	coef[j] = 0; }
		cexp = 0;
		cconst = 1;
		cin >> S;
		level = 1;
		last[0] = 0;
		l = 0;
		while (level)
		{
			cin >> S;
			if (S[0] == 'E')
			{
				if (last[nl] == 2)
				{	if (cconst)
						cconst /= consts[l];
					else
						cconst = zero;
					l--; }
				else if (last[nl] == 1)
					cexp--;
				level--;
				nl--;
			}

			if (S[0] == 'L')
			{
				cin >> T;
				level++;
				if (T[0] == 'n')
				{	cexp++; last[++nl] = 1; }
				else {
					l++;
					consts[l] = 0;
					for (j = 0; j < strlen(T); j++)
						consts[l] = 10*consts[l] + T[j] - '0';
					if (consts[l] == 0 )
							zero = cconst;
						cconst *= consts[l];
					last[++nl] = 2;

				}
			}
			if (S[0] == 'O')
			{
				cin >> T;
				temp = 0;
				for (j = 0; j < strlen(T); j++)
					temp = 10*temp + T[j] - '0';
				coef[cexp] += cconst*temp;
			}
		}

		cout << "Program #" << i + 1 << endl;
		cout << "Runtime = ";
		temp = 0;
		for (j = 10; j >= 0; j--)
		{
			if (coef[j])
			{

				if (temp)
					cout << "+";
				if (!j && coef[j] == 1)
					cout << "1";
				if (coef[j] != 1)
					cout << coef[j];
				if (coef[j] != 1 && j)
					cout << "*";
				if (j)
					cout << "n";
				if (j > 1)
					cout << "^" << j;
				temp = 1;
			}
		}

		if (!temp)
			cout << "0";
		cout << endl << endl;
	}

	return 0;
}





