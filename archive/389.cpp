#include <iostream.h>
#include <string.h>

main()
{
	char S[7], T[10]; int b, c, l, m;
	int digit[200]; int value[16];
	int i;
	long N;

	digit['0'] = 0;
	digit['1'] = 1;
	digit['2'] = 2;
	digit['3'] = 3;
	digit['4'] = 4;
	digit['5'] = 5;
	digit['6'] = 6;
	digit['7'] = 7;
	digit['8'] = 8;
	digit['9'] = 9;
	digit['A'] = 10;
	digit['B'] = 11;
	digit['C'] = 12;
	digit['D'] = 13;
	digit['E'] = 14;
	digit['F'] = 15;

	value[0] = '0';
	value[1] = '1';
	value[2] = '2';
	value[3] = '3';
	value[4] = '4';
	value[5] = '5';
	value[6] = '6';
	value[7] = '7';
	value[8] = '8';
	value[9] = '9';
	value[10] = 'A';
	value[11] = 'B';
	value[12] = 'C';
	value[13] = 'D';
	value[14] = 'E';
	value[15] = 'F';


	while (cin >> S >> b >> c)
	{
		m = 0; N = 0;
		l = strlen(S);

		for (i = 0; i < l; i++)
			N = b*N + digit[S[i]];
		while (N)
		{
			T[m] = value[N % c];
			N /= c;
			m++;
		}

		if (m > 7)
			cout << "  ERROR" << endl;
		else {
			for (i = m; i < 7; i++)
				cout << " ";
			for (i = 0; i < m; i++)
				cout << T[m - 1 - i];
			cout << endl;
		}
	}

	return 0;
}
