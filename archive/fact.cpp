#include <fstream.h>

ifstream infile("fact.in");
ofstream outfile("fact.out");

main()
{
	int i, j, N;
	int D;
	infile >> N;
	int k;

		D = 1;
		for (i = 1; i <= N; i++)
		{
			j = i;

			while (j % 10 == 0)
				j /= 10;
			D *= (j % 10);
				while (D % 10 == 0)
				D /= 10;
			D %= 10;
		}

	outfile << D << endl;
	return 0;
}


