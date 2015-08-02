#include <fstream.h>
#include <math.h>

ofstream outfile("QUIRK.TXT");

int ten = 1;

void print(int dig, int x)
{
	if (!dig)
		return;
	print(dig - 1, x / 10);
	outfile << x % 10;
}

int main()
{
	long power = 1;
	long x;
	long y;
	long square;
	long root;


	for (root = 0; root < ten; root++)
		power *= 10;

	power /= 2;

	for (y = 0; y < 2*power && power*power >= (2*power - 1)*y; y++)
	{
   	square = power*power - (2*power - 1)*y;
		root = (int)sqrt((double)square);
		if (root*root == square)
		{
			x = power - y + root;
			if (x >= 0 && x < 2*power)
			{	print(ten, x);
				print(ten, y);
				outfile << endl;
			}
			x = power - y - root;
			if (x >= 0 && x < 2*power)
			{	print(ten, x);
				print(ten, y);
				outfile << endl;
			}
		}
	}

	return 0;
}
