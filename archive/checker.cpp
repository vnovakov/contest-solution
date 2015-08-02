#pragma option -O2

#include <fstream.h>
#include <time.h>

ifstream infile("checker.in");
ofstream outfile("checker.out");

int N;
int last;
long count = 0;

char Sdiag[27], Ddiag[27], col[14];
int pos[14];

void explore(int r)
{
	int i, up, down;
	if (r == N)
	{
		if (count < 3)
		{
		for (i = 0; i < N; i++)
			outfile << pos[i] + 1 << ' ';
		outfile << endl;
		}
		count++; return; }

	up = N;
	down = 0;

	if (N > 8)
	{
	if (!r)
			up /= 2;
	}

	for (i = down; i < up; i++)
	{
		if (!col[i] && !Sdiag[i + r] && !Ddiag[i - r + N - 1])
		{
			pos[r] = i;
			col[i] |= 1;
			 Sdiag[i + r] |= 1;
			  Ddiag[i - r + N - 1] |= 1;
			explore(r + 1);
			col[i] &= 0;
			Sdiag[i + r] &= 0;
			 Ddiag[i - r + N - 1] &= 0;
		}
	}

	if (N > 8)
	{
	if (!r)
	{

		count *= 2;

		if (N % 2 == 1)
		{
			i = N / 2;
		if (!col[i] && !Sdiag[i + r] && !Ddiag[i - r + N - 1])
		{
			pos[r] = i;
			last = i;
			col[i] = Sdiag[i + r] = Ddiag[i - r + N - 1] = 1;
			explore(r + 1);
			col[i] = Sdiag[i + r] = Ddiag[i - r + N - 1] = 0;
		}
		}
	}
	}



}
main()
{
	int i;
	infile >> N;

	for (i = 0; i < N; i++)
		col[i] = 0;
	for (i = 0; i < 2*N - 1; i++)
		Sdiag[i] = Ddiag[i] = 0;
	last = N + 1;

	explore(0);

	outfile << count << endl;

	cout << (float)clock() / CLOCKS_PER_SEC << endl;

	return 0;
}
