#include <iostream.h>
#include <alloc.h>

int *graph; int n;

int k(int i, int j)
{
	return n*i + j;
}

main()
{
	int m, i, j, v, a, b, c, min, ok; double max;
	int visited[500]; long dist[500];
	int mi, ma, mb, sys = 1;

	while (1)
	{
		cin >> n >> m;
		ma = 0;
		mb = 0;

		if (m + n == 0)
			break;

		graph = (int *)malloc(n*n*sizeof(int));
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				graph[k(i,j)] = 0;

		for (i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			graph[k(a-1,b-1)] = graph[k(b-1,a-1)] = c;
		}

		for (i = 0; i < n; i++)
		{	visited[i] = 0; dist[i] = -1; }

		dist[0] = 0;

		while(1)
		{
			min = -1; ok = 0; max = 0;

			for (i = 0; i < n; i++)
				if (visited[i] == 0)
					ok = 1;

			if (!ok)
				break;

			for (i = 0; i < n; i++)
				if (visited[i] == 0)
				{
					if (dist[i] < min || min == -1) {
						min = dist[i]; v = i; }
				}

			for (i = 0; i < n; i++)
			{
				if (!visited[i] && graph[k(i,v)] && dist[i] == -1 ||
					dist[i] > dist[v] + graph[k(i,v)])
				{
					graph[k(i,v)] = graph[k(v,i)] = 0;
					dist[i] = dist[v] + graph[k(i,v)];
					if (dist[i] > max)
					{	max = dist[i]; mi = i; }
				}
			}

			visited[v] = 1;
		}

		cout << "System #" << sys++ << endl;

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (graph[k(i,j)] > max)
				 {  ma = i + 1; mb = j + 1; max = graph[k(i,j)]; }
		if (ma + mb == 0)

		cout << "The last domino falls after " << max << " seconds, at"
			  << " key domino " << mi + 1 << endl << endl;

		else

		cout << "That last domino falls after " << max << " seconds," <<
				 " between key dominoes " << ma << " and " << mb << endl << endl;

	}

	return 0;
}

