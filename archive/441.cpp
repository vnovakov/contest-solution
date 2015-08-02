/* @JUDGE_ID: 3207EZ 441 C++ */
#include <iostream.h>

int n;
int array[13];
int used[6];

main()
{
	int i, finish, ca = 1, k;

	while (1)
	{
		cin >> n;
		if (!n)
			break;
		if (ca++ != 1)
			cout << endl;
		for (i = 0; i < n; i++)
		{	cin >> array[i]; if (i < 6) used[i] = i ; }

		while (1)
		{
			for (i = 0; i < 6; i++)
				cout << array[used[i]] << " ";
			cout << endl;
			finish = 1;
			for (i = 0; i < 6; i++)
				if (used[i] != n - 6 + i)
				{	finish = 0; break; }
			if (finish)
				break;
			k = 5;
			used[k]++;
			while (used[k] == n + k - 5)
			{
//				used[k] = used[k - 1] + 2;
				used[k - 1]++;
				k--;
			}
			for (i = k + 1; i < 6; i++)
				used[i] = used[i - 1] + 1;
		}
	}

	return 0;
}

