/* @JUDGE_ID: 3207EZ 555 C++ */
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

int suites[4][13];
int cards[4][13];
int index;

int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;

	if (suites[index][A] > suites[index][B])
		return 1;
	else if (suites[index][A] == suites[index][B])
	{
		if (cards[index][A] > cards[index][B])
			return 1;
		else
			return -1;
	}
	else
		return -1;
}

main()
{
	char dealer;
	int pos;
	int perm[13];
	int amount[4];
	int s[200], c[200], name[4];
	char sN[4] = "CDSH";
	char cN[13] = "23456789TJQKA";
	char S[100];
	int i;

	name[0] = 'S';
	name[1] = 'W';
	name[2] = 'N';
	name[3] = 'E';

	s['C'] = 0;
	s['D'] = 1;
	s['S'] = 2;
	s['H'] = 3;

	c['2'] = 0;
	c['3'] = 1;
	c['4'] = 2;
	c['5'] = 3;
	c['6'] = 4;
	c['7'] = 5;
	c['8'] = 6;
	c['9'] = 7;
	c['T'] = 8;
	c['J'] = 9;
	c['Q'] = 10;
	c['K'] = 11;
	c['A'] = 12;

	while (cin >> dealer)
	{
		if (dealer == '#')
			break;
		if (dealer == 'S')
			pos = 1;
		else if (dealer == 'W')
			pos = 2;
		else if (dealer == 'N')
			pos = 3;
		else
			pos = 0;
		for (i = 0; i < 4; i++)
			amount[i] = 0;
		cin.getline(S, 100);
		cin.getline(S, 100);

		for (i = 0; i < strlen(S); i += 2)
		{
			amount[pos]++;
			suites[pos][amount[pos] - 1] = s[S[i]];
			cards[pos][amount[pos] - 1] = c[S[i + 1]];
			pos = (pos + 1) % 4;
		}
		cin.getline(S, 100);

		for (i = 0; i < strlen(S); i += 2)
		{
			amount[pos]++;
			suites[pos][amount[pos] - 1] = s[S[i]];
			cards[pos][amount[pos] - 1] = c[S[i + 1]];
			pos = (pos + 1) % 4;
		}

		for (index = 0; index < 4; index++)
		{
			cout << (char)name[index] << ":";

			for (i = 0; i < 13; i++)
				perm[i] = i;

			qsort(perm, 13, sizeof(int), cmp);

			for (i = 0; i < 13; i++)
				cout << ' ' << sN[suites[index][perm[i]]] <<
									cN[cards[index][perm[i]]];

			cout << endl;
		}

	}

	return 0;
}