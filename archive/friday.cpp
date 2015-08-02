#include <fstream.h>

ifstream infile("friday.in");
ofstream outfile("friday.out");

int regular[12] = {5,1,1,4,6,2,4,0,3,5,1,3};
int leap[12] =    {5,1,2,5,0,3,5,1,4,6,2,4};
int count[7] = {0,0,0,0,0,0,0};

main()
{
	int N , i;
	int year = 1900;
	int start = 2;

	infile >> N;

	for (; year - 1900 < N; year++)
	{
		if ((year % 4 != 0) || (year % 100 == 0 && year % 400 != 0))
		{
			for (i = 0; i < 12; i++)
				count[(regular[i] + start) % 7]++;
			start++;
		} else {
			for (i = 0; i < 12; i++)
				count[(leap[i] + start) % 7]++;
			start += 2;
		}
	}

	outfile << count[0];
	for (i = 1; i < 7; i++)
			outfile << ' ' << count[i];
	outfile << endl;
	return 0;
}
