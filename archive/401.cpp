/* @JUDGE_ID: 3207EZ 401 C++ */
#include <iostream.h>
#include <string.h>

int mirror[35] = {0,-1,-1,-1,28,-1,-1,7,
						8,11,-1,9,12,-1,14,-1,-1,
						-1,-1,19,20,21,22,23,24,
						30,26,-1,4,-1,25,-1,-1,33,-1};

int index(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	else
		return 26 + c - '1';
}

main()
{
	char S[25];
	int length, l;
	int i, pal, mir;

	while (cin.getline(S, 25))
	{
		length = strlen(S); l = length;
		pal = mir = 1;

		for (i = length - 1; i >= 0; i--)
			if (S[i] == ' ')
				l--;

		length = l;

		for (i = 0; i < length; i++)
			if (S[i] != S[length - 1 - i])
				{	pal = 0; break; }

		for (i = 0; i < length; i++)
			if (mirror[index(S[i])] != index(S[length - 1 - i]))
				{	mir = 0; break; }

		for (i = 0; i < length; i++)
			cout << S[i];

		cout << " -- is ";

		if (!pal && !mir)
			cout << "not a palindrome.";
		else if (pal && !mir)
			cout << "a palindrome.";
		else if (!pal && mir)
			cout << "a mirrored string.";
		else
			cout << "a mirrored palindrome.";
		cout << endl << endl;
	}

	return 0;
}
