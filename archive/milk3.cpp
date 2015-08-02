#include <fstream.h>

ifstream infile("milk3.in");
ofstream outfile("milk3.out");


int visited[21][21][21];
int capA;
int capB;
int capC;

void explore(int a, int b, int c)
{


	if (a < 0 || a > capA)
		return;
	if (b < 0 || b > capB)
		return;
	if (c < 0 || c > capC)
		return;
	if (a + b + c != capC)
		return;
	if (visited[a][b][c])
		return;
	visited[a][b][c] = 1;


	if (a + b <= capA) explore(a + b, 0, c);
		else explore(capA, a + b - capA, c);
	if (a + b <= capB) explore(0, a + b, c);
		else explore(a + b - capB, capB, c);
	if (a + c <= capC) 	explore(0, b, a + c);
		else explore(a + c - capC, b, capA );
	if (a + c <= capA) explore(a + c, b, 0);
		else explore(capA, b, a + c - capA);
	if (b + c <= capB)	explore(a, b + c, 0);
		else explore(a, capB, b + c - capB);
	if (b + c <= capC) explore(a, 0, b + c);
		else explore(a, b + c - capC, capC);


}

main()
{
	int i, j, k, cPos[21];
	infile >> capA >> capB >> capC;

	for (i = 0; i  < 21; i++)
		for (j = 0; j < 21; j++)
			for (k = 0; k < 21; k++)
			  visited[i][j][k] = 0;

	explore(0, 0, capC);
	for (i = 0; i <= capC; i++)
		cPos[i] = 0;

		for (j = 0; j < 21; j++)
			for (k = 0; k < 21; k++)
				if (visited[0][j][k])
					cPos[k] = 1;

	int first = 0;
	for (i = 0; i <= capC; i++)
		if (cPos[i])

		{
			if (!first)
				outfile << i;
			else

			outfile << ' ' << i;
			first = 1;
		}

	outfile << endl;

	return 0;
}
