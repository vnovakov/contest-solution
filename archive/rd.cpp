#include <fstream.h>
#include <stdlib.h>

ofstream outfile("range.in");

int N;

main()
{
	int i, j;
   randomize();

	N = 15;

	outfile << N << endl;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{

				outfile << 1;
	
		}
		outfile << endl;
	}

	return 0;
}