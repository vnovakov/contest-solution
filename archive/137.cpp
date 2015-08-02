/* @JUDGE_ID: 3207EZ 137 C++ */
#include <iostream.h>

float Mx[100], My[100], Nx[100], Ny[100];
float Bx[100], By[100];

main()
{
	int M, N;
	int m, n;
   int B;

	while (1)
	{
		cin >> M;
		if (!M)	break;
		cin >> N;
      B = 0;

		for (m = 0; m < M; m++)
			cin >> Mx[m] >> My[m];
		for (n = 0; n < N; n++)
			cin >> Nx[n] >> Ny[n];

		for (m = 0; m < M; m++)
			for (n = 0; n < N; n++)
         	
