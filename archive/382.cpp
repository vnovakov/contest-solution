/* @JUDGE_ID: 3207EZ 382 C++ */
#include <iostream.h>
#include <iomanip.h>

main()
{
	long n, s; int i;

	cout << "PERFECTION OUTPUT" << endl;

	while (1)
	{
		cin >> n; if (!n) break;

		s = 1;
		i = 2;
		for (; (long)i*i < n; i++)
			if (n % i == 0)
				s += i + n / i;
		if (i*i == n)
      	s += i;


		if (n == 1)
			s--;

		cout << setw(5) << n;
		if (s < n)
			cout << "  DEFICIENT";
		else if (s == n)
			cout << "  PERFECT";
		else
			cout << "  ABUNDANT";
		cout << endl;
	}

	cout << "END OF OUTPUT" << endl;

	return 0;
}
