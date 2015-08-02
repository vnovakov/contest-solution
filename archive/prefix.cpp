#include <fstream.h>
#include <string.h>

ifstream infile("prefix.in");
ofstream outfile("prefix.out");

char huge S[200000];
int huge pos[200000];
int length[200];

char pre[200][10];
int count;
int N;

main()
{

	int i, j, k, q = -1, good;
	char str[1000];
	count = N; int max_length = 0, run_0 = 0;

	while (1)
	{
		infile >> str;
		if (str[0] == '.')
			break;

		count++;
		length[count - 1] = strlen(str);
		if (length[count - 1] > max_length)
			max_length = length[count - 1];
		for (i = 0; i < length[count - 1] ;i++)
      	pre[count-1][i] = str[i];
	}
	infile.getline(str, 1000);
	while (!infile.eof())
	{
		infile.getline(str, 1000);

		N += strlen(str);

		for (i = N - strlen(str); i < N; i++)
			S[i] = str[i - (N - strlen(str))];
	}

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < count; j++)
		{
			if ((length[j] <= i && pos[i - length[j]]) || length[j] - i == 1)
			{
				good = 1;
				for (k = 0; k < length[j] ; k++)
						if (S[i - length[j] + k + 1] != pre[j][k])
							good = 0;
				if (good)
					pos[i] = 1;
			}
		}

		if (!pos[i])
			run_0++;
		else
		{
			run_0 = 0;
			q = i;
		}
		if (run_0 > max_length)
			break;
	}
	outfile << q + 1<< endl;

	return 0;
}
