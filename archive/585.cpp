/* @JUDGE_ID: 3207EZ 585 C++ */

#include <iostream.h>

char triangle[100][200];
char odd[100][100];
char even[100][100];
int n;

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

main()
{
	int tri = 1;
	int i, j, biggest;
	char s[210];

	while (1)
	{
		cin >> n;
		if (!n)
			break;
		cin.getline(s, 210);
		for (i = 0; i < n; i++)
		{
			cin.getline(s, 210);
			for (j = i; j < 2*n - i - 1; j++)
				triangle[i][j-i] = (s[j] == '-') ? 1 : 0;
		}
		biggest = 0;
		for (j = 0; j < n; j++)
		{
			even[0][j] = triangle[0][2*j];
			if (even[0][j] > biggest)
				biggest = even[0][j];
		}
		for (i = 1; i < n; i++)
			for (j = 0; j <= n - i - 1; j++)
			{
				if (triangle[i][2*j] && even[i-1][j] && triangle[i-1][2*j+1] && even[i-1][j+1])
					even[i][j] = min(even[i-1][j],even[i-1][j+1]) + 1;
				else
					even[i][j] = triangle[i][2*j];
				if (even[i][j] > biggest)
					biggest = even[i][j];
			}

		for (i = 0; i < n - 1; i++)
		{
			odd[i][0] = triangle[n - 2 - i][1];
			odd[i][i] = triangle[n - 2 - i][2*i + 1];
			if (odd[i][0] > biggest)
				biggest = odd[i][0];
			if (odd[i][i] > biggest)
				biggest = odd[i][2*i - 1];
			for (j = 1; j < i; j++)   {
				if (triangle[n - 2 - i][2*j + 1] && odd[i-1][j-1] && odd[i-1][j] &&
					triangle[n - 3 - i][2*j])
					odd[i][j] = min(odd[i-1][j-1],odd[i-1][j]) + 1;
				else
					odd[i][j] = 1;
				if (odd[i][j] > biggest)
					biggest = odd[i][j];
			}
		}

		cout << "Triangle #" << tri++ << endl;
		cout << "The largest triangle area is " << biggest*biggest << "." << endl << endl;
	}

	return 0;
}



