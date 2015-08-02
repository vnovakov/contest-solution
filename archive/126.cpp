/* @JUDGE_ID: 3207EZ 126 "trivial" */
#include <iostream.h>
#include <string.h>

enum id {COEF, X, Y};

struct Term {
	int coef;
	int xExp;
	int yExp;
};

main()
{
	char s[100], t[100];
	id what;
	int i, j, num, sign, m, n;
	Term poly1[100], poly2[100];

	while (1)
	{
		cin.getline(s, 100);
		if (s[0] == '#')
			break;
		cin.getline(t, 100);
		id = COEF;
		num = 0;
		sign = 1;
		m = n = 0;
		for (i = 0; i < strlen(s); i++)
		{
			if (s[i] == '+' || s[i] == '-' )
			{
				id = COEF;
				if (i)
					poly1[m++].y = num;
				num = 0;
				if (s[i] == '-')
					sign = -1;
				else sign = 1;
			} else if (s[i] == 'x')
			{
				id = X;
				poly1[m].coef = sign*num;
				num = 0;
			} else if (s[i] == 'y')
			{
				id = Y;
				poly1[m].x = num;
				num = 0;
			}
			else if (s[i] >= '0' && s[i] <= '9')
				num = 10*num + s[i] - '0';
