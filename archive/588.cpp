#include <iostream.h>

float TOL = 0.001;
float x[100], y[100];
int N;

int side (float x, float y, float x1, float y1, float x2, float y2)
{
	float k = (x1 - x)*(y1 - y2) - (y1 - y)*(x1 - x2);
	if (k > TOL)
		return 1;
	else if (eq(k, 0))
		return 0;
	return -1;
}

int intersect(float L1x1, float L1y1, float L1x2, float L1y2,
				  float L2x1, float L2y1, float L2x2, float L2y2)
{
	if (side(L1x1,L1y1,L2x1,L2y1,L2x2,L2y2) == side(L1x2,L1y2,L2x1,L2y1,L2x2,L2y2))

		return 0;
  if		(side(L2x1,L2y1,L1x1,L1y1,L1x2,L1y2) == side(L2x2,L2y2,L1x1,L1y1,L1x2,L1y2))

		return 0;
	return 1;
}

main()
{
   int n;
	while (1)
	{
		cin >> N;

		if (!N)
			break;

		for (n = 0; n < N; n++)
			cin >> x[n] >> y[n];

		
	}