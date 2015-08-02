/* @JUDGE_ID: 554 C */
#include <iostream.h>
#include <string.h>

int nWords;
int length[100];
char words[100][30];

int match(char S[300], int start, int finish)
{
	int i, j, ok;

	for (i = 0; i < nWords; i++)
		if (length[i] == finish - start + 1)
		{
			ok = 1;
			for (j = 0; j < length[i]; j++)
				if (words[i][j] != S[start + j])
					{ ok = 0; break; }
			if (ok)
				return 1;
		}
	return 0;
}

int totalMatch(char S[300])
{
	int len = strlen(S);
	int i; int last = 0;
	int sum = 0;

	for (i = 0; i < len; i++)
		if (S[i] == ' ')
		{
			sum += match(S, last, i - 1);
			last = i + 1;
		}

	return sum;
}

main()
{

	int word, pos, line;
	int max = 0, pmax;
	int i, j, k = 0;
	char U[300];
	char V[300];

	nWords = 0;

	while (1)
	{
		cin.getline(U, 300);
		if (U[0] == '#')
			break;
		length[nWords] = strlen(U);
		for (pos = 0; pos < strlen(U); pos++)
			words[nWords][pos] = U[pos];
		nWords++;
	}
	cin.getline(U, 300);

	for (j = 0; j < strlen(U); j++)
   	V[j] = U[j];

	for (i = 0; i < 27; i++)
	{
		for (j = 0; j < strlen(U); j++)
		{
			U[j]++;
			if (U[j] > 'Z')
				U[j] = ' ';
			else if (U[j] == ' ' + 1)
				U[j] = 'A';
		}
		pmax = totalMatch(U);
		if (pmax > max)
		{
			max = pmax; k = i;
			for (j = 0; j < strlen(U); j++)
				V[j] = U[j];
		}
	}

	k = 0;
	for (j = i + 1; j < strlen(U) && V[j] != ' '; j++)
		k++;

	line = 0;
	for (i = 0; i < strlen(U); i++)
	{
		cout << V[i];
		if (V[i] == ' ')
		{
			k = 0;
			for (j = i + 1; j < strlen(U) && V[j] != ' '; j++)
				k++;
		}
		line++;
		if (V[i] == ' ' && line + k > 60)
		{	line = 0;
			cout << endl;
		}
	}
	cout << endl;

	return 0;
}
