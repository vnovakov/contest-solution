/* @JUDGE_ID: 3207EZ 195 C++ */
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

char s[100];
int used[100];
int freq[150];
char history[100];
int length;

int cmp(void const *a, void const *b)
{
	char A = *(char *)a;
	char B = *(char *)b;
	if (A > B)
		return 1;
	else if (A == B)
		return 0;
	return -1;
}

void explore(int level)
{
	int i;
	if (!level)
	{
		for (i = 0; i < length; i++)
			cout << history[i];
		cout << endl;
		return;
	}
	for (i = 0; i < length; i++)
		if (!used[i])
		{
			used[i] = 1;
			history[length - level] = s[i];
			freq[s[i]]--;
			explore(level - 1);
			freq[s[i]]++;
			used[i] = 0;
			i += freq[s[i]] - 1;

		}
}


main()
{
	int i, j, n;

	cin >> n;
	cin.getline(s, 100);

	for (i = 0; i < n; i++)
	{
		cin.getline(s, 100);
		for (j = 50; j < 150; j++)
			freq[j] = 0;
		length = strlen(s);
		for (j = 0; j < length; j++)
		{	freq[s[j]]++;
			used[j] = 0;
		}
		qsort(s, length, sizeof(char), cmp);
		explore(length);
	}

	return 0;
}