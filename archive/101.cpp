/* @JUDGE_ID: 3207EZ 101 C++ */
#include <iostream.h>

int grid[25][25];
int posX[25], posY[25];
int N;

void putBack(int a)
{
	int i;

	grid[posX[a]][posY[a]] = -1;

	for (i = 0; i < N && grid[a][i] != -1; i++)
		;
	grid[a][i] = a;
	posX[a] = a;
	posY[a] = i;
}

void print()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		cout << " " << i << ":     ";
		for (j = 0; j < N; j++)
			if (grid[i][j] != -1)
				cout << " " << grid[i][j];
		cout << endl;
	}
}


main()
{
	int i, j, k, a, b;
	char S[6], T[6];
	cin >> N;

	for (i = 0; i < N; i++)
	{
		grid[i][0] = i;
		posX[i] = i;
		posY[i] = 0;
		for (j = 1; j < N; j++)
			grid[i][j] = -1;
	}

	while (cin >> S)
		if (S[0] == 'q')
			break;
		else {
			cin >> a >> T >> b;
			if (a == b || posX[a] == posX[b])
				goto next;
			if (S[0] == 'm' && T[1] == 'n')
			{
				for (i = posY[a] + 1; i < N && grid[posX[a]][i] != -1; i++)
					putBack(grid[posX[a]][i]);
				for (i = posY[b] + 1; i < N && grid[posX[b]][i] != -1; i++)
					putBack(grid[posX[b]][i]);
				grid[posX[a]][posY[a]] = -1;
				posX[a] = posX[b];
				posY[a] = posY[b] + 1;
				grid[posX[a]][posY[a]] = a;
			}
			else if (S[0] == 'm' && T[1] == 'v')
			{
				for (i = posY[a] + 1; i < N && grid[posX[a]][i] != -1; i++)
					putBack(grid[posX[a]][i]);
				grid[posX[a]][posY[a]] = -1;
				posX[a] = posX[b];
				for (i = posY[b] + 1; i < N && grid[posX[b]][i] != -1; i++)
					;
				posY[a] = i;
				grid[posX[a]][posY[a]] = a;
			} else if (S[0] == 'p' && T[1] == 'n')
			{
				for (i = posY[b] + 1; i < N && grid[posX[b]][i] != -1; i++)
					putBack(grid[posX[b]][i]);
				j = posX[a]; k = posY[b] + 1;
				for (i = posY[a]; i < N && grid[j][i] != -1; i++, k++)
				{
					grid[posX[b]][k] = grid[j][i];
					grid[j][i] = -1;
					posX[grid[posX[b]][k]] = posX[b];
					posY[grid[posX[b]][k]] = k;
				}
			} else {
				for (k = posY[b] + 1; k < N && grid[posX[b]][k] != -1; k++)
					;
				j = posX[a];
				for (i = posY[a]; i < N && grid[j][i] != -1; i++, k++)
				{
					grid[posX[b]][k] = grid[j][i];
					grid[j][i] = -1;
					posX[grid[posX[b]][k]] = posX[b];
					posY[grid[posX[b]][k]] = k;
				}
			}

		next:
		;
		}

	print();
	return 0;
}


