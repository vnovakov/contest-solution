/* @JUDGE_ID: 3207EZ 193 C++ */
#include <iostream.h>

enum Color {NONE, BLACK, WHITE};

int graph[100][100];
Color color[100];
Color best[100];
int N, E;
int maxBlackCount, blackCount, count;

void explore()
{
	int flag = 0; int u, v;
	int aux[100];

	if (N - count + blackCount <= maxBlackCount)
		return;

	if (blackCount > maxBlackCount) {
		maxBlackCount = blackCount;
		for (v = 0; v < N; v++)
			best[v] = color[v];
	}

	for (v = 0; v < N; v++)
		if (color[v] == NONE)
		{	flag = 1; u = v; break; }
	if (!flag)
		return;

	count++;
	color[u] = BLACK; blackCount++;
	for (v = 0; v < N; v++)
		if (color[v] == NONE && graph[u][v])
		{	color[v] = WHITE; aux[v] = 1;
			count++; }
		else
			aux[v] = 0;
	explore();

	for (v = 0; v < N; v++)
		if (aux[v] == 1)
		{	color[v] = NONE;
			count--;
		}
	blackCount--;

	color[u] = WHITE;

	explore();

	color[u] = NONE;

	count--;

}


main()
{
	int nG;	cin >> nG;
	int g, u, v, e, black;

	for (g = 0; g < nG; g++)
	{
		 cin >> N >> E;
		 for (u = 0; u < N; u++)
		 {	color[u] = NONE;
			for (v = 0; v < N; v++)
				graph[u][v] = 0;
		 }
		 for (e = 0; e < E; e++)
		 {	cin >> u >> v;
			graph[u-1][v-1] = graph[v-1][u-1] = 1;
		 }

		 maxBlackCount = 0;
		 blackCount = 0; count = 0;

		 explore();

		 cout << maxBlackCount << endl;
		 black = 0;
		 for (u = 0; u < N ; u++)
			if (best[u] == BLACK)
			{  if (!black)
					black = 1;
				else
					cout << " ";
				cout << u + 1 ;
			}

		 cout << endl;
	}

	return 0;
}
