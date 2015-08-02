/* @JUDGE_ID: 3207EZ 128 C++ */
#include <iostream.h>
#include <string.h>

char digits[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

main()
{
	int i, l;
	long P;
	long T, Q;
	char S[2048];

	while (cin.getline(S, 2048))
	{
		l = strlen(S);
		P = 65536;
		T = 0;

		for (i = l - 1; i >= 0; i--)
		{  T += P * S[i];
			T = T % 34943;
			P = (P * 256) % 34943;
		}

		Q = 34943 - T;

		cout << digits[Q / 4096] << digits[(Q / 256) % 16] << ' ' <<
				digits[(Q / 16) % 16] << digits[Q % 16] << endl;

	}

	return 0;
}
