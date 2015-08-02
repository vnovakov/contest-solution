//### PROGRAM
/*
  ID: vnovako001
  PROG: frameup
*/

#include <fstream.h>
#include <stdlib.h>

ifstream infile("frameup.in");
ofstream outfile("frameup.out");


int W, H;
char matrix[30][30];
int N;
char letter[100];
int left[100], right[100], up[100], down[100];
int id[255];
int top[26][26];
int in[26];
int perm[26];
int order[26];
int done[26];


int cmp(void const *a, void const *b)
{
	char A = letter[*(int *)a];
	char B = letter[*(int *)b];
	if (A > B)
		return 1;
	return -1;
}

void explore(int a)
{
	int i, j, k;
	int backup[26], nB = 0;
	if (a == N)
	{
		for (i = 0; i < N; i++)
			outfile << letter[order[i]];
		outfile << endl;
	}
	else {

		for (i = 0; i < N; i++)
			if (in[perm[i]] == 0 && !done[perm[i]])
		{

			nB = 0;
			for (j = 0; j < N; j++)
			{
				if (top[j][perm[i]])
				{
					backup[nB++] = j;
					top[j][perm[i]] = 0;
					in[j]--;
				}
			}
			order[a] = perm[i];
			done[perm[i]] = 1;
			explore(a + 1);
			done[perm[i]] = 0;
			for (j = 0; j < nB; j++)
			{
				in[backup[j]]++;
				top[backup[j]][perm[i]] = 1;
			}
		}
	}
}

main()
{
	int i, j, g;
	int a, b;
	char c, d;
	char S[100];

	infile >> H >> W;
	infile.getline(S, 100);

	N = 0;

	for (i = 0; i < 255; i++)
	{
		id[i] = -1;
		up[i] = -1;
		down[i] = -1;
	}

	for (i = 0; i < H; i++)
	{
		infile.getline(S, 100);

		for (j = 0; j < W; j++)
		{
			matrix[i][j] = S[j];
			if (S[j] != '.')
			{
			if (id[S[j]] == -1)
			{
				id[S[j]] = N;
				letter[N] = S[j];
				left[N] = j;
            right[N] = j;
				up[N] = i;
				N++;
			} else if (up[id[S[j]]] == i) {
				if (j > right[id[S[j]]])
				right[id[S[j]]] = j;
				if (j < left[id[S[j]]])
				left[id[S[j]]] = j;
			} else if (up[id[S[j]]] != i && up[id[S[j]]] != -1)
			{
				if (j > right[id[S[j]]])
					right[id[S[j]]] = j;
				if (j < left[id[S[j]]])
				left[id[S[j]]] = j;
				down[id[S[j]]] = i;



			}
			}
		}
	}

	for (i = 0; i < N; i++)
	{
		perm[i] =i;
		in[i] = 0;
		done[i] = 0;
	}



	for (i = 0; i < H; i++)
		for (j = 0; j < W; j++)
		{
			a = id[matrix[i][j]];

			for (b = 0; b < N; b++)
				if (a == b)
					top[a][a] = 0;
				else if (top[a][b] == 0) {
					if ( ((j == left[b] || j == right[b]) &&
						  (up[b] <= i && down[b] >= i)) ||
						((i == up[b] || i == down[b]) &&
						  (left[b] <= j && right[b] >= j)) )
						  {
						top[a][b] = 1;
						in[a]++;
						}
					else
						top[a][b] = 0;
				}
		}

	qsort(perm, N, sizeof(int), cmp);
	explore(0);


	return 0;
}

//### END