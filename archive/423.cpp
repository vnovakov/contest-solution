#include <iostream.h>
#include <string.h>

	int n;
	int i, j, k, ii;
	char S[100];
	int matrix[100][100];
	int done[100]; int length[100];
   int temp, min;


main()
{

	cin >> n;

	for (i = 0; i < n; i++)
		matrix[i][i] = 0;

	for (i = 1; i < n; i++)
		for (j = 0; j < i; j++)
		{	temp = 0;
			cin >> S;
			if (S[0] == 'x')
				matrix[i][j] = matrix[j][i] = 0;
			else  {
				for (k = 0; k < strlen(S); k++)
					temp = 10*temp + S[k] - '0';
				matrix[i][j] = matrix[j][i] = temp;
			}
		}

	for (i = 0; i < n; i++)
	 {		done[i] = 0; length[i] = -1; }

	length[0] = 0;

	while(1)
	{
		for (i = 0; i < n; i++)
			if (done[i] == 0)
				goto proceed;

		break;

		proceed:
		;

		min = 32000;

		for (i = 0; i < n; i++)
			if (done[i] == 0)
				if (length[i] != -1 && length[i] < min)
				{
					min = length[i]; ii = i; }

		done[ii] = 1;
		for (i = 0; i < n; i++)
			if (matrix[i][ii] &&
			 (matrix[i][ii] + length[ii] < length[i] || length[i] == -1))
				length[i] = matrix[i][ii] + length[ii];
	}

	min = 0;
	for (i = 0; i < n ; i++)
		if (length[i] > min)
			min = length[i];

	cout  << min << endl;

	return 0;
}





