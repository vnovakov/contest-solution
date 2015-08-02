#include <fstream.h>
#include <stdlib.h>

ifstream infile("transfor.in");
ofstream outfile("transfor.out");

int start[10][10];
int finish[10][10];
int N;

int same()
{
	int i, j;
	int ret = 1;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (start[i][j] != finish[i][j])
				ret = 0;
	return ret;
}

void rotate()
{
	int after[10][10];
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			after[i][j] = start[j][N-1-i];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			start[i][j] = after[i][j];
}

void reflect()
{
	int after[10][10];
	int i, j;

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			after[i][j] = start[i][N-1-j];
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			start[i][j] = after[i][j];
}

void end(int i)
{
	outfile << i << endl;
	exit(0);
}

main()
{
	int i, j;
	char S[20];
	infile >> N;

	infile.getline(S, 20);
	for (i = 0; i < N; i++)
	{
		infile.getline(S, 20);
			for (j = 0; j < N; j++)
				start[i][j] = (S[j] == '-');
	}
	for (i = 0; i < N; i++)
	{
		infile.getline(S, 20);
			for (j = 0; j < N; j++)
				finish[i][j] = (S[j] == '-');
	}

	if (same())
		end(6);
	reflect();
	if (same())
		end(4);
	reflect();
	for (i = 1; i < 4; i++)
	{
		rotate();
		if (same())
			end(i);
		reflect();
		if (same())
			end(5);
		reflect();
	}
	end(7);

	return 0;
}
