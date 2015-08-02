#include <iostream.h>

int gridX[7][7];
int gridY[7][7];
int gridZ[7][7];
int filled[7][7];
int deg[7][7];
int conn[7][7][7][7];
int num[5];

int differBy1(int a, int b,int c, int p, int q, int r)
{
	if (a == p && c == r && b != q)
		return 1;
	if (a != p && c == r && b == q)
		return 1;
	if (a == p && c != r && b == q)
		return 1;
	return 0;
}

int search(int toFill)
{
	int i, j, k, l, good;
	int count[2][2][2];

		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
				for (k = 0; k < 2; k++)
					count[i][j][k] = 0;
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++)
			{
				if (filled[i][j])
				count[gridX[i][j]][gridY[i][j]][gridZ[i][j]] += deg[i][j] - 1;
			}
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
				for (k = 0; k < 2; k++)
					if (count[i][j][k] > 3)
						return 0;
	if (!toFill)
	{
		for (i = 0; i < 2; i++)
			for (j = 0; j < 2; j++)
				for (k = 0; k < 2; k++)
					if (count[i][j][k] != 3)
						return 0;
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++)
				for (k = 0; k < 7; k++)
					for (l = 0; l< 7; l++)
						if (conn[i][j][k][l] && !differBy1
						(gridX[i][j], gridY[i][j], gridZ[i][j],
						gridX[k][l], gridY[k][l], gridZ[k][l]))
							return 0;
		return 1;

	}

	else
	{
		for (i = 0; i < 7; i++)
			for (j = 0; j < 7; j++)
				if (deg[i][j] && !filled[i][j])
				{
					good = 0;
					if (i && conn[i][j][i-1][j] && filled[i-1][j])
					{
						gridX[i][j] = gridX[i-1][j];
						gridY[i][j] = gridY[i-1][j];
						gridZ[i][j] = gridZ[i-1][j];
						filled[i][j] = 1;

						gridX[i][j] = 1 - gridX[i][j];
						if (search(toFill - 1))
							return 1;
						gridX[i][j] = 1 - gridX[i][j];
						gridY[i][j] = 1 - gridY[i][j];
						if (search(toFill - 1))
							return 1;
						gridY[i][j] = 1 - gridY[i][j];
						gridZ[i][j] = 1 - gridZ[i][j];
						if (search(toFill - 1))
							return 1;
						gridZ[i][j] = 1 - gridZ[i][j];
						filled[i][j] = 0;
						good = 1;
					}
					if (good)
						break;

					if (i < 6 && conn[i][j][i+1][j] && filled[i+1][j])
					{
						gridX[i][j] = gridX[i+1][j];
						gridY[i][j] = gridY[i+1][j];
						gridZ[i][j] = gridZ[i+1][j];
						filled[i][j] = 1;

						gridX[i][j] = 1 - gridX[i][j];
						if (search(toFill - 1))
							return 1;
						gridX[i][j] = 1 - gridX[i][j];
						gridY[i][j] = 1 - gridY[i][j];
						if (search(toFill - 1))
							return 1;
						gridY[i][j] = 1 - gridY[i][j];
						gridZ[i][j] = 1 - gridZ[i][j];
						if (search(toFill - 1))
							return 1;
						gridZ[i][j] = 1 - gridZ[i][j];
						filled[i][j] = 0;
						good = 1;
					}
					if (good)
						break;
					if (j && conn[i][j][i][j-1] && filled[i][j-1])
					{
						gridX[i][j] = gridX[i][j-1];
						gridY[i][j] = gridY[i][j-1];
						gridZ[i][j] = gridZ[i][j-1];
						filled[i][j] = 1;

						gridX[i][j] = 1 - gridX[i][j];
						if (search(toFill - 1))
							return 1;
						gridX[i][j] = 1 - gridX[i][j];
						gridY[i][j] = 1 - gridY[i][j];
						if (search(toFill - 1))
							return 1;
						gridY[i][j] = 1 - gridY[i][j];
						gridZ[i][j] = 1 - gridZ[i][j];
						if (search(toFill - 1))
							return 1;
						gridZ[i][j] = 1 - gridZ[i][j];
						filled[i][j] = 0;
						good = 1;
					}
					if (good)
						break;
					if (j < 6 && conn[i][j][i][j+1] && filled[i][j+1])
					{
						gridX[i][j] = gridX[i][j+1];
						gridY[i][j] = gridY[i][j+1];
						gridZ[i][j] = gridZ[i][j+1];
						filled[i][j] = 1;

						gridX[i][j] = 1 - gridX[i][j];
						if (search(toFill - 1))
							return 1;
						gridX[i][j] = 1 - gridX[i][j];
						gridY[i][j] = 1 - gridY[i][j];
						if (search(toFill - 1))
							return 1;
						gridY[i][j] = 1 - gridY[i][j];
						gridZ[i][j] = 1 - gridZ[i][j];
						if (search(toFill - 1))
							return 1;
						gridZ[i][j] = 1 - gridZ[i][j];
						filled[i][j] = 0;
						good = 1;
					}

					if (good)
               	break;
				}

	}

	return 0;
}

