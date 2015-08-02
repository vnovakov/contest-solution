#include <iostream.h>
#include <string.h>
#include <math.h>

char names[100][30];
double lat[100], lon[100];
int nameL[100];
int n;
double R = 6378;
double PI =  3.141592653589793;

int getNum(char name[30])
{
	int i, j, ok;
	for (i = 0; i < n; i++)
		if (nameL[i] == strlen(name))
		{
			ok = 1;
			for (j = 0; j < strlen(name); j++)
				if (names[i][j] != name[j])
				{	ok = 0; break; }
			if (ok == 1)
				return i;
		}
	return i;
}

main()
{
	n = 0;
	int i, j; double theta1, phi1, theta2, phi2, d, D;
	double x1, y1, z1, x2, y2, z2;
	char s[34], t[34];
	while (1)
	{
		cin >> s;
		if (s[0] == '#')
			break;
		for (i = 0; i < strlen(s); i++)
			names[n][i] = s[i];
		nameL[n] = strlen(s);
		cin >> lat[n] >> lon[n];
		n++;
	}
	while (1)
	{
		cin >> s;
		if (s[0] == '#')
			break;
		cin >> t;
		cout << s << " - " << t << endl;
		i = getNum(s);
		j = getNum(t);
		if (i == n || j == n)
			cout << "Unknown" << endl;
		else
		{
			theta1 = lon[i] / 180 * PI + PI;
			theta2 = lon[j] / 180 * PI + PI;
			phi1 = (90 - lat[i]) / 180 * PI;
			phi2 = (90 - lat[j]) / 180 * PI;
			x1 = R*sin(phi1)*cos(theta1);
			x2 = R*sin(phi2)*cos(theta2);
			y1 = R*sin(phi1)*sin(theta1);
			y2 = R*sin(phi2)*sin(theta2);
			z1 = R*cos(phi1);
			z2 = R*cos(phi2);
			d = sqrt((x1 - x2)*(x1 - x2) +
						(y1 - y2)*(y1 - y2) +
						(z1 - z2)*(z1 - z2));
			D = R*2*asin(d/(2*R));
			if (D - int(D) >= D + 1 - int(D))
				D++;

			cout << int(D) << " km" << endl;
		}
	}

	return 0;
}

