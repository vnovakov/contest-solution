#include <fstream.h>

ifstream infile("race3.in");
ofstream outfile("race3.out");

int N;
int nN[50];
int neighbors[50][50];
int isSplit[50];
int isUnavoid[50];
int bad;
int badA;
int badB;
int visited[50];
int visitedA[50];
int visitedB[50];

void explore(int i)
{
	visited[i] = 1;
	int j, k;
	for (j = 0; j < nN[i]; j++)
	{
		k = neighbors[i][j];
		if (!visited[k] && k != bad)
			explore(k);
	}
	}

void exploreA(int i)
{
	visitedA[i] = 1;
	int j, k;
	for (j = 0; j < nN[i]; j++)
	{
		k = neighbors[i][j];
		if (!visitedA[k] && k != badA)
			exploreA(k);
	}
}
void exploreB(int i)
{
	visitedB[i] = 1;
	int j, k;
	for (j = 0; j < nN[i]; j++)
	{
		k = neighbors[i][j];
		if (!visitedB[k] && k != badB)
			exploreB(k);
	}
}


main()
{

	int i, j, k, good, a;

	for (i = 0; i < 50; i++)
		nN[i] = 0;

	N = 0;
	while (1)
	{
		while (1)
		{
			infile >> a;
			if (a == -2)
			{
				N++;
				break;
			}
			if (a == -1)
				goto finish;
			neighbors[N][nN[N]] = a;
			nN[N]++;
		}
	}

	finish:
	;
	k = 0;
	for (i = 1; i < N; i++)
	{
		// compute isUnavoid

		bad = i;

		for (j = 0; j <= N; j++)
			visited[j] = 0;
		explore(0);
		isUnavoid[i] = !visited[N];
      k += isUnavoid[i];
	}
	outfile << k;
	for (i = 1; i < N; i++)
		if (isUnavoid[i])
			outfile << ' ' << i;
	outfile << endl;
	k =0;
	for (i = 1; i < N; i++)
	{
		// compute isSplit

		badA = i;
		badB = -1;

		for (j = 0; j <= N; j++)
			visitedA[j] =  visitedB[j] = 0;
		exploreA(0);
		exploreB(i);
		good = 0;
		for (j = 0; j <= N; j++)
			if (visitedA[j] && visitedB[j])
				good = 1;
		isSplit[i] = !good;
		k += isSplit[i];
	}
	outfile << k;
	for (i = 1; i < N; i++)
		if (isSplit[i])
			outfile << ' ' << i;
	outfile << endl;

	return 0;
}



