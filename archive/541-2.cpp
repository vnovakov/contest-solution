/* @JUDGE_ID: 3207EZ 541 C++ */
#include <iostream.h>

int matrix[101][101];

main()
{
	int n, a, b;
	int row, col;
	int badrow, badcol, nbr = 0, nbc = 0;
	while(1)
	{
		nbr = 0; nbc = 0;
		cin >> n;
		if (!n)
			break;
		for (row = 1; row <= n; row++)
			for (col = 1; col <= n; col++)
				cin >> matrix[row][col];

		for (row = 1; row <= n; row++)
		{
			a = 0;
			for (col = 1; col <= n; col++)
			{	b = matrix[row][col];
				if (a == b)
					a = 1;
				else
					a = 0;
			}
			if (a == 1)
			{	badrow = row; nbr++; }

		}

		for (col = 1; col <= n; col++)
		{
			a = 0;
			for (row = 1; row <= n; row++)
			{	b = matrix[row][col];
				if (a == b)
					a = 1;
				else
					a = 0;
			}
			if (a == 1)
			{	badcol = col; nbc++; }

		}
		if (nbr == 0 && nbc == 0)
			cout << "OK" << endl;
		else if (nbc == 1 && nbr == 1)
			cout << "Change bit (" << badrow << "," << badcol << ")" << endl;
		else
			cout << "Corrupt" << endl;
	}

	return 0;
}
