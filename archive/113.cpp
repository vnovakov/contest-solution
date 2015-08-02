/* @JUDGE_ID: 3207EZ 113 C++ "Logarithms" */

#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <string.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

main()
{
	int i, n;
	char N[105];
	int nd, ne;
	double l;
	long first, c;

	while (infile >> n)
	{
		infile >> N;
		nd = strlen(N) ;
		ne = nd - 1;
		first = 0;
		for (i = 0; i < 9 && i <= ne; i++)
		{
			first = (long)10*first + N[i] - '0';
			nd--;
		}		l = (double)nd*log(10) + log(first);
		l /= n;
		l = exp(l);
		c = l;
		if ((double)l - c < 0.00001)
			outfile << c << endl;
		else
		{	c = ceil(l);
			outfile << c << endl;
		}
	}

	return 0;
}

