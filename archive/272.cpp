#include <iostream.h>
#include <string.h>

main()
{
	char S[1000];
   char *O[2] = {"``", "''"};
	int i, n;
	int state = 1;

	while (cin.getline(S, 1000))
	{
		n = strlen(S);
		for (i = 0; i < n; i++)
			if (S[i] == '"')
				cout << O[state = !state];
			else
				cout << S[i];
		cout << endl;
	}

	return 0;
}
