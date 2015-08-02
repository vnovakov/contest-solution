#include <iostream.h>

int path[33][33];
int where[33][33];
int bitmap[32][32];

void print()
{
	int i, j, whichway = 0;

	for (i = 0; i < 31; i++)
		for (j = 0; j < 31; j++)
		{
			if (path[i+1][j+1] && path[i][j+1] &&
				(where[i][j+1] == 1 || where[i+1][j+1] == 2) )
			{
				if (whichway == 0)
					bitmap[i][j] = 1;
				else
					bitmap[i][j+1] = 1;
				whichway = 1 - whichway;
			}
		}
	for (j = 0; j < 31; j++)
		for (i = 0; i < 31; i++)
		{
			if (path[i+1][j+1] && path[i+1][j] &&
				(where[i+1][j] == 3 || where[i+1][j+1] == 4))
			{
				if (whichway == 0)
					bitmap[i+1][j] = 1;
				else
					bitmap[i+1][j] = 1;
				whichway = 1 - whichway;
			}
		}

	for (j = 31; j >= 0; j--)
	{
		for (i = 0; i < 31; i++)
		{
			if (bitmap[i][j])
				cout << "X";
			else
				cout << ".";
		}
		cout << endl;
	}
}

main()
{
	int n, i, j, h, a, b, bn = 1;
	char c;

	cin >> n;
	for (h = 0; h < n; h++)
	{
		for (i = 0; i < 33; i++)
			for (j = 0; j < 33; j++)
			{	path[i][j] = 0;
				where[i][j] = 0;
				if (i < 32 && j < 32)
					bitmap[i][j] = 0;
			}

		cin >> a >> b;
		path[a][b] = 1;
		while (cin >> c) {

			if (c == '.')
			{
				cout << "Bitmap #" << bn++ << endl;
				print();
				goto next;
			}
			else {
				if (c == 'E') {
					where[a][b] = 1;
					a++; }
				else if (c == 'W') {
					where[a][b] = 2;
					a--; }
				else if (c == 'N') {
					where[a][b] = 3;
					b++;  }
				else if (c == 'S') {
					where[a][b] = 4;
					b--; }
				path[a][b] = 1;
			}
		}

		next:
      ;
	}

	return 0;
}


