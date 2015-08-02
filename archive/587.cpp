/* @JUDGE_ID: 3207EZ 587 C++ */
#include <iostream.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

double ABS(double a)
{
	if (a > 0)
		return a;
	else
		return -a;
}

main()
{
	char S[300]; int i;
	double dx, dy;
	double x, y;
   double s = 0.7071067812;
   float fx, fy;
	int d;
	int map = 1;

	while (1)
	{
		cin.getline(S, 300);
		if (S[0] == 'E')
			break;
		d = 0;   dx = 0; dy = 0;
		x = 0;
		y = 0;
		for (i = 0; i < strlen(S); i++)
		{
			if (S[i] == ',' || S[i] == '.')
			{
				if (dx < 0.0001)
					y += dy;
				else if (dy < 0.0001)
					x += dx;
				else
				{	x += dx*s;
					y += dy*s;
				}

				d = 0;
				dx = 0;
				dy = 0;
			}
			else if (S[i] >= '0' && S[i] <= '9')
				d = 10*d + S[i] - '0';
			else if (S[i] == 'N' || S[i] == 'n')
				dy = d;
			else if (S[i] == 'S' || S[i] == 's')
				dy = -d;
			else if (S[i] == 'E' || S[i] == 'e')
				dx = d;
			else if (S[i] == 'W' || S[i] == 'w')
				dx = -d;
		}
		fx = x;
		fy = y;
		printf("Map #%d\nThe treasure is located at (%.3f,%.3f).\n",map++,fx,fy);
		printf("The distance to the treasure is %.3f.\n\n", sqrt(fx*fx + fy*fy));
	}

	return 0;
}
