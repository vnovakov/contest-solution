/* @JUDGE_ID: 3207EZ 156 C++ */
#include <iostream.h>
#include <string.h>
#include <stdlib.h>

char words[1000][20];
char huge sorted[1000][20];
char aux[20];
int length[1000];
int permAnagram[1000];
int permSort[1000];
int use[1000];
int N;

int Ccmp(void const *A, void const *B)
{
	char a = *(char *)A;
	char b = *(char *)B;

	if (a > b)
		return 1;
	else if (a == b)
		return 0;
	else
		return -1;
}

int Acmp(void const *A, void const *B)
{
	int a = *(int *)A;
	int b = *(int *)B;

	return strcmp(sorted[a], sorted[b]);

}

int Scmp(void const *A, void const *B)
{
	int a = *(int *)A;
	int b = *(int *)B;

	return strcmp(words[a], words[b]);

}

main()
{
	int i, j;
	char S[30];
	N = 0;

	while (1)
	{
		cin >> S;
		if (S[0] == '#')
			break;
		length[N] = strlen(S);
		for (i = 0; i < length[N]; i++)
			words[N][i] = S[i];

		N++;
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < length[i]; j++)
			aux[j] =
				(words[i][j] >= 'a') ? words[i][j] : words[i][j] + 'a' - 'A';

		qsort(aux, length[i], sizeof(char), Ccmp);
		for (j = 0; j < length[i]; j++)
			sorted[i][j] = aux[j];
		permAnagram[i] = i;
		permSort[i] = i;
	}

	qsort(permAnagram, N, sizeof(int), Acmp);

	for (i = 0; i < N; i++)
		use[i] = 1;
	for (i = 0; i < N - 1; i++)
		if (strcmp(sorted[permAnagram[i]], sorted[permAnagram[i + 1]]) == 0)
			use[permAnagram[i]] = use[permAnagram[i + 1]] = 0;

	qsort(permSort, N, sizeof(int), Scmp);

	for (i = 0; i < N; i++)
		if (use[permSort[i]])
		{
			for (j = 0; j < length[permSort[i]]; j++)
				cout << words[permSort[i]][j];
			cout << endl;
		}

	return 0;
}
