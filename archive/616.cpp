/* @JUDGE_ID: 3207EZ 616 C++ */
#include <iostream.h>

main()
{
	long n, nn, Q, P, m, k;

	while (cin >> P)
	{
		if (P < 0)
			break;

		cout << P << " coconuts, ";

		nn = 0;
		for (n = 2; n <= P; n++)
		{
			m = 1;
			Q = P;
			for (k = 0; k < n; k++)
			{
				if ((Q - 1) % n != 0)
				{	m = 0; break; }
				Q = (Q - 1) / n * (n - 1);
				if (Q < 0)
            {  m = 0;	break; }

			}
			if (m)
				if (Q % n == 0)
					nn = n;
		}

		if (!nn)
			cout << "no solution";
		else
			cout << nn << " persons and 1 monkey";
		cout << endl;
	}

	return 0;
}
