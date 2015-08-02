//### PROGRAM
/*
ID: vnovako001
PROG: poly1
*/
#include <fstream.h>
#include <string.h>

ifstream infile("poly1.in");
ofstream outfile("poly1.out");

int poly1[101][101];
int poly2[101][101];
int huge prod[201][201];

enum WHAT {NONE, COEF, POWX, POWY};

void process(char string[100], int l, int poly[101][101])
{
	int expX, expY, coef, sign, num; WHAT what;
	int i;
	what = COEF;
		num = 0;
      sign = 1;
			expX = 0;
			expY = 0;
			coef = 0;

	for (i = 0; i < l; i++)
	{
		if (string[i] == 'x')
		{

			if (what == COEF)
				coef = num * sign;
			if (!i || string[i - 1] == '+')
				coef = 1;
			  else  if ( string[i - 1] == '-')
				coef = -1;
			if (what == POWY)
			{
				if (num)	expY = num;
			}


			what = POWX;
			expX = 1;
			num = 0;
		} else if (string[i] == 'y')
		{
			if (what == COEF)
				coef = num * sign;
			if (!i || string[i - 1] == '+')
				coef = 1;
			  else  if ( string[i - 1] == '-')
				coef = -1;
			if (what == POWX)
			{
				if (num)
					expX = num;
			}


			what = POWY;
			expY = 1;
			num = 0;
		} else if (string[i] == '+')
		{
			if (what == COEF)
			{
				coef = num * sign;
			}
			if (what == POWX)
			{
				if (num) expX = num;
			}
			if (what == POWY)
			{ if (num)	expY = num;
			}

			poly[expX][expY] += coef;

			what = COEF;
			expX = 0;
			expY = 0;
			sign = 1;
			num = 0;
		} else if (string[i] == '-')
		{
			if (what == COEF)
			{
				coef = num * sign;
			}
			if (what == POWX)
			{
				if (num) expX = num;
			}
			if (what == POWY)
			{	if (num) expY = num;
			}

			poly[expX][expY] += coef;

			what = COEF;
			expX = 0;
			expY = 0;
			sign = -1;
			num = 0;
		} else {
			num = 10*num + string[i] - '0';
		}
	}

			if (what == POWX)
			{
				if (num) expX = num;
			}
			if (what == POWY)
			{	if (num) expY = num;
			}
			if (what == COEF)
			{	coef = sign * num;
         }
			poly[expX][expY] += coef;


}

char strTop[400];
char strBot[400];
int where = 0;

void printnum(int a)
{
	if (!a)
		return;
	printnum(a / 10);
	strBot[where++] = a % 10 + '0';
}

void printTopNum(int a)
{
	if (!a)
		return;
	printTopNum(a / 10);
	strTop[where++] = a % 10 + '0';
}

void printcoef(int x, int y, int value)
{
	if (where == 0)
	{
		if (value < 0)
		{
			strBot[where++] = '-';
		}
	}
	else {
		strBot[where++] = ' ';
		strBot[where++] = (value > 0) ? '+' : '-';
		strBot[where++] = ' ';
	}
	if (value != 1 && value != -1)
	{
		if (value < 0)
			value = -value;
		printnum(value);
	}
	if (!x && !y && value == 1)
	{
		printnum(value);
	}
	if (!x && !y && value == -1)
	{
		printnum(-value);
	}
	if (x)
	{
		strBot[where++] = 'x';
		if (x != 1)
			printTopNum(x);
	}
	if (y)
	{
		strBot[where++] = 'y';
		if (y != 1)
			printTopNum(y);
	}
}


main()
{
	char str1[100];
	char str2[100];

	int i, j, k, l, max;

	for (i = 0; i < 101; i++)
		for (j = 0; j < 101; j++)
poly1[i][j] = poly2[i][j] = 0;
	for (i = 0; i < 201; i++)
		for (j = 0; j < 201; j++)
			prod[i][j] = 0;

	infile.getline(str1, 100);
	infile.getline(str2, 100);

		process(str1, strlen(str1), poly1);
		process(str2, strlen(str2), poly2);


	for (i = 0; i < 200; i++)
	  strBot[i] =	strTop[i] = ' ';

	for (i = 0; i < 101; i++)
		for (k = 0; k < 101; k++)
			if (poly1[i][k])
			for (j = 0; j < 101; j++)
				for (l = 0; l < 101; l++)
					prod[i+j][k+l] += poly1[i][k] * poly2[j][l];

		for (i = 200; i >= 0; i--)
			for (j = 0; j < 201; j++)
				if (prod[i][j])
				{
					printcoef(i, j, prod[i][j]);
				}

	max = 0;

	for (i = where - 1; i >= 0; i--)
		if (strTop[i] != ' ')
		{	max = i + 1; break; }

	if (max)
	{
	for (i = 0; i < max; i++)
		outfile << strTop[i];
	outfile << endl;
	}

	max = 0;

	for (i = where - 1; i >= 0; i--)
		if (strBot[i] != ' ')
		{	max = i + 1; break; }
	for (i = 0; i < max; i++)
		outfile << strBot[i];
	outfile << endl;

	return 0;
}

//### END