/* @JUDGE_ID: 3207EZ 499 C++ */
#include <iostream.h>
#include <string.h>

main()
{
	int upper[26];
	int lower[26]; int i, n, max;
	char S[1000]; char c;

	while (cin.getline(S, 1000))
	{
		for (i = 0; i < 26; i++)
			upper[i] = lower[i] = 0;
		n = strlen(S);
		max = 0;
		for (i = 0; i < n; i++)
		{
			c = S[i];
			if (c >= 'A' && c <= 'Z')
			{	upper[c - 'A']++; if (upper[c - 'A'] > max)
											max = upper[c - 'A']; }
			else if (c >= 'a' && c <= 'z')
			{
				lower[c - 'a']++;
				if (lower[c - 'a'] > max)
					max = lower[c - 'a'];
			}
		}

		for (i = 0; i < 26; i++)
			if (upper[i] == max)
				cout << (char)('A' + i);
		for (i = 0; i < 26; i++)
			if (lower[i] == max)
				cout << (char)('a' + i);
		cout << " " << max << endl;
	}

	return 0;
}
