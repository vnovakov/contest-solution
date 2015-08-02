#include <iostream.h>
#include <math.h>

#include <fstream.h>

ofstream outfile("c.out");

main()
{
	long Ncase;
	long a, b, c;
	long aR, bR, aC, bC;
	long count;
	long diff;



	cin >> Ncase;

	while (Ncase--)
	{
		cin >> a >> b;
		if (b < a)
		{
			c = b;
			b = a;
			a = c;
		}
      cout << sqrt(a);
		aR = ceil(sqrt(a));
		bR = ceil(sqrt(b));
		count = 0;

		if (aR == bR)
		{
			cout << (b - a) << endl << endl;
		} else {
			aC = a - (aR - 1)*(aR - 1);
			bC = b - (bR - 1)*(bR - 1);
			diff = aC - bC + bR - aR;

			if (aC % 2 == 0)
			{
				if (abs(diff + 1) > abs(diff - 1))
					aC--;
				else
					aC++;
				count++;
			}


			diff = abs(aC - bC + bR - aR);
			if (diff > bR - aR)
			{
				cout << count + bR - aR + diff << endl << endl;
			} else {
				if ((diff + bR - aR)  % 2 == 0)
					cout << count + 2*(bR - aR) << endl << endl;
				else
					cout << count - 1 + 2*(bR - aR) << endl << endl;
			}
		}
	}

	return 0;
}
