#include <fstream.h>

ifstream infile("pal.in");
ofstream outfile("pal.out");

int B;

void print(long a)
{
	if (!a)
		return;
	print (a / B);
	a %= B;
	if (a < 10)
		outfile << a;
	else
		outfile << (char)('A' + a - 10);
}

main()
{
	int i, d, k; long j;
	int works;
	int dig[100];
	infile >> B;

	for (i = 1; i <= 300; i++)
	{
		j = (long)i*i;
		d = 0;
		works = 1;
		while (j)
		{
			dig[d++] = j % B;
			j /= B;
		}
		for (k = 0; k < d; k++)
			if (dig[k] != dig[d-1-k])
				works = 0;
		if (works)
		{
			print(i);
			outfile << ' ';
			print((long)i*i);
			outfile << endl;
		}
	}

	return 0;
}
