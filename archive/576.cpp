/* @JUDGE_ID: 3207EZ 576 C++ "Easy" */
#include <iostream.h>
#include <string.h>

int num[3] = {5,7,5};

int isVowel (char c)
{
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
		return 1;
	return 0;
}

main()
{
	char S[100];
	int stage, count, i, l;

	while (1)
	{
		cin.getline(S, 100);
		stage = 0;
		if (S[0] == 'e' && S[1] == '/' && S[2] == 'o')
			break;
		else {
			l = strlen(S);
			count = 0;
			for (i = 0; i <= l; i++)
			{
				if (i == l || S[i] == '/')
				{
					if (count != num[stage])
					{
						cout << stage + 1;
						goto next;
					}
					count = 0;
					stage++;
				}
				else if (isVowel(S[i]) && ((!i) || (!isVowel(S[i-1]))))
					count++;
			}
			cout << "Y";

		}
		next:
		;
		cout << endl;
	}

	return 0;
}
