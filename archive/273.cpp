#include <iostream.h>

struct LineSeg {
	int x1;
	int y1;
	int x2;
	int y2;
};

LineSeg lines[12];
int matrix[12][12];
int N;

int side(LineSeg A, int x, int y)
{
	long Ax = A.x2 - A.x1;
	long Ay = A.y2 - A.y1;
	long Bx = x - A.x1;
	long By = y - A.y1;

	long crossZ = Ax*By - Ay*Bx;

	if (crossZ > 0)
		return 1;
	else if (crossZ == 0)
		return 0;
	return -1;
}

int sameSide(LineSeg A, LineSeg B)
{
	int s1 = side(A, B.x1, B.y1);
	int s2 = side(A, B.x2, B.y2);

	return (s1 == s2 && s1 && s2);
}


int intersect(LineSeg A, LineSeg B)
{
	return (!sameSide(A, B) && !sameSide(B, A));
}

main()
{
	int n, a, b, i, j, k;
	cin >> N;

	for (n = 0; n < N; n++)
		cin >> lines[n].x1
			 >> lines[n].y1
			 >> lines[n].x2
			 >> lines[n].y2;

	for (i = 0; i < N; i++)
		for (j = i; j < N; j++)
		{
			if (i == j)
				matrix[i][i] = 1;
			else {
				matrix[i][j] = intersect(lines[i], lines[j]);
				matrix[j][i] = matrix[i][j];
			}
		}
	for (k = 0; k < N; k++)
		for (i = 0; i < N; i++)
			for (j = i; j < N; j++)
			{
				matrix[i][j] = matrix[i][k] || matrix[k][j];
				matrix[j][i] = matrix[i][j];
			}
	while (1)
	{
		cin >> a >> b;

		if (!a && !b)
			break;

		if (!matrix[a-1][b-1])
			cout << "NOT ";
		cout << "CONNECTED" << endl;
	}

	return 0;
}
