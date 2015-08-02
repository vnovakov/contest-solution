#include <iostream.h>


main()
{
	int d, m, Y, c, y, a;
	int numdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	while (1)
	{
		cin >> m  >> d >> Y;
		if (d + m + y == 0)
			break;
		if (m < 1 || m > 12)
		{	cout << m << "/" << d << "/" << Y << " is an invalid date." << endl;
			goto next; }
		numdays[1] = 28;
		if (Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0))
			numdays[1] = 29;
		if (d < 1 || d > numdays[m - 1])
		{	cout << m << "/" << d << "/" << Y << " is an invalid date." << endl;
			goto next; }
		switch (m)
		{
			case 1: cout << "January"; break;
			case 2: cout << "February"; break;
			case 3: cout << "March"; break;
			case 4: cout << "April"; break;
			case 5: cout << "May"; break;
			case 6: cout << "June"; break;
			case 7: cout << "July"; break;
			case 8: cout << "August"; break;
			case 9: cout << "September"; break;
			case 10: cout << "October"; break;
			case 11: cout << "November"; break;
			case 12: cout << "December"; break;
		}
		cout << " " << d << ", " << Y << " is a ";
		m -= 2;
		if (m <= 0)
			m += 12;
		if (m == 11 || m == 12)
			Y -= 1;
		c = Y / 100;
		y = Y % 100;
		a = int(((float)2.6*m - 0.2) + d + y + int(y/4) + int(c/4) - 2*c);
		a = a % 7;
		if (a < 0)
			a += 7;
		switch(a)
		{
			case 0: cout << "Sunday"; break;
			case 1: cout << "Monday"; break;
			case 2: cout << "Tuesday"; break;
			case 3: cout << "Wednesday"; break;
			case 4: cout << "Thursday"; break;
			case 5: cout << "Friday"; break;
			case 6: cout << "Saturday"; break;
		}
		cout << endl;

		next:
		;
	}

	return 0;
}