main()
{
	int nCase;
	int i, j, k, l, a;
	int count;


	cin >> nCase;

	while(nCase--)
	{
		count = 0;
		for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
		{	deg[i][j] = 0;
      	filled[i][j] = 0;
		for (k = 0; k < 7; k++)
		for (l = 0; l < 7; l++)
			conn[i][j][k][l] = 0;
		}
		for (i = 0; i < 6; i++)
		{
			for (j = 0; j < 6; j++)
			{
				cin >> a;
				if (a)
				{
				count++;
				if (!conn[i][j][i][j+1])
				{
				conn[i][j][i][j+1] = 1; deg[i][j]++; deg[i][j+1]++;
				conn[i][j+1][i][j] = 1;
				}
				if (!conn[i][j][i+1][j])
				{
				conn[i][j][i+1][j] = 1; deg[i][j]++; deg[i+1][j]++;
				conn[i+1][j][i][j] = 1;
				}
				if (!conn[i][j+1][i+1][j+1])
				{
				conn[i][j+1][i+1][j+1] = 1; deg[i+1][j+1]++; deg[i][j+1]++;
				conn[i+1][j+1][i][j+1] = 1;
				}
				if (!conn[i+1][j][i+1][j+1])
				{
				conn[i+1][j][i+1][j+1] = 1; deg[i+1][j+1]++; deg[i+1][j]++;
            conn[i+1][j+1][i+1][j] = 1;
				}
				if (count == 1)
				{
					gridX[i][j] = 0;
					gridY[i][j] = 0;
					gridZ[i][j] = 0;
					gridX[i+1][j] = 1;
					gridY[i+1][j] = 0;
					gridZ[i+1][j] = 0;
					gridX[i][j+1] = 0;
					gridY[i][j+1] = 1;
					gridZ[i][j+1] = 0;
					gridX[i+1][j+1] = 1;
					gridY[i+1][j+1] = 1;
					gridZ[i+1][j+1] = 0;
					filled[i][j] = 1;
					filled[i+1][j] = 1;
					filled[i][j+1] = 1;
					filled[i+1][j+1] = 1;
				}
			}
		}
		}
		if (count != 6)
			cout << "incorrect" << endl;
		else {
			for (i = 0; i < 7; i++)
				for (j = 0; j < 7; j++)
					num[deg[i][j]]++;
			if ((num[2] - num[3])% 3 != 0)
				cout << "incorrect" << endl;
			else {
				if (search(10))
					cout << "correct" << endl;
				else
					cout << "incorrect" << endl;

			}

		}


		if (nCase)
			cout << endl;
	}

	return 0;
}
