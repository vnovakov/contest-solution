#include <iostream.h>
#include <fstream.h>

ofstream outfile("f.out");

main()
{
	long k;
	long n;
	long s;
	int nCase;

	cin >> nCase;

	while (nCase--)
	{
		cin >> k;
		if (k < 0) k = -k;

		n = 1;
		s = 1;

		while (1)
		{
			if (s >= k && (s - k) % 2 == 0)
				break;
			n++;
			s += n;
		}
		cout << n << endl;
		if (nCase > 1)
			cout << endl;
	}

	return 0;
}


