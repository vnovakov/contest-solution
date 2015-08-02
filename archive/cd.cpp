#include <fstream.h>

ofstream outfile("castle.in");

main()
{
	int i, j;

	outfile << "32 32" << endl;

	for (i = 0; i < 32; i++)
	{
		for (j = 0; j < 32; j++)
			if (j == 15)
				outfile << "4 ";
			else if (j == 16)
				outfile << "1 ";
			else
				outfile << "0 ";
		outfile << endl;
	}



	return 0;
}
