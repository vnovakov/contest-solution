/* @JUDGE_ID: 3207EZ 542 C++ "Dynamic programming - O(N^2)" */
#include <iostream.h>
#include <stdio.h>
#include <string.h>

char country[16][12];
int length[16];
float stor[16][32];
float win[16][16];

float prob(int c, int pos)
{
	float sum; int i;

	if (stor[c][pos] != -1)
		return stor[c][pos];

	if (pos > 15)
		return (pos == c + 16) ? 1 : 0;

	sum = 0;

	for (i = 0; i < 16; i++)
		if (i != c)
			sum += prob(c, 2*pos)*prob(i, 2*pos + 1)*win[c][i] +
					 prob(c, 2*pos + 1)*prob(i, 2*pos)*win[c][i];

	stor[c][pos] = sum;

	return sum;
}

main()
{
	int i, j, percent;
	char S[12];

	for (i = 0; i < 16; i++)
		for (j = 1; j < 32; j++)
			stor[i][j] = -1;

	for (i = 0; i < 16; i++)
	{
		cin.getline(S, 12);
		length[i] = strlen(S);

		for (j = 0; j < length[i]; j++)
			country[i][j] = S[j];
	}

	for (i = 0; i < 16; i++)
		for (j = 0; j < 16; j++)
		{
			cin >> percent;
			win[i][j] = 1.0*percent / 100.0;
		}

	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < length[i]; j++)
			cout << country[i][j];
		for (; j <= 11; j++)
			cout << ' ';
		cout << "p=";
		printf("%.2f%\n", 100.0 * prob(i, 1));
	}

	return 0;
}
