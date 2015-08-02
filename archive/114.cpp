#include <iostream.h>

int bumper[50][50];
int Bvalue[1000], Bcost[1000];
int M, N;
int Bdir[4] = {3,0,1,2};
int dirX[4] = {1,0,-1,0};
int dirY[4] = {0,1,0,-1};

int p(int dir1, int m)
{
	dir1 %= 2;
	int dir2;
	if (m == 0 || m == M)
		dir2 = 1;
	else
		dir2 = 0;
	if (dir1 != dir2)
		return 1;
	return 0;
}

main()
{
	int m, n; int wallCost, b, nB, value, life, dir;
	cin >> M	>> N;

	for (m = 0; m < M; m++)
		for (n = 0; n < N; n++)
			bumper[m][n] = -1;
	cin >> wallCost >> nB;

	for (b = 0; b < nB; b++)
	{
		cin >> m >> n;
		bumper[m][n] = b;
		cin >> Bvalue[b] >> Bcost[b];
	}

	while (cin >> m >> n >> dir >> life)
	{
		value = 0;
		while (life)
		{
			m += dirX[dir];
			n += dirY[dir];

			if (m == 0 || n == 0 || m == M || n == N)
			{
				if ((m + n) % (2*M + 2*N) == 0 || p(dir, m)) {
					dir = Bdir[dir];
					life -= wallCost;
				}
			}
			else if (bumper[m][n] != -1)
			{
				dir = Bdir[dir];
				life -= Bcost[bumper[m][n]];
				value += Bvalue[bumper[m][n]];
			} else
			{	life--; if (!life) break; }
		}
		cout << value << endl;
	}

	return 0;
}


