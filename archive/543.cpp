#include <iostream.h>

int isPrime(long n)
{
	for (long k = 3; k*k <= n; k += 2)
      if ((k == 3 || k % 3 != 0) && (k == 5 || k % 5 !=  
		if (n % k == 0)
			return 0;
	return 1;
}

main()
{
	long k, n;

	while (cin >> n)
	{
		if (!n)
			return 0;
		for (k = 3; 2*k <= n; k += 2)
			if ((k == 3 || k % 3 != 0) && isPrime(k) && isPrime(n - k))
			{	cout << n << " = " << k << " + " << n - k << endl;
				break;
			}

	}
}




