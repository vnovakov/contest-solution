#include <iostream.h>
#include <math.h>

const double PI = 3.1415926535;

void out(double S)
{
	double R = 100*S;
	long Q = R;
	if (S < 0.005)
	{	cout << "0.00" << endl; return; }
	if ((R - Q) >= (Q + 1 - R))
		Q = Q + 1;
	int array[10];
	int i, k = 0;
	if (Q < 10) {
		cout << "0.0" << Q << endl; return; }
	else if (Q < 100) {
		cout << "0." << Q << endl; return; }
	while (Q)
	{
		array[k++] = Q % 10;
		Q /= 10;
	}
	for (i = k - 1; i >= 0; i--)
	{
		cout << array[i];
		if (i == 2)
			cout << '.';
	}
	cout << endl;
}

main()
{
	double x1, x2, x3, y1, y2, y3, a, b, c, s;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		a = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
		b = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1));
		c = sqrt((x2 - x3)*(x2 - x3) + (y2 - y3)*(y2 - y3));
		s = (x1*y2 + x2*y3 + y1*x3 - x1*y3 - y1*x2 - x3*y2);
		if (s < 0)
			s = -s;
		out(PI*a*b*c/s);
	}
}
