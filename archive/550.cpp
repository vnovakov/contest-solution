/* @JUDGE_ID: 3207EZ 550 C++ */
#include <iostream.h>

long gcf(long a, long b)
{
	if (!b)
		return a;
	return gcf(b, a % b);
}

main()
{
	long base, factor, digit, den;
	long exp, power;
	while (cin >> base >> digit >> factor)
	{
		den = (base*factor - 1) / gcf((base*factor - 1), digit);
		power = base % den;
		exp = 1;

		while (power % den != 1)
		{
			exp++;
			power = (power * base) % den;
		}

		cout << exp << endl;
	}

	return 0;
}


