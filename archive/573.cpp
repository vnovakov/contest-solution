/* @JUDGE_ID: 3207EZ 573 C++ */
#include <iostream.h>

main()
{
	int h, d; float f, u, pos;
	int day;

	while (1)
	{
		cin >> h >> u >> d >> f;
		if (h == 0)
			break;
		pos = 0; day = 1;
		f *= 0.01*u;
		while (1)
		{
			if (u > 0)
				pos += u;
			if (pos > h)
				break;
			pos -= d;
			if (pos < 0)
				break;
			u -= f;
			day++;
		}

		if (pos > h)
			cout << "success";
		else
			cout << "failure";
		cout << " on day " << day << endl;
	}

	return 0;
}
