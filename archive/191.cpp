#include <iostream.h>

struct Edge {
	int a;
	int b;
};

int matrix[45][45];
Edge edges[2000];

main()
{
	int x, y, z, start, n = 0;
	while (1)
	{
		cin >> x >> y;
		if (x + y == 0)
		{	 } else
		{
			cin >> z;
			edges[z - 1].a = x - 1;
			edges[z - 1].b = y - 1;
			if (x > n)
				n = x;
			if (y > n)
				n = y;
			if (z == 1)
			{	if (
			matrix[y][z]

