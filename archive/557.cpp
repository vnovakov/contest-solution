/* @JUDGE_ID: 3207EZ 557 C++ */
#include <iostream.h>
#include <stdio.h>

float array[1001];
float aux[1001];
float saved[1001];

main()
{

	float f;

	int m, h, n, i, j, max = 4;
	saved[2] = 0;
	saved[4] = 0.25;

	cin >> m;

	for (h = 0; h < m; h++)
	{
		cin >> n;

		if (n <= max)
			f = 2*saved[n];
		else {

			array[0] = 0;
			array[1] = 0;
			array[2] = 1;

			for (i = 3; i <= n; i++)
				{
				aux[0] = 0;
				aux[i] = 1;
				for (j = 1; j < i; j++)
					aux[j] = (array[j-1] + array[j])/2;
				for (j = 0; j <= i; j++)  {
					if (i % 2 == 0 && 2*j == i)
					{   if (i > max)
							max = i;
						saved[i] = aux[j];
					}
					array[j] = aux[j];
				}
			}

			f = 2*array[n/2];
		}
		printf("%.4f", f);
		cout << endl;

	}
	return 0;
}

