#include <fstream.h>

ifstream infile("zerosum.in");
ofstream outfile("zerosum.out");

int N;


main()
{
	int pow3 = 1, p, q, doWhat;
	int bits[10];
	int i;
	long sum, curr;

	infile >> N;

	for (i = 1; i < N; i++)
		pow3 *= 3;

	for (p = 0; p < pow3; p++)
	{

		q = p;
		for (i = N - 1; i >= 1; i--)
		{
			bits[i] = q % 3;
			q /= 3;
		}

		sum = 0; curr = 1;
		doWhat = 1;

		for (i = 1; i < N; i++)
		{
			q = bits[i];
			if ( q == 0)
			{
				//' '
				curr = 10*curr + i + 1;
			} else if (q  == 1)
			{
				//'+'
				sum += doWhat * curr;
				curr = i + 1;

				doWhat = 1;
			} else {
				//'-'
				sum += doWhat * curr;
				curr = i + 1;

				doWhat = -1;
			}

			bits[i] = q % 3;
			q /= 3;
		}
				sum += doWhat * curr;

		if (sum == 0)
		{
			outfile << 1;
			for (i = 1; i < N; i++)
			{
				if (bits[i] == 0)
					outfile << ' ';
				else if (bits[i] == 1)
					outfile << '+';
				else
					outfile << '-';
				outfile << (i + 1);
			}
         outfile << endl;
		}

	}

	return 0;
}




