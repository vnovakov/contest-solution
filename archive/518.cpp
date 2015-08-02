#include <iostream.h>

long labs(long a)
{
	if (a > 0)
		return a;
	return -a;
}

main()
{
	long y1, m1, d1, h1, min1, s1;
	long y2, m2, d2, h2, min2, s2;
	long time1, time2;
	int length[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
	char s[20]; long n;

	while (cin >> y1 >> m1 >> d1 >> h1 >> min1 >> s1)
	{
		cin >> y2 >> m2 >> d2 >> h2 >> min2 >> s2;

		time1 = s1 + 60*min1 + 3600*h1 + 86400*(d1 - 1);
		time1 += length[m1] * 86400;
		if (y1 % 4 == 0 && y1 % 100 != 0 && m1 > 2)
			time1 += 86400;
		time1 += 365*(y1 - 1970)*86400;
		time1 += ((y1 - 1969)/4) * 86400;

		time2 = s2 + 60*min2 + 3600*h2 + 86400*(d2 - 1);
		time2 += length[m2] * 86400;
		if (y2 % 4 == 0  && m2 > 2)
			time2 += 86400;
		time2 += 365*(y2 - 1970)*86400;
		time2 += ((y2 - 1969)/4) * 86400;

		cin >> n >> s;

		if (s[0] == 'm' && s[1] == 'i')
			n *= 60;
		else if (s[0] == 'h')
			n *= 3600;
		else if (s[0] == 'd')
			n *= 86400;
		else {

		}
		cout << labs(time1 - time2) / n << endl;
	}
}
