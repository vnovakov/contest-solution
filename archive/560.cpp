/* @JUDGE_ID: 3207EZ 560 C++ "DFS" */
#include <iostream.h>
#include <string.h>

int digits[12];

void explore(int dig[12], int L)
{
	int i;
	int s = 0;
	int carry;
	int nL, nDig[12];


	for (i = 0; i < L; i++)
		s += dig[i];

	if (s % 3 == 0)
	{
		carry = 0;
		for (i = 0; i < L; i++)
		{
			nDig[i] = (dig[i] + 10*carry) / 3;
			carry = (dig[i] + 10*carry) % 3;
		}
		nL = L;
		while (nDig[L - nL] == 0 && nL)
			nL--;
		explore(nDig, nL);
	}

}

main()
{
	int nInp;
	char S[12];
	int D[12];
	int i;

	cin >> nInp;

	while (nInp--)
	{
		cin >> S;

		for (i = 0; i < strlen(S); i++)
			D[i] = S[i] - '0';

		explore(D, strlen(S));
	}

	return 0;
}
