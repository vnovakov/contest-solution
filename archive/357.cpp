/* @JUDGE_ID: 3207EZ 357 C++ "Dynamic Programming" */
#include <iostream.h>

main()
{
	int value[5] = {1,5,10,25,50};
	int array[100]; int i, j, n;

	while(cin >> n)
	{

			array[0] = 1;
			for (i = 1; i <= n; i++)
				array[i] = 1;
			for (i = 1; i < 5; i++)
				for (j = 0; j <= n; j++)
				{	if (j >= value[i])
						array[j] += array[j - value[i]];
				}


			if (array[n] == 1)
				cout << "There is only 1 way to produce " << n << " cents change." << endl;
			else
				cout << "There are " << array[n] <<
				" ways to produce " << n << " cents change." << endl;

	}

	return 0;
}
