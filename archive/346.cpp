/* @JUDGE_ID: 3207EZ 346 C++ */
#include <iostream.h>
#include <string.h>

int sf(char c)
{
	if (c == '#')
		return 1;
	else
		return -1;
}

void print(int a)
{
	if (a == 0)
		cout << "C";
	else if (a == 1)
		cout << "C#";
	else if (a == 2)
		cout << "D";
	else if (a == 3)
		cout << "D#";
	else if (a == 4)
		cout << "E";
	else if (a == 5)
		cout << "F";
	else if (a == 6)
		cout << "F#";
	else if (a == 7)
		cout << "G";
	else if (a == 8)
		cout << "G#";
	else if (a == 9)
		cout << "A";
	else if (a == 10)
		cout << "A#";
	else if (a == 11)
		cout << "B";
}

int note(char c)
{
	if ((c == 'a') || (c == 'A'))
		return 9;
	if ((c == 'b') || (c == 'B'))
		return 11;
	if ((c == 'c') || (c == 'C'))
		return 0;
	if ((c == 'd') || (c == 'D'))
		return 2;
	if ((c == 'e') || (c == 'E'))
		return 4;
	if ((c == 'f') || (c == 'F'))
		return 5;
	if ((c == 'g') || (c == 'G'))
		return 7;
}

int check(int a, int b, int c)
{
	if (((b - a == 4) || (b - a == -8)) && ((c - b == 3) || (c - b == -9)))
		return 1;
	else if (((b - a == 3) || (b - a == -9)) && ((c - b == 4) || (c - b == -8)))
		return -1;
	return 0;
}

main()
{
	char a[4], b[4], c[4];
	int x, y, z; int rec; int what; int t;

	while (cin >> a >> b >> c)
	{
		x = note(a[0]);
		y = note(b[0]);
		z = note(c[0]);
		if (strlen(a) == 2)
			x = (x + sf(a[1])) % 12;
		if (strlen(b) == 2)
			y = (y + sf(b[1])) % 12;
		if (strlen(c) == 2)
			z = (z + sf(c[1])) % 12;
		rec = 0;
		if (check(x,y,z) == 1)
		{	rec = 1; what = x; t = 1; }
		if (check(x,y,z) == -1)
		{	rec = 1; what = x; t = -1; }
		if (check(x,z,y) == 1)
		{	rec = 1; what = x; t = 1; }
		if (check(x,z,y) == -1)
		{	rec = 1; what = x; t = -1; }
		if (check(y,x,z) == 1)
		{	rec = 1; what = y; t = 1; }
		if (check(y,x,z) == -1)
		{	rec = 1; what = y; t = -1; }
		if (check(y,z,x) == 1)
		{	rec = 1; what = y; t = 1; }
		if (check(y,z,x) == -1)
		{	rec = 1; what = y; t = -1; }
		if (check(z,x,y) == 1)
		{	rec = 1; what = z; t = 1; }
		if (check(z,x,y) == -1)
		{	rec = 1; what = z; t = -1; }
		if (check(z,y,x) == 1)
		{	rec = 1; what = z; t = 1; }
		if (check(z,y,x) == -1)
		{	rec = 1; what = z; t = -1; }
		cout << a << " " << b << " " << c << " is";
		if (!rec)
			cout << " unrecognized." << endl;
		else {
			cout << " a "; print(what);
			if (t == 1)
				cout << " Major chord." << endl;
			else
				cout << " Minor chord." << endl;
		}
	}

	return 0;
}
