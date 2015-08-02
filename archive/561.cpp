#include <iostream.h>
#include <stdio.h>

main()
{
	char A[300], B[300], C[300];
   int count[3][26];
	int nCases;
	int S;
	int a, b, c, i;
	cin >> nCases;

	while (nCases)
	{
		nCases--;
		cin >> a >> b >> c;
		cin >> A >> B >> C;
      S = 0;

		for (i = 0; i < 26; i++)
			count[0][i] = count[1][i] = count[2][i] = 0;
		for (i = 0; i < a; i++)
			count[0][A[i] - 'A']++;
		for (i = 0; i < b; i++)
			count[1][B[i] - 'A']++;
		for (i = 0; i < c; i++)
			count[2][C[i] - 'A']++;
		for (i = 0; i < 26; i++)
			S += count[0][i] * count[1][i] * count[2][i];
		printf("%.4f\n", 34.0 * (float)S / (float)(a*b*c));
	}

	return 0;
}
