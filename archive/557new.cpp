/* @JUDGE_ID: 3207EZ 557 C++ "Pascal's Triangle" */
#include <iostream.h>
#include <stdio.h>
#include <math.h>

float save[1001];
float p[1000];

main()
{
	int n, nInputs, inp, i;
	float prod = 1;

	cin >> nInputs;

	for (i = 0; i < 500;  )
	{
		save[2*++i] = prod;
      p[i] = prod;
		prod *= 1.0 - 0.5 / i;
	}

	for (inp = 0; inp < nInputs; inp++)
	{
		cin >> n;

//		printf("%.4f\n", 1 - save[n]);
		printf("%.8f\n", 1 - p[n] * sqrt(3*n + 1));
	}

	return 0;
}

