#include <fstream.h>
#include <time.h>

ifstream infile("ttwo.in");
ofstream outfile("ttwo.out");

int grid[10][10];

int move(int &X, int &Y, int &dX, int &dY)
{
	int temp;
	X += dX;
	Y += dY;

	if (X < 0 || X > 9 || Y < 0 || Y > 9 ||
		grid[X][Y] )
	{
		X -= dX;
		Y -= dY;
		temp = dX;
		dX = dY;
		dY = -temp;
	}
}

main()
{
	long time = 0;
	int FdX = -1;
	int FdY = 0;
	int CdX = -1;
	int CdY = 0;
	int FX, FY, CX, CY;
	int i, j;

	char str[20];

	j = 0;
	while (infile.getline(str, 20))
	{

		for (i = 0; i < 10; i++)
		{
			grid[j][i] = 0;
			if (str[i] == 'F')
			{	FX = j; FY = i; }
			if (str[i] == 'C')
			{	CX = j; CY = i; }
			if (str[i] == '*')
				grid[j][i] = 1;
		}

		j++;


	}

	while (1)
	{
		time++;
		move(FX, FY, FdX, FdY);
		move(CX, CY, CdX, CdY);
		if (FX == CX && FY == CY)
		{	break; }
		if (clock() > CLOCKS_PER_SEC)
		{
			outfile << 0 << endl;
			return 0;
		}
	}

	outfile << time << endl;

	return 0;
}
