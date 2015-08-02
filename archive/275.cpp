/* @JUDGE_ID: 3207EZ 275 C++ "O(b)" */
#include <iostream.h>

long t, a, b, i, digits, m, mod[10000], term;

main()
{



	while (1)
	{
		cin >> a >> b;
		if (!b)
			break;

		m = a % b;

		cout << "."; digits = 1;

		for (i = 0; i < b; i++)
			mod[i] = 0;
		mod[m] = 1;
		term = 0;

		while (m)
		{
			if (digits % 50 == 0)
				cout << endl;
			digits++;
			m *= 10;
			cout << m / b;
			m %= b;
			if (m && mod[m])
			{	term = digits - mod[m];
				break;
			}
			mod[m] = digits;
		}
		cout << endl;
		if (!term)
			cout << "This expansion terminates.";
		else
			cout << "The last " << term << " digits repeat forever.";
		cout << endl << endl;
	}

	return 0;
}

