/* @JUDGE_ID: 3207EZ 558 C++ */
#include <iostream.h>

const long INF = 2000000000;

long d[1000];
int v, e;
int start[2000];
int finish[2000];
int weight[2000];

main()
{
	int h, n, i, j, a, b, w;

	cin >> n;

	for (h = 0; h < n; h++)
	{	cin >> v >> e;
		for (i = 0; i < e; i++)
			cin >> start[i] >> finish[i] >> weight[i];
		for (i = 0; i < v; i++)
			d[i] = INF;
		d[0] = 0;
		for (j = 1; j < v; j++)
			for (i = 0; i < e; i++) {
				a = start[i];
				b = finish[i];
				w = weight[i];
					if (d[b] > d[a] + w)
						d[b] = d[a] + w;
			}
		for (i = 0; i < e; i++) {
				a = start[i];
				b = finish[i];
				w = weight[i];
				if (d[b] > d[a] + w)
				{  v = 0;
					cout << "possible" << endl;
					break;
				}
		}
		if (v)
			cout << "not possible" << endl;
	}

	return 0;
}


