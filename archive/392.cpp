#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

main()
{
	int poly[9]; int i, first;

	while (1)
	{
		for (i = 8; i >= 1; i--)
			infile >> poly[i];
		if (!(infile >> poly[0]))
			break;
		first = 1;

		for (i = 8; i >= 0; i--)
			if (poly[i] || (!i && first))
			{
				if (first)   {
					first = 0;
					if (poly[i] < 0)
						outfile << "-";
					if (poly[i] != 1 || !i)
						outfile << abs(poly[i]);
					if (i)   {
						outfile << "x";
						if (i > 1)
							outfile << "^" << i;
						}
				}
			 else {
					outfile << " ";
					if (poly[i] < 0)
						outfile << "- ";
					else
						outfile << "+ ";
					if (poly[i] != 1 || !i)
						outfile << abs(poly[i]);
					if (i)   {
						outfile << "x";
						if (i > 1)
							outfile << "^" << i;
						}
				 }

			}
	 outfile << endl;
	}

	return 0;
}

