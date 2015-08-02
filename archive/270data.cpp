#include <fstream.h>
#include <stdlib.h>

ofstream outfile("INPUT.TXT");
int N = 300;

main()
{
	int i;
	outfile << 1 << endl << endl;

	for (i = 0; i < N; i++)
	{
		outfile << rand() % 100 << " " << rand() % 100 << endl;
	}

	outfile << endl;
}
