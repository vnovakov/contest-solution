/* @JUDGE_ID: 3207EZ 315 C++ */
#include <iostream.h>
#include <string.h>

int matrix[100][100];
int close[100][100];
int visited[100];
int N;

main()
{
	char S[1000];
	int i, j, k, l, stage, a, b, count;
	while (1)
	{
		cin >> N;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				matrix[i][j] = 0;
		if (!N)
			break;
		cin.getline(S, 1000);
		while (1)
		{
			cin.getline(S, 1000);
			if (S[0] == '0')
         	break;
			a = 0;
			b = 0;
			stage = 0;
			for (i = 0; i < strlen(S); i++)
			{
				if (S[i] == ' ')
				{
					if (stage == 0)
						stage++;
					else
					{
						matrix[a-1][b-1] = matrix[b-1][a-1] = 1;
						b = 0;
					}
				} else if (!stage)
					a = 10*a + S[i] - '0';
				else
					b = 10*b + S[i] - '0';
			}
			matrix[a-1][b-1] = matrix[b-1][a-1] = 1;
		}

		count = 0;

		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
				for (k = 0; k < N; k++)
					if (j == i || k == i || !matrix[j][k])
						close[j][k] = 0;
					else
						close[j][k] = 1;
			l = (i + 1) % N;
			for (j = 0; j < N; j++)
				visited[j] = -1;
			visited[l] = 0;
			while (1)
			{
				for (j = 0; j < N; j++)
					if (visited[j] == 0)
					{	k = j; break; }
				if (j == N)
					break;
				visited[k] = 1;
				for (j = 0; j < N; j++)
					if (close[j][k] && visited[j] == -1)
						visited[j] = 0;
			}
			for (j = 0; j < N; j++)
				if (j != i && visited[j] != 1)
					{	count++; cout << i + 1 << endl; goto next;  }


			next:
			;
		}

		cout << count << endl;
	}

	return 0;
}
