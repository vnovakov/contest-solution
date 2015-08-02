#include <iostream.h>
#include <fstream.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

int n;
int newIndex[21];
int array[21];
int inc[21];

main()
{
	int i, j, a, max;
	cin >> n;

	for (i = 0; i < n; i++)
	{	cin >> a;
		newIndex[a] = i; }

	while(1)
	{
		for (i = 0; i < n; i++)
		{
			if (cin >> a)
				array[i] = newIndex[a];
			 else
				return 0;
		}
		inc[0] = 1;

		for (i = 1; i < n; i++)
		{
			max = 1;
			for (j = 0; j < i; j++)
				if (array[j] < array[i])
					if (inc[j] + 1 > max)
						max = inc[j] + 1;
			inc[i] = max;
		}
		max = 0;
		for (i = 0; i < n; i++)
			if (inc[i] > max)
				max = inc[i];
		cout << max << endl;
	}

}


