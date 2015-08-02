//### PROGRAM
/*
ID: vnovako001
PROG: fence
*/
#include <fstream.h>

ifstream infile("fence.in");
ofstream outfile("fence.out");

int F, N;
int huge matrix[500][500];
int degree[5000];
int circuit[5000];
int circuitSize = 0;
int temp[5000];
int size = 0;

void findCircuit(int i)
{
	int j;


	while (degree[i])


	{
		temp[size++] = i;

		for (j = 0; j < N; j++)
			if (matrix[i][j])
				break;
		matrix[i][j]--;
		matrix[j][i]--;
		degree[i]--;
		degree[j]--;

		i = j;
	}
}

int splice(int array[500], int size, int pos)
{
	int j;

		for (j = circuitSize + size - 1; j >= pos + size; j--)
			circuit[j] = circuit[j - size];

	for (j = pos; j < pos + size; j++)
		circuit[j] = array[j - pos];
	circuitSize += size;
}

main()
{
	int i, j, a, b;
	int start, end;

	int pos = 0;

	infile >> F;

	for (i = 0; i < 500; i++)
		for (j = 0; j < 500; j++)
			matrix[i][j] = degree[i] = 0;
		N = 0;

	for (i = 0; i < F; i++)
	{
		infile >> a >> b;
		a--;
		b--;
		if (a + 1 > N)
			N = a + 1;
		if (b + 1 > N)
			N = b + 1;
		matrix[a][b]++; matrix[b][a]++;
		degree[a]++; degree[b]++;
	}

	j = 0;
	start = -1;
	end = -1;
	for (i = 0; i < N; i++)
		if (degree[i] % 2 == 1)
		{
			if (start == -1)
			{	j = -1;
				start = i;
			}
			else
				end = i;
		}

	if (start == -1)
		start = 0;

	findCircuit(start);

	if (j == 0)
		temp[size++] = start;
	else
   	temp[size++] = end;


	pos = 0;
	splice( temp, size, pos);  // array, size, before what

	while (1)
	{
		j = -1;
		for (i = circuitSize - 1; i >= 0; i--)
			if (degree[circuit[i]])
			{  j = circuit[i]; break; }
		if (j == -1)
			break;
		pos = i;
		size = 0;
		findCircuit( j );
		splice (temp, size, pos);
	}

	for (i = 0; i < circuitSize; i++)
		outfile << circuit[i]+1  << endl;

	return 0;

}

//### END
