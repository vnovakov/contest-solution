#include <iostream.h>
#include <string.h>

void swap (int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

int array[30];

void flip (int a)
{
	int i;
	for (i = 0; 2*i < a; i++)
		swap(array[i], array[a - i]);
}

main()
{
	int N;
	int a, i, j, k, max;
	char S[200];

	while (cin.getline(S, 200))
	{
		N = 0;
		a = 0;
	for (i = 0; i <= strlen(S); i++)
			if (S[i] == ' ' || i == strlen(S))
			{
				array[N] = a;
				a = 0;
				N++;
			}
			else
				a = 10*a + S[i] - '0';
		cout << S << endl;
		for (i = N - 1; i; i--)
		{
			max = array[i];
			for (j = i - 1; j >= 0; j--)
				if (array[j] > max)
				{	k = j; max = array[j]; }
			if (max != array[i])
			{
				if (k != 0)
				{	flip(k); cout << N - k << " "; }
            flip(i);
				cout << N - i << " ";

			}
		}
		cout << 0 << endl;
	}

	return 0;
}