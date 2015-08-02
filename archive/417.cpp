#include <iostream.h>
#include <string.h>

long array[27][27];

long C(int a, int b)
{
	int r;
	if (b == 0)
		return 1;
	if (a == 0)
		return 0;
	if (a == b)
		return 1;
	if (array[a][b] != 0)
		return array[a][b];
	r = C(a-1,b-1) + C(a-1,b);
	array[a][b] = r;
	return r;
}

main()
{
	char S[100]; char j;
	int l; int i; long c;

	for (i = 0; i <= 26; i++)
		for (c = 0; c <= 26; c++)
			array[i][c] = 0;

	while(cin.getline(S, 10))
	{
		c = 0;
		l = strlen(S);
		for (i = 0; i < l - 1; i++)
			if (S[i] >= S[i+1])
				goto next;

		for (i = 1; i < l; i++)
		  c += C(26,i);
		c += 1;
		for (j = 'a'; j < S[0]; j++)
			c += C(25 - (j - 'a'), l - 1);

		for (i = 1; i < l; i++)
		{
			if (i)
				for (j = S[i - 1] + 1; j < S[i]; j++)
					c += C(25 - (j - 'a'), l - 1 - i);
		}

		next:
		;

		cout << c << endl;
	}

	return 0;
}