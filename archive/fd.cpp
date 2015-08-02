#include <fstream.h>

ofstream outfile("fence4.in");

main()
{
	int i;
	int j;
/*
	j = 0;
	for (i = 0; i < 50; i++)
		outfile << j << ' ' << i << endl;
	for (; j < 50; j++)
		outfile << j << ' '  << i << endl;
	for (; i >= 0; i--)
		outfile << j << ' ' << i << endl;
	for (i = 0; --j > 0; )
		outfile << j << ' ' << i << endl;
*/
	for (i = 0; i < 98; i++)
   	outfile << i << " 0" << endl << i + 1 << " 1" << endl;
	return 0;
}

