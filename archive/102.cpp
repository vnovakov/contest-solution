/* @JUDGE_ID: 3207EZ 102 C++ */
#include <iostream.h>

int array[3][3];
char a[3] = {'B','C','G'};

main()
{
	int i, j, k, ii, jj, kk, max, S;


	while (cin >> array[0][0])
	{
		S = array[0][0];
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				if (i + j != 0)
				{	cin >> array[i][j]; S += array[i][j]; }
		max = 0;
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				for (k = 0; k < 3; k++)
					if (i != j && j != k && i != k)
					{
						if (array[0][i] + array[1][j] + array[2][k] > max)
						{
							max = array[0][i] + array[1][j] + array[2][k];
							ii = i;
							jj = j;
							kk = k;
						}
					}
		cout << a[ii] << a[jj] << a[kk] << " " << S - max << endl;
	}

	return 0;
}

