#include <fstream.h>
#include <string.h>

ifstream infile("flac.in");
ofstream outfile("flac.out");

char S[1000];
char P[1000];
int id[1000];
int L, N;

main()
{
	int i, j;
	while (!infile.eof())
	{
		infile.getline(S, 1000);

		L = strlen(S);
		N = 0;

		for (i = 0; i < L; i++)
			if ( (S[i] >= 'a' && S[i] <= 'z') ||
					(S[i] >= 'A' && S[i] <= 'Z')  )
			{
				P[N] = S[i];
				if (P[N] > 'Z')
					P[N] -= 'a' - 'A';
				id[N++] = i;
			}
		for (i = 0; i < N; i++)
		{
			for (j = i
