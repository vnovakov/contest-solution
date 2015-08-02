/* @JUDGE_ID: 3207EZ 271 C++ "Memoized" */
#include <iostream.h>
#include <string.h>

char S[300];
char mem[256][256];

int ok(int start, int finish)
{
	int i;
	int r = 0;
	if (start == finish)
		r = (S[start] >= 'p' && S[start] <= 'z');
	else if (S[start] == 'N')
		r = ok(start + 1, finish);
	else if (S[start] == 'C' || S[start] == 'D' || S[start] == 'E' || S[start] == 'I')
	{
		for (i = start + 1; i < finish; i++)
			if (ok(start + 1, i) && ok(i + 1, finish))
			{
				r = 1;
				break; }
	}

	return 0;
}



main()
{
	int r;
	while (cin.getline(S, 300))
	{
		r = ok(0, strlen(S) - 1);
		if (r)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}

   return 0;
}
