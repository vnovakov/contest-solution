/* @JUDGE_ID: 3207EZ 138 C++ */
#include <iostream.h>
#include <iomanip.h>

main()
{
	long x, y, nx, ny;
	int i;

	x = 1;
	y = 1;

	for (i = 0; i < 10; i++)
	{
		nx = 3*x + 2*y + 1;
		ny = 4*x + 3*y + 1;
		x = nx;
		y = ny;
		cout << setw(10) << x << setw(10) << y << endl;
	}

	return 0;
}
