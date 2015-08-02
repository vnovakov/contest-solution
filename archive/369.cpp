/* @JUDGE_ID: 3207EZ 369 C++ "Memoization" */
#include <iostream.h>

unsigned long array[101][101];

unsigned long C(int a, int b)
{
	unsigned long r;
	if (a < 2*b)
   	b = a - b;
	if (b == 0)
		return 1;
	if (a == 0)
		return 0;
	if (a == b)
		return 1;
	if (array[a][b] != 0)
		return array[a][b];
	r = C(a-1,b-1) + C(a-1,b);
	array[a][b] = r;
	return r;
}

main()
{
	int m, n;

	while(1)
	{
		cin >> m >> n;
		if (m + n == 0)
			break;
		cout << m << " things taken " << n << " at a time is " << C(m,n) <<
			" exactly." << endl;
	}

	return 0;
}