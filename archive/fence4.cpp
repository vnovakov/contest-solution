#include <fstream.h>
#include <math.h>
#include <stdlib.h>

ifstream infile("fence4.in");
ofstream outfile("fence4.out");

double const TOL = 0.0001;
double const PI = 3.14159;

int eq(double a, double b)
{
	if ((a - b)*(a - b) < TOL*TOL)
		return 1;
	return 0;
}


int side (double x, double y, double x1, double y1, double x2, double y2)
{
	double k = (x1 - x)*(y1 - y2) - (y1 - y)*(x1 - x2);
	if (k > TOL)
		return 1;
	else if (eq(k, 0))
		return 0;
	return -1;
}

int intersect(double L1x1, double L1y1, double L1x2, double L1y2,
				  double L2x1, double L2y1, double L2x2, double L2y2)
{
	if (side(L1x1,L1y1,L2x1,L2y1,L2x2,L2y2) == side(L1x2,L1y2,L2x1,L2y1,L2x2,L2y2))

		return 0;
  if		(side(L2x1,L2y1,L1x1,L1y1,L1x2,L1y2) == side(L2x2,L2y2,L1x1,L1y1,L1x2,L1y2))

		return 0;
	return 1;
}

double ang[200];
int cmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;

	if (ang[A] > ang[B])
		return 1;
	return -1;
}
double X, Y;
double x[201], y[201];

int perm[200];
int N;

main()
{
	int i, j, k, q;
	double angle;
	int hit[201];
	double closest = 1/TOL;
	int cl = -1;
	double d, xx, yy, dx, dy;

	infile >> N >> X >> Y;
	for (i = 0; i < N; i++)
		infile >> x[i] >> y[i];
	x[N] = x[0];
	y[N] = y[0];
	x[N+1] = x[1];
	y[N+1] = y[1];

	k = 0;

	for (i = 0; i < N; i++)
		for (j = i  + 2; j < N && j < N - 1 + i;  j++)
			if (intersect(x[i], y[i], x[i+1], y[i+1],
							  x[j], y[j], x[j+1], y[j+1]))
				k = 1;
	if (k)
	{
		outfile << "NOFENCE" << endl;
		return 0;
	}

	for (i = 0; i < N; i++)
	{
		hit[i] = 0;
		perm[i] = i;
		ang[i] = atan2(   y[i] - Y, x[i] - X);
		if (ang[i] < 0)
			ang[i] += 2*PI;
	}

   qsort(perm, N, sizeof(int), cmp);

	for (j = 0; j < N; j++)

		if (!eq(ang[perm[j]], ang[perm[(j+1)%N]]))
			{
		angle = (ang[perm[j]] + ang[perm[(j+1)%N]]) / 2;

		if (j == N - 1)
			angle -= PI;
		if (angle < 0)
			angle += 2*PI;

		cl = -1;
		closest = 1/TOL;

		for (i = 0; i < N; i++)
		{
			if (side ( x[i], y[i], X, Y, X + 1000*cos(angle), Y + 1000*sin (angle)
							) &&
				side (	x[i+1], y[i+1] , X, Y, X + 1000*cos(angle), Y + 1000*sin (angle)
						))
							if (
				 side ( x[i], y[i], X, Y, X + 1000*cos(angle), Y + 1000*sin (angle)
							) !=
				side (  	x[i+1], y[i+1],X, Y, X + 1000*cos(angle), Y + 1000*sin (angle)
				))
			{
				if (eq(x[i],x[i+1]))
				{
					xx = x[i];
					yy = Y + tan(angle) * (xx - X);
				}
				else if (eq(y[i], y[i+1]))
				{
					yy = y[i];
					xx = X + (yy - Y) / tan(angle);
				}
				else {
				xx = (Y - y[i] - X*tan(angle) + x[i]*(y[i+1]-y[i])/(x[i+1]-x[i]))
				/ ( (y[i+1]-y[i])/(x[i+1]-x[i]) - tan(angle) );
				yy = Y + tan(angle) * (xx - X); }
				if ((eq(yy,Y) && ((xx > X && (angle < PI/ 2 || angle > 3*PI/2)) ||
									 (xx < X && (angle > PI/2 && angle < 3*PI/2))  ))
				|| (angle < PI && yy > Y) || (angle > PI && yy < Y))
				{
				dx = xx - X;
				dy = yy - Y;
				d = sqrt   (dx*dx+dy*dy);
				if (d < closest)
				{	closest = d; cl = i; }
				}
			}
		}

		if (cl != -1)
			hit[cl] = 1;
	}

	q = 0;

	for (i = 0; i < N; i++)
		q += hit[i];
	outfile << q << endl;
	for (i = 0; i < N - 2; i++)
		if (hit[i])
		{
			outfile << x[i] << ' ' << y[i] << ' ' << x[i+1] << ' ' << y[i+1] << endl;
		}
	if (hit[N-1])
	outfile << x[0] << ' ' << y[0] << ' ' << x[N-1] << ' ' << y[N-1] << endl;
	if (hit[N-2])
	outfile << x[N-2] << ' ' << y[N-2] << ' ' << x[N-1] << ' ' << y[N-1] << endl;

	return 0;
}

