/* @JUDGE_ID: 3207EZ 311 C++ */
#include <iostream.h>

main()
{
   long need;
	long amount[7];
	long two, one;

	while (1)
	{
		cin >> amount[1]
			 >> amount[2]
			 >> amount[3]
			 >> amount[4]
			 >> amount[5]
			 >> amount[6];
		if (amount[1] + amount[2] + amount[3] +
			 amount[4] + amount[5] + amount[6] == 0)
			 break;

		need = 0;
		two = 0;
		one = 0;
		need += amount[6];
		need += amount[5];
		one += 11*amount[5];
		need += amount[4];
		two += 5*amount[4];
		if (amount[3] > 0)
		{
			need += amount[3] / 4;
			if (amount[3] % 4 > 0)
				need++;
		}
			if (amount[3] % 4 == 1)
		{	two += 5; one += 7; }
		else if (amount[3] % 4 == 2)
		{	two += 3; one += 6; }
		else if (amount[3] % 4 == 3)
		{	two += 1; one += 5; }
		if (amount[2] < two)
			one += 4 * (two - amount[2]);
		else if (amount[2] > two)
		{	amount[2] -= two;
			if (amount[2] > 0)
			{
				need += amount[2] / 9;
				if (amount[2] % 9 > 0)
					need++;
			}
			one += ((9 - (amount[2] % 9)) % 9 ) * 4;
		}

		if (amount[1] > one)
		{	amount[1] -= one;
			if (amount[1] > 0)
			{
				need += amount[1] / 36;
				if (amount[1] % 36 > 0)
					need++;
			}
		}

		cout << need << endl;
	}

	return 0;
}
