#include <iostream.h>

char matrix[10][10];

main()
{
	char S[200];
	int nLines;
	int i, j, row = 0, col = 0;

	while (1)
	{
		cin >> nLines;
		if (!nLines)
			break;
		cin.getline(S, 200);

		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				matrix[i][j] = 0;
		row = 0;
      col = 0;

		while (nLines--)
		{
			cin.getline(S, 200);

