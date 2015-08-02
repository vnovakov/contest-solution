/* @JUDGE_ID: 3207EZ 306 C++ */
#include <iostream.h>
#include <string.h>

int a[200];
int n;

long cycleLength()
{
	int b[200];
	int c[200];
	long R = 0;
	int same;
   int i;

for (i = 0; i < n; i++)
		b[i] = i;
	while (1)
	{
		if (R == 0)
			same = 0;
		else
			same = 1;
			for (i = 0; i < n; i++)
				if (b[i] != i )
					same = 0;
		if (same)
			return R;
		R++;
		for (i = 0; i < n; i++)
			c[a[i] - 1] = b[i];
		for (i = 0; i < n; i++)
			b[i] = c[i];
	}
}


main()
{
	int i;
	int l;
	long k, j;
	long C;
	int stage;
	char P[200], Q[200];
	char S[1000];

	while (1)
	{
		cin >> n;

		if (!n)
			break;
		for (i = 0; i < n; i++)
			cin >> a[i];
		C =  cycleLength();
		cin.getline(S, 1000);
		while (1)
		{
			cin.getline(S, 1000);
			if (S[0] == '0')
				break;
			stage = 0;
			k = 0;
			l = 0;
			for (i = 0; i < strlen(S); i++)
				if (S[i] == ' ' && !stage)
					stage++;
				else if (S[i] >= '0' && S[i] <= '9' && !stage)
					k = 10*k + S[i] - '0';
					else if (stage)
					P[l++] = S[i];
			k = k % C;

			for (i = l; i < n; i++)
				P[i] = ' ';

			for (j = 0; j < k; j++)
			{
				for (i = 0; i < n; i++)
					Q[a[i] - 1] = P[i];
				for (i = 0; i < n; i++)
					P[i] = Q[i];
			}

			for (i = 0; i < n; i++)
				cout << P[i];

			cout << endl;
		}
	}

	return 0;
}
