/* @JUDGE_ID: 3207EZ 414 C++ */
#include <iostream.h>
#include <string.h>

int matrix[20][25];
int N;

main()
{
	int i;
	int j;
	int blank;
	int min, max, sep;
	char S[30];

	while (1)
	{
		cin >> N;
		if (!N)
			break;
		max = -1; min = 25; sep = 25; blank = 0;
		cin.getline(S, 30);
		for (i = 0; i < N; i++)
		{
			cin.getline(S, 30);
			for (j = 0; j < 25; j++)
			{
				matrix[i][j] = (S[j] == 'X') ? 1 : 0;
				if (!matrix[i][j])
					blank++;
			}

		}

		for (i = 0; i < N; i++)
		{
			min = 25;
			max = -1;
			for (j = 0; j < 25; j++)
				if (!matrix[i][j])
				{
					if (j > max)
						max = j;
					if (j < min)
						min = j;
				}
			if (max - min + 1 < sep)
				sep = max - min + 1;
		}

		if (sep < 0)
			sep = 0;
		cout << blank - N*sep << endl;
	}

	return 0;
}
