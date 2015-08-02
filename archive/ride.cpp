
#include <fstream.h>
#include <string.h>

ifstream infile("ride.in");
ofstream outfile("ride.out");

main()
{
	char S[100];
	char T[100];
	int p = 1, q = 1;

	int m, n;

	infile >> S >> T;

	m = strlen(S);
	n = strlen(T);

	while (m--)
	{
		p *= (S[m] - 'A' + 1);
		p %= 47;
	}
	while (n--)
	{
		q *= (T[n] - 'A' + 1);
		q %= 47;
	}

	if (p == q)
		outfile << "GO" << endl;
	else
		outfile << "STAY" << endl;

	return 0;
}