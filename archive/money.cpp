#include <fstream.h>

ifstream infile("money.in");
ofstream outfile("money.out");

unsigned long array[10000];

main()
{
	int V, N, i, j, money;

	infile >> V >> N;

	array[0] = 1;

	for (i = 1; i <= N; i++)
		array[i] = 0;

	for (j = 0; j < V; j++)
	{
		infile >> money;

		for (i = money; i <= N; i++)
			array[i] += array[i - money];
		cout << array[N] << endl;
	}

	outfile << array[N] << endl;

	return 0;
}

