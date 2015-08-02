/* @JUDGE_ID: 3207EZ 413 C++ */
#include <iostream.h>
#include <stdio.h>

unsigned int array[30];
int total[3], count[3];
int diff[30];
int N;

main()
{
	int i, quit = 0, start;

	while (1)
	{
		N = 0;
		while (1)
		{
			cin >> array[N];
			if (!array[N])
			{	if (!N)
					quit = 1;
				break;
			}
			N++;
		}
		if (quit)
			break;
		for (i = 0; i < N - 1; i++)
		{
			if (array[i+1] > array[i])
				diff[i] = 1;
			else if (array[i+1] < array[i])
				diff[i] = -1;
			else
				diff[i] = 0;
		}
		total[0] = total[1] = total[2] = 0;
		count[0] = count[1] = count[2] = 0;
		i = 0; start = 0;
		while (diff[i] == 0 && i < N - 1)
		{
			i++;
			start++;
		}
		if (i != N - 1)
		{
			total[diff[i] + 1] = 1 + start;
			count[diff[i] + 1] = 1;
		}
		for (i++; i < N - 1; i++)
		{
			if (diff[i] == diff[i - 1] || diff[i] == 0)
			{
				total[diff[i - 1] + 1]++;
            diff[i] = diff[i - 1];
			}
			else
			{	total[diff[i] + 1]++;
				count[diff[i] + 1]++;
			}
		}
		if (total[0] == 0) count[0] = 1;
		if (total[2] == 0) count[2] = 1;
		printf("Nr values = %d:  %.6f %.6f\n", N,
															 (float)total[2]/count[2],
															 (float)total[0]/count[0]);
	}

	return 0;
}
