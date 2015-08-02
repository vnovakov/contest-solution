/* @JUDGE_ID: 3207EZ 326 C++ */
#include <iostream.h>

main()
{
	int n;
	int i, j; long ii; long k;
	long array[10];
	long diff[10][10];
	long aux[10];

	while(1)
	{
		cin >> n;
		if (!n)
			break;
		for (i = 0; i < n; i++)
			cin >> array[i];
		cin >> k;

		for (i = 0; i < n; i++)
			diff[0][i] = array[i];
		for (i = 1; i < n; i++)
			for (j = 0; j < n - i; j++)
				diff[i][j] = diff[i-1][j+1] - diff[i-1][j];
		for (i = 0; i < n; i++)
			aux[i] = diff[i][n - 1 - i];
		for (ii = 0; ii < k; ii++)
		{
			for (j = n - 2; j >= 0; j--)
				aux[j] += aux[j + 1];
		}
		cout << "Term " << n + k << " of the sequence is " << aux[0] << endl;
	}

	return 0;
}