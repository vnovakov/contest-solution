#include <iostream.h>
#include <iomanip.h>

long gcf(long a, long b)
{
	if (!b)
		return a;
	return gcf(b, a % b);
}

main()
{
	long m, n;

	while (cin >> m >> n)
	{
		cout << setw(10) << m << setw(10) << n << "     ";
		if (gcf(m, n) == 1)
			cout << "Good";
		else
			cout << "Bad";
		cout << " Choice" << endl;
	}
}
