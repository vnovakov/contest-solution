#include <iostream.h>
#include <stdio.h>

int nCham, nMass,  masses[10];
int chambers[5]; int cM[5][10]; int cN[5];

float fabs(float a)
{
	if (a < 0)
		a = -a;
	return a;
}

main()
{
	int i, j, k, sum, set = 1, cu; float aver, min, im;

	while (cin >> nCham >> nMass)
	{
		for (i = 0; i < nMass; i++)
			cin >> masses[i];
		for (i = 0; i < nCham; i++)
		{	chambers[i] = 0; cN[i] = 0; }
		sum = 0; cu = 1;
		for (i = 0; i < nMass; i++)
		{
			sum += masses[i];
			aver = (float)sum / cu;
			min = -1;
			for (j = 0; j < nCham; j++)
			{	if (min == -1 || fabs(aver - chambers[j] - masses[i]) < min)
				{   k = j; min = fabs(aver - chambers[j] - masses[i]); }
			}
			cN[k]++; if (cN[k] == 1) cu++;
			chambers[k] += masses[i];
			cM[k][cN[k]-1] = i;
		}
		cout << "Set #" << set++ << endl;
		for (i = 0; i < nCham; i++)
		{
			cout << " " << i << ":";
			for (j = 0; j < cN[i]; j++)
				cout << " " << masses[cM[i][j]];
			cout << endl;
		}
		cout << "IMBALANCE = "; im = 0;
		for (i = 0; i < nCham; i++)
		{
			im += fabs(chambers[i] - aver);
		}

		printf("%.5f\n\n", im);
	}

	return 0;
}



