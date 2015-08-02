#include <fstream.h>

ifstream infile("ratios.in");
ofstream outfile("ratios.out");

long gcf(long a, long b)
{
	if (!b)
		return a;
	return gcf(b, a % b);
}

main()
{
	long matrix[3][3];
	long prod[3];
	long D, Dx, Dy, Dz;
	long g;


	long i, j;
	for (i = 0; i < 3; i++)
		infile >> prod[i];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			infile >> matrix[j][i];
	D = matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2]*matrix[2][1]) -
		 matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2]*matrix[2][0]) +
		 matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1]*matrix[2][0]);
	if (!D)
	{
		outfile << "NONE" << endl;
		return 0;
	}
	Dx= prod[0] * (matrix[1][1] * matrix[2][2] - matrix[1][2]*matrix[2][1]) -
		 matrix[0][1] * (prod[1] * matrix[2][2] - matrix[1][2]*prod[2]) +
		 matrix[0][2] * (prod[1] * matrix[2][1] - matrix[1][1]*prod[2]);
	Dy= matrix[0][0] * (prod[1] * matrix[2][2] - matrix[1][2]*prod[2]) -
		 prod[0] * (matrix[1][0] * matrix[2][2] - matrix[1][2]*matrix[2][0]) +
		 matrix[0][2] * (matrix[1][0] * prod[2] - prod[1]*matrix[2][0]);
	Dz= matrix[0][0] * (matrix[1][1] * prod[2] - prod[1]*matrix[2][1]) -
		 matrix[0][1] * (matrix[1][0] * prod[2] - prod[1]*matrix[2][0]) +
		 prod[0] * (matrix[1][0] * matrix[2][1] - matrix[1][1]*matrix[2][0]);
	if (!(( D >= 0 && Dx >= 0 && Dy >= 0 && Dz >= 0) ||
		( D <= 0 && Dx <= 0 && Dy <= 0 && Dz <= 0)	))
	{
		outfile << "NONE" << endl;
		return 0;
	}
	if (D < 0)
	{	D = -D; Dx = -Dx; Dy = -Dy; Dz = -Dz; }
	g = gcf(D, gcf(Dz, gcf(Dx, Dy)));
	D /= g;
	Dx /= g;
	Dy /= g;
	Dz /= g;
	if (!Dx && !Dy && !Dz)
   	D = 0;

	if (Dx > 100 || Dy > 100 || Dz > 100)
	{
		outfile << "NONE" << endl;
		return 0;
	}
	else
	{
		outfile << Dx << ' ' << Dy << ' ' << Dz << ' ' << D << endl ;
	}

	return 0;
}
