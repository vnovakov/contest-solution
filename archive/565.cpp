#include <iostream.h>
#include <string.h>

int N;
int M;
char name[16];
int matrix[100][16];
int satisfy[100];
int used[16];
int save[16];

int getName(char c)
{
	int i;
	for (i = 0; i < N; i++)
		if (c == name[i])
			return i;
	N++;
	name[N - 1] = c;
	return N - 1;
}

int explore(int level)
{
	int i;
	int back[100];
	if (level == N)
	{
		for (i = 0; i < M; i++)
			if (!satisfy[i])
         	return 0;
		for (i = 0; i < N; i++)
			save[i] = used[i];
		return 1;
	}
	used[level] = 1;
	for (i = 0; i < M; i++)
	{
		back[i] = satisfy[i];
		if (matrix[i][level] == 1)
			satisfy[i] = 1;
	}
	if (explore(level + 1)) return 1;
	for (i = 0; i < M; i++)
		satisfy[i] = back[i];
	used[level] = 0;
	for (i = 0; i < M; i++)
	{
		back[i] = satisfy[i];
		if (matrix[i][level] == -1)
			satisfy[i] = 1;
	}
	if (explore(level + 1)) return 1;
	for (i = 0; i < M; i++)
		satisfy[i] = back[i];

	return 0;
}

main()
{
	char S[100];
   int i, j;

	while (cin.getline(S, 100))
	{
		for (i = 0; i < 100; i++)
			for (j = 0; j < 16; j++)
				matrix[i][j] = 0;

		M = 0; N = 0;
		while (1)
		{

			for (i = 0; i < strlen(S); i += 2)
				if (S[i] == ';')
					break;
				else if (S[i] == '+')
					matrix[M][getName(S[i + 1])] = 1;
				else
					matrix[M][getName(S[i + 1])] = -1;
			M++;
			cin.getline(S, 100);
			if (S[0] == '.')
				break;

		}
		for (i = 0; i < M; i++)
			satisfy[i] = 0;

		if (explore(0) == 0)
			cout << "No pizza can satisfy these requests." << endl;
		else
		{
			cout << "Toppings: ";
			for (i = 0; i < N; i++)
				if (save[i])
					cout << name[i];
			cout << endl;
		}
	}

	return 0;
}
