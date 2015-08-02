#include <iostream.h>

int grid[30][30][30];
int L, R, C;

main()
{
	int startX, startY, startZ;
	int finishX, finishY, finishZ;
	while (1)
	{
		cin >> L >> R >> C;

		for (i = 0; i < L; i++)
			for (j = 0; j < R; j++)
			{
				cin >> S;
				for (k = 0; k < C; k++)
					if (S[k] == 'S')
					{
						grid[i][j][k] = 0;
						startX = i;
						startY = j;
						startZ = k;
					} else if (S[k] == 'E')
					{
						grid[i][j][k] = 0;
						finishX = i;
						finishY = j;
						finishZ = k;
					} else if (S[k] == '.')
						grid[i][j][k] = 0;
					else
						grid[i][j][k] = -1;
			}
		
