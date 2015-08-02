/* @JUDGE_ID: 3207EZ 485 C++ "DP" */

#include <iostream.h>
#include <fstream.h>

ofstream outfile("OUTPUT.TXT");

main()
{
	int i, j;
	long array[24][24];

	for (i = 0; i < 24; i++)
	{
		array[i][0] = 1;
		outfile << array[i][0];
		for (j = 1; j < i; j++)
		{
			array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
			outfile << ' ' << array[i][j];
		}
		if (i)
		{
		array[i][i] = 1;
		outfile << " 1" << endl;
		}
		else
      	outfile << endl;
	}

	return 0;
}
