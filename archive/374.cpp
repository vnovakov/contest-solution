#include <iostream.h>

main()
{
	unsigned long a, b;
	int bin[100], i;
	unsigned int n, d;

	while (cin >> a >> b >> n)
	{
		 a = a % n;
		 i = 0;

		 while (b)
		 {
			bin[i++] = b % 2;
			b /= 2;
		 }
		 d = 1;
		 for (i--; i >= 0; i--)
		 {
			d = ((unsigned long)d * d ) % n;
			if (bin[i] == 1)
				d = ((unsigned long)d * a) % n;
		 }

		 cout << d << endl;
	}

	return 0;
}

