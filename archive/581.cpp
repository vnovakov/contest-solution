#include <iostream.h>
#include <fstream.h>
#include <string.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

char matrix[50][500];
char S[200];
char words[128][32];
int nWords;
int length[128];
int N, M = 0;

main()
{
	int i, j, k, nLines;

	infile >> N >> nWords;

	for (i = 0; i < nWords; i++)
	{
		infile >> S;
		length[i] = strlen(S);
		for (j = 0; j < length[i]; j++)
			words[i][j] = S[j];
	}

	infile >> nLines;
	infile.getline(S, 200);
	k = -1; M = 0;

	for (i = 0; i < nLines; i++)
	{
		infile.getline(S, 200);
		for (j = 0; j < strlen(S); j++)
			if (S[j] >= 'A' && S[j] <= 'Z')
			{	k++; if (k == N) { k = 0; M++; }
				matrix[k][M] = S[j];
			}
	}
	for (k++; k != N; k++)
   	matrix[k][M] = ' ';


	for (i = 0; i < nWords; i++)
	{
		for (j = 0; j < N; j++)
			for (k = 0; k < M; k++)


	return 0;
}



