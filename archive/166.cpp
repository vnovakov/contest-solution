#include <iostream.h>
#include <iomanip.h>

main()
{
	int value[6] = {1,2,4,10,20,40};
	int amount[6];
	double tn, tn2; int i, j, k, n, s;
	int array[101];  

	while (1)
	{
		s = 0;
		for (i = 0; i < 6; i++)
		{ 	cin >> amount[i]; s += amount[i]; }

		if (!s)
			break;

		cin >> tn;

		tn2 = 20*tn;  n = int(tn2);

		array[0] = 1;
		for (k = 1; k <= n; k++)
				array[k] = 0;

		for (i = 0; i < 6; i++)
			for (k = n; k >= value[i]; k--)
				for (j = 1; j <= amount[i]; j++)
					if ((k - j*value[i]) >= 0)
						array[k] += array[k - j*value[i]];


		cout << setw(3) << array[n] << endl;
	}

	return 0;
}
