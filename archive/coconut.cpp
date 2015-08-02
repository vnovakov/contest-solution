#include <fstream.h>
#include <math.h>

ifstream infile("coconut.in");
ofstream outfile("coconut.out");

int N;

main()
{
	long C;
	int i;
	long amount[10] = {0,0,0,0,0,0,0,0,0,0};

	 infile >> N;

	C = (long)pow((long)N, N + 1) + 1 - N;

	outfile << C;

	for (i = 0; i < N; i++)
	{
		C--;
		amount[i] += C / N;
		C = (N - 1) * C / N;
	}

	for (i = 0; i < N; i++)
	{
		amount[i] += C / N;
	}

	for (i = 0; i < N; i++)
		outfile << ' ' << amount[i];
	outfile << endl;

	return 0;
}
