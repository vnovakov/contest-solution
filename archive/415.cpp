/* @JUDGE_ID: 3207EZ 415 C++ "Math" */
#include <iostream.h>
#include <stdio.h>
#include <math.h>

const long double R = 432000;
const long double r = 3950;
const long double D = 92900000;
const long double PI = 3.1415926535;

main()
{

	long double d_theta, sinTheta, cosTheta,
					sinPhi, cosPhi, sinDel, cosDel, time,  y,
					psi, S;
	double f;

	cosTheta = (r*D + R*sqrt(D*D + R*R - r*r)) / (D*D + R*R);
	sinTheta = (r*R - D*sqrt(D*D + R*R - r*r)) / (D*D + R*R);

	while (cin >> time)
	{
		d_theta = -time/43200*PI;
		sinDel = sin(d_theta);
		cosDel = cos(d_theta);
		sinPhi = sinTheta*cosDel + cosTheta*sinDel;
		cosPhi = cosTheta*cosDel - sinTheta*sinDel;

		y = -r/sinPhi + D*cosPhi/sinPhi;
		y /= R;

		if (y <= -1)
			y = -1;
		if (y >= 1)
			y = 1;

		if (y >= 0)
		{
			psi = acos(y);
			S = 1 - (psi - y*sqrt(1 - y*y))/PI;
		} else
		{
			y = -y;
			psi = acos(y);
			S = (psi - y*sqrt(1 - y*y))/PI;
		}
		f = S;
		printf("%.6f",f);
		cout << endl;

	}
	return 0;
}