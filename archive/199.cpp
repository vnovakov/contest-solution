#include <iostream.h>
#include <fstream.h>

ifstream infile("INPUT.TXT");

int n;
int b1[31], b2[31], b3[31], b4[31];
int matrix[31][31];
int f[31][31];
int A[3][3];
int B[3][3];
int coef[31];
int vector[31];

main()
{
	int i, j, k, l, cases, nc, count;

	infile >> cases;

	for (nc = 0; nc < cases; nc++)
	{
		infile >> n;

		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				infile >> A[j][2-i];
		for (i = 0; i < 3; i++)
			for (j = 0; j < 3; j++)
				infile >> B[j][2-i];
		for (i = 0; i <= n; i++)
			infile >> b1[i];
		for (i = 0; i <= n; i++)
			infile >> b2[i];
		for (i = 0; i <= n; i++)
			infile >> b3[i];
		for (i = 0; i <= n; i++)
			infile >> b4[i];
		count = 1;
		for (j = n - 1; j >= 1; j--)
			for (i = 1; i < n; i++)
				matrix[i][j] = count++;
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n; j++)
				infile >> f[j][i];
		count = 0;
		for (j = n - 1; j >= 1; j--)
			for (i = 1; i < n; i++)
			{
				vector[count] = 0;
				for (k = 1; k <= (n-1)*(n-1); k++)
					coef[k] = 0;
				for (k = i - 1; k <= i + 1; k++)
					for (l = j - 1; l <= j + 1; l++)
					{
						if (k == 0)
							vector[count] -= n*n*A[k - i + 1][l - j + 1]*b3[l];
						else if (k == n)
							vector[count] -= n*n*A[k - i + 1][l - j + 1]*b4[l];
						else if (l == 0)
							vector[count] -= n*n*A[k - i + 1][l - j + 1]*b1[k];
						else if (l == n)
							vector[count] -= n*n*A[k - i + 1][l - j + 1]*b2[k];
						else
							coef[matrix[k][l]] = n*n*A[k - i + 1][l - j + 1];
					}
				for (k = i - 1; k <= i + 1; k++)
					for (l = j - 1; l <= j + 1; l++)
						vector[count] += B[k - i + 1][l - j + 1]*f[k][l];

				cout << coef[1];
				for (k = 2; k <= (n-1)*(n-1); k++)
					cout << " " << coef[k];
				cout << endl;
            count++;
			}
		cout << vector[1];
		for (i = 2; i <= (n - 1)*(n - 1) ; i++)
			cout << " " << vector[i];
		cout << endl;
	}

	return 0;
}



