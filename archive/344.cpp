/* @JUDGE_ID: 3207EZ 344 C++ */
#include <iostream.h>

int roman[5] = {1,5,10,50,100};
char rc[5] = {'i','v','x','l','c'};

int used[101][5];

void convert(int n)
{
	int rom[5]; int i; int nn = n;
	for (i = 0; i < 5; i++)
		rom[i] = 0;
	for (i = 4; i >= 0; i--)
	{
		if (n && n < 50 && n >= 40)
		{
			rom[3]++;
			rom[2]++;
			n -= 40;
		} else if (n && n < 10 && n >= 9)
		{
			rom[0]++;
			rom[2]++;
			n -= 9;
		} else if (n && n < 5 && n >= 4)
		{
			rom[0]++;
			rom[1]++;
			n -= 4;
		} else if (n && n < 100 && n >= 90)
		{
			rom[2]++;
			rom[4]++;
			n -= 90;
		}
		 else if (n >= roman[i])
		{
			rom[i] += n / roman[i];
			n = n % roman[i];
		}
	}
	for (i = 0; i < 5; i++)
		used[nn][i] = used[nn - 1][i] + rom[i];
}

main()
{
	int n, i;

	for (i = 0; i < 5; i++)
		used[0][i] = 0;
	for (i = 1; i <= 100; i++)
		convert(i);

	while (1)
	{
		cin >> n;
		if (!n)
			break;
		cout << n << ": ";
		for (i = 0; i < 4; i++)
			cout << used[n][i] << " " << rc[i] << ", ";
		cout << used[n][4] << " " << rc[4] << endl;
	}

	return 0;
}

