#include <iostream.h>
#include <math.h>

main()
{
	float a = 3, b = 5, c = 7;
	float s = (a + b + c) / 2;
	float K = sqrt(s*(s-a)*(s-b)*(s-c));
	float R = a*b*c/K/4;

	cout << "Left-hand side: " << a*b*c / (R * (a*a + b*b + c*c - 8*R*R));
	cout << endl << "Right-hand side: " << sqrt(3)*3 << endl;
}
