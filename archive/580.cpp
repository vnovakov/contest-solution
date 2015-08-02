/* @JUDGE_ID: 3207EZ 580 C++ "Recurrence relation" */
#include <iostream.h>

unsigned long array[35];
unsigned long pow[35];
unsigned long ans[35];

unsigned long dummy;
unsigned long f(int n)
{
	int i; unsigned long s = 0;
	if (n == -1)
		return 1;
	if (array[n] != -1)
		return array[n];
	else
	{
		for (i = 0; i <= n - 3; i++)
			s += f(i-1)*pow[n - i - 3];
		ans[n] = s;
		array[n] = pow[n] - s;
		return array[n];
	}
}


main()
{
	int i, n; unsigned long p = 1;

	for (i = 0; i < 35; i++)
	{	array[i] = -1; pow[i] = p; p *= 2; }
	array[0] = 1; ans[0] = 0;
	array[1] = 2; ans[1] = 0;
	array[2] = 4; ans[2] = 0;
	array[3] = 7; ans[3] = 1;
	array[4] = 13; ans[4] = 3;
	array[5] = 24; ans[5] = 8;
	array[6] = 44; ans[6] = 20;

	while (1)
	{
		cin >> n;
//		if (n > 29)
//      	for (;;)
		if (!n)
			break;
		dummy = f(n);
		cout << ans[n] << endl;
	}

	return 0;
}
