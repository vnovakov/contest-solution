//### PROGRAM
/*
ID: vnovako001
PROG: ariprog
*/
#include <fstream.h>
#include <time.h>

ifstream infile("ariprog.in");
ofstream outfile("ariprog.out");

int huge array[200000];

long limit;

main()
{
	long length, M, L;
	double time_0;
	int some = 0;
	long diff, i, j, start, start_0;

	time_0 = clock();

	infile >> length >> M;

	limit = (long)M*M + (long)M*M;

	for (i = 0; i <= limit; i++)
		array[i] = 0;
	for (i = 0; i <= M; i++)
		for (j = 0; j <= M; j++)
			array[(long)i*i + (long)j*j] = 1;


	if (length < 4)
	{
	for (diff = 1; diff <= limit / (length - 1); diff++)
	{

		for (start_0 = 0; start_0 <= limit; start_0++)
			if (array[start_0])
			{
				 start = start_0;
				L = 1;
				while (array[start])
				{
					start += diff;
					if (start > limit || !array[start])
						break;
					L++;
					if (L == length)
					{
						outfile << start_0 << ' ' << diff << endl;
						some = 1;
						break;
					}
				}
			}
	}

	} else {
	for (diff = 4; diff <= limit / (length - 1); diff += 4)
	{
		if (((double)clock() - time_0) / CLOCKS_PER_SEC > 12)
      	break;
		for (start_0 = 0; start_0 <= limit; start_0++)
			if (array[start_0])
			{
				 start = start_0;
				L = 1;
				while (array[start])
				{
					start += diff;
					if (start > limit || !array[start])
						break;
					L++;
					if (L == length)
					{
						outfile << start_0 << ' ' << diff << endl;
						some = 1;
						break;
					}
				}
			}
	}
	}

	if (!some)
		outfile << "NONE" << endl;
	return 0;
}

//### END
