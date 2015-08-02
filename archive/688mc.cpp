#include <iostream.h>
#include <stdlib.h>

main()
{
	int n;
	long k, pt; int i, cn = 1;
	float x[100], y[100], r[100];
	float S; int l;

	float X, Y, minX, minY, maxX, maxY;

	while (1)
	{
		cin >> n;
		S = 0;  l = 0;
		if (!n)
			break;

		minX = 400; minY = 400; maxX = -200; maxY = -200;
			for (i = 0; i < n; i++)
			{
				cin >> x[i] >> y[i] >> r[i];
				if (x[i] - r[i] < minX)
					minX = x[i] - r[i];
				if (x[i] + r[i] > maxX)
					maxX = x[i] + r[i];
				if (y[i] - r[i] < minY)
					minY = y[i] - r[i];
					if (y[i] + r[i] > maxY)
					maxY = y[i] + r[i];
			}
			pt = 0;

		for (l = 0; l < 100; l++)
		{
      	pt = 0;
			for (k = 0; k < 10000; k++)
			{
				X = minX + (maxX - minX) * (float)(rand() % 1000) / 1000;
				Y = minY + (maxY - minY) * (float)(rand() % 1000) / 1000;

				for (i = 0; i < n; i++)
						if ((X - x[i]) < r[i] && (x[i] - X) < r[i] &&
						 (Y - y[i]) < r[i] && (y[i] - Y) < r[i])
					{
						pt++;
						break;
					}
			}
			S += (maxX - minX)*(maxY - minY) * (float)pt / k;
		}
		cout << cn++ << " " << S / l << endl;

	}

	return 0;
}

