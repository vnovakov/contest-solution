/* @JUDGE_ID: 3207EZ 190 C++ */
#include <iostream.h>
#include <math.h>

void out(double s, int sign)
{
	int n;

	if (s < 0)
	{  if (sign)
			cout << "- ";
		s = -s;
	} else {
		if (sign)
			cout << "+ ";
	}

	cout << int(s) << ".";

	s -= int(s);

	n = 1000*s;

	if ((double)(1000*s - n) >= double(n + 1 - 1000*s))
		n++;

	if (n < 10)
		cout << "00" << n;
	else if (n < 100 )
		cout << "0" << n;
	else
		cout << n;
}

main()
{
	double x1, x2, x3, y1, y2, y3;
	double h, k, r, c, d, e, aa, bb, cc, dd, ee, ff;
	int s = 0;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		if (s)
			cout << endl;
		if (!s) s = 1;
		aa = 2*(x2 - x1);
		bb = 2*(y2 - y1);
		cc = x2*x2 + y2*y2 - x1*x1 - y1*y1;
		dd = 2*(x3 - x1);
		ee = 2*(y3 - y1);
		ff = x3*x3 + y3*y3 - x1*x1 - y1*y1;
		h = ( bb*ff - ee*cc) / (aa*ee - bb*dd);
		k = (dd*cc - aa*ff) / (aa*ee - bb*dd);
		r = (double)sqrt((h + x1)*(h + x1) + (k + y1)*(k + y1));
		cout << "(x ";
		out(h,1);
		cout << ")^2 + (y ";
		out(k,1);
		cout << ")^2 = ";
		out(r,0);
		cout << "^2" << endl;
		c = 2*h;
		d = 2*k;
		e = h*h + k*k - r*r;
		cout << "x^2 + y^2 ";
		out(c,1);
		cout << "x "; out(d,1); cout << "y "; out(e,1); cout << " = 0" << endl;
	}

	return 0;

}
