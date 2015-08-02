/* @JUDGE_ID: 3207EZ 494 C++ */

#include <iostream.h>
#include <string.h>

int isAlpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

main()
{
	char S[1000];
	int count;
	int l;
	int i;

	while (cin.getline(S, 900))
	{
		l = strlen(S);
		count = 0;

		for (i = 0; i < l; i++)
			if (!i || (isAlpha(S[i]) && !isAlpha(S[i - 1])))
				count++;

		cout << count << endl;
	}

	return 0;
}
