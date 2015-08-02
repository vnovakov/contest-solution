/* @JUDGE_ID: 3207EZ 347 C++ */
#include <iostream.h>
#include <string.h>

int visited[7];
int digits[7];
int pos;
int nDigits;

int check()
{
	int i, j; int count; int use[10]; int s = 0;
	for (i = 0; i < nDigits; i++)
	{ s += digits[i];		visited[i] = 0; }
	if (s % nDigits != 0)
   	return 0;

	visited[0] = 1;
	pos = 0;
	count = 0;

	for (i = 0; i < 10; i++)
		use[i] = 0;

	for (i = 0; i < nDigits; i++)
		use[digits[i]]++;

	for (i = 0; i < 10; i++)
		if (use[i] > 1)
			return 0;

	while(1)
	{
		count++;
		pos += digits[pos];
		pos = pos % nDigits;
		if (pos == 0 && count == nDigits)
			return 1;
		else if (visited[pos] == 1)
			return 0;
		visited[pos] = 1;
	}
}

main()
{

	char S[100]; int i, cc = 0;

	while(1)
	{
		cc++;
		cin.getline(S, 100);
		if (S[0] == '0')
			break;
		nDigits = strlen(S);
		for (i = 0; i < nDigits; i++)
			digits[i] = S[i] - '0';
		while (!check())
		{
			i = nDigits - 1;
			digits[i] = ( digits[i] + 1 ) % 10;

			while (i && digits[i] == 0)
			{	i--; 	digits[i] = ( digits[i] + 1 ) % 10; }
			if (digits[0] == 0)
			{
				for (i = nDigits; i >= 1; i--)
					digits[i] = digits[i - 1];
				digits[0] = 1;
				nDigits++;
			}
		}
		cout << "Case " << cc << ": ";
		for (i = 0; i < nDigits; i++)
			cout << digits[i];
		cout << endl;
	}

	return 0;
}
