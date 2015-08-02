#include <iostream.h>

void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int array[50];

main()
{
	int nInp, N, n, nSwap, i, j;

	cin >> nInp;

	for (; nInp; nInp--)
	{
		cin >> N;
		for (n = 0; n < N; n++)
			cin >> array[n];

		nSwap = 0;
		for (i = 0; i < N; i++)
			for (j = i + 1; j < N; j++)
				if (array[j] < array[i])
				{
					nSwap++;
					swap(array[j], array[i]);
				}
		cout << "Optimal train swapping takes " << nSwap << " swaps." << endl;
	}

	return 0;
}
