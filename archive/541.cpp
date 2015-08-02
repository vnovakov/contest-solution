#include <iostream.h>

main()
{
	int n, a, b;
	int row, col;
	int rowsum[101];
	int colsum[101];
	int badrow, badcol, nbr = 0, nbc = 0;
	while(1)
	{
		cin >> n;
		if (!n)
			break;
		for (row = 1; row <= n; row++)
		{
			rowsum[row] = 0;
			colsum[row] = 0;
		}
		for (row = 1; row <= n; row++)
			for (col = 1; col <= n; col++)
			{
				cin >> a;
				b = rowsum[row];
				rowsum[row] = ((!a) && b) || ((!b) && a);
				b = colsum[row];
				colsum[col] = ((!a) && b) || ((!b) && a);
			}
		for (row = 1; row <= n; row++)
		{
			if (rowsum[row] == 1)
			{	badrow = row; nbr++; }
			if (colsum[row] == 1)
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
