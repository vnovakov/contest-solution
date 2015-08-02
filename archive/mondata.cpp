#include <fstream.h>
#include <stdlib.h>

ofstream outfile("money.in");

main()
{
	int N, M;

	randomize();

	N = 25; M = 100;
	outfile << N << " " << M << endl;


	while (N--)
		outfile << N + 13 << endl;

	return 0;
}
