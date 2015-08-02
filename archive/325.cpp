/* @JUDGE_ID: 3207EZ 325 C++ */
#include <iostream.h>
#include <string.h>

char S[10000];
int n;


int exists(char c)
{
	int i;
	for (i = 0; i < n; i++)
		if (S[i] == c)
			return i;
	return -1;
}

int num(int start, int finish)
{
	int i;
	if (start > finish)
		return 0;

	for (i = start; i <= finish; i++)
		if (S[i] < '0' || S[i] > '9')
			return 0;

	return 1;
}

int sgnNum(int start, int finish)
{
	if (S[start] == '+' || S[start] == '-')
		return num(start + 1, finish);
	else
		return num(start, finish);
}

main()
{

	int exp, dot, s, f, i;

	while (1)
	{
		cin.getline(S, 10000);

		if (S[0] == '*' && strlen(S) == 1)
			break;

		n = strlen(S);

		for (i = 0; i < n; i++)
			if (S[i] != ' ')
			{	s = i; break; }

		for (i = n - 1; i >= 0; i--)
			if (S[i] != ' ')
			{	f = i; break; }

		for (i = s; i <= f; i++)
			cout << S[i];

		dot = exists('.');
		exp = exists('E');
		if (exp == -1)
			exp = exists('e');

		if (dot == -1)
		{
			if (sgnNum(s, exp - 1) && sgnNum(exp + 1, f))
					cout <<  " is legal." << endl;
			else
					cout <<  " is illegal." << endl;

		}

		else if (exp != -1)
		{
			if (sgnNum(s, dot - 1) && num(dot + 1, exp - 1) && sgnNum(exp + 1, f))
					cout <<  " is legal." << endl;
			else
					cout <<  " is illegal." << endl;
		} else {
			if (sgnNum(s, dot - 1) && num(dot + 1, f))
					cout <<  " is legal." << endl;
			else
					cout <<  " is illegal." << endl;
		}

		next:
		;
	}

	return 0;
}