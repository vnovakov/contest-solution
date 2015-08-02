/* @JUDGE_ID: 3207EZ 348 C++ "Dynamic Programming" */
#include <iostream.h>

int a[30];
int b[30];

long bestA[30][30];
int sizeS[30][30];
int sizeF[30][30];
int split[30][30];

void printSplit(int start, int finish)
{
	if (start == finish)
	{
		cout << "A" << start + 1;
	} else
	{
		cout << "(";
		printSplit(start,split[start][finish]-1);
		cout << " x ";
		printSplit(split[start][finish],finish);
		cout << ")";
	}
}

long best(int start, int finish)
{
	long pmin, min; int i, ii;
	if (start == finish)
		return 0;
	if (bestA[start][finish] == 0)
	{
		min = -1;
		for (i = start + 1; i <= finish; i++)
		{
			pmin = best(start, i - 1) + best(i,finish) +
				sizeS[start][i-1]*sizeF[i][finish]*sizeS[i][finish];
			if (min == -1 || pmin < min)
			{	min = pmin; ii = i; }
		}
		sizeS[start][finish] = sizeS[start][ii-1];
		sizeF[start][finish] = sizeF[ii][finish];
		split[start][finish] = ii;
		bestA[start][finish] = min;
	}
	return bestA[start][finish];
}



main()
{
	int i, j, n, ca = 1; long dummy;

	while (1)
	{
		cin >> n;

		if (!n)
			break;

		for (i = 0; i < 30; i++)

			for (j = 0; j < 30; j++)
				{ sizeF[i][j] = sizeS[i][j] = bestA[i][j] = 0; }

		for (i = 0; i < n; i++)  {
			cin >> a[i] >> b[i];
			sizeS[i][i] = a[i];
			sizeF[i][i] = b[i];
		}

		dummy = best(0, n-1);  
		cout << "Case " << ca++ << ": ";
		printSplit(0,n-1);
      cout << endl;

	}

	return 0;
}


