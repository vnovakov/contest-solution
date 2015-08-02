#pragma option -O2

#include <fstream.h>
#include <time.h>

ifstream infile("checker.in");
ofstream outfile("checker.out");

int N;
int last;
long count = 0;
long fullCount = 0;

char Sdiag[27], Ddiag[27], col[14];
int dont[14][14];
int pos[14];

void explore(int r)
{
	int i;
	if (r == N)
	{
		count++;
		return; }


	for (i = 0; i < N; i++)
	{
		if (!dont[r][i] && !col[i] && !Sdiag[i + r] && !Ddiag[i - r + N - 1])
		{
			col[i]++;
			 Sdiag[i + r]++;
			  Ddiag[i - r + N - 1]++;
			explore(r + 1);
			col[i] = 0;
			Sdiag[i + r] = 0;
			 Ddiag[i - r + N - 1] = 0;
		}
	}


}
main()
{
	int i, j;
	infile >> N;


// ADFH

	for (i = 0; i < N; i++)
		col[i] = 0;
	for (i = 0; i < 2*N - 1; i++)
		Sdiag[i] = Ddiag[i] = 0;

	count = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			dont[i][j] = 0;

	for (i = N/2; i < N; i++)
		dont[0][i] = 1;
	for (i = 0; 2*i < N; i++)
		dont[N - 1][i] = 1;
	for (i = 0; 2*i < N; i++)
		dont[i][0] = dont[i][N - 1] = 1;

	explore(0);

	fullCount += 8*count;

// ACEG

	for (i = 0; i < N; i++)
		col[i] = 0;
	for (i = 0; i < 2*N - 1; i++)
		Sdiag[i] = Ddiag[i] = 0;

	count = 0;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			dont[i][j] = 0;

	for (i = N/2; i < N; i++)
	{
		dont[0][i] = 1;
		dont[N-1][i] = 1;
		dont[i][0] = 1;
		dont[i][N-1] = 1;
	}

	explore(0);

	fullCount += 4*count;


	outfile << fullCount << endl;

	cout << (float)clock() / CLOCKS_PER_SEC << endl;

	return 0;
}
