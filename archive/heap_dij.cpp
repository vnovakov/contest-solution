//### Program

#pragma option -O2

/*

Problem: 3
Name: Vladimir Novakovski
Email: vnovakov@lan.tjhsst.edu
School: TJHSST
Grade: 10
Age: 14
CityState: Springfield, VA
Country: USA

*/


#include <fstream.h>
#include <alloc.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

typedef long* Larray;
typedef int* Iarray;

const long INF = 2000000000;

int nN[400];
Iarray neighbors[400];
Larray dN[400];
int start[2000];
int end[2000];
long dist[2000];
int temp[400];
int heapIndex[400];

long d[400];
int n = 0;

int heap[401];
int heapSize;

void heapify(int i)
{
	int si;
	int a;

	i++;

	while (1)
	{

		si = i;

	if (2*i <= heapSize 
	&& d[heap[2*i]] < d[heap[i]])
	
		si = 2*i;
	
	if (2*i + 1 <= heapSize 
	&& d[heap[2*i + 1]] < d[heap[i]])

		si = 2*i + 1;

	if (i != si)
	{
		heapIndex[heap[i]] = si;
		heapIndex[heap[si]] = i;
		a = heap[i];
		heap[i] = heap[si];
			heap[si] = a;
			i = si;
		} else break;
	}

}

void heapUp(int i)
{
	int a;

	i++;
	while (1)
	{
		if (i == 1)
			break;

		else if 
		(d[heap[i]] < d[heap[i/2]])
		{
		heapIndex[heap[i]] = i / 2;
		heapIndex[heap[i/2]] = i;
			a = heap[i];
		heap[i] = heap[i/2];
			heap[i/2] = a;
			i /= 2;
		} else
			break;
	}
}

int minHeap()
{
	return heap[1];
}

void deleteHeap(int i)
{
	int a;

	i++;

	heapIndex[heap[i]] = heapSize;
	heap[i] = heap[heapSize];

	heapSize--;
	heapify(i-1);
}

void buildHeap()
{
	int i;

	heapSize = n;

	for (i = 1; i <= heapSize; i++)
	{
		heapIndex[i - 1]  = i;
		heap[i] = i - 1;
	}

	for (i = (heapSize / 2); i >= 1; i--)
		heapify(i - 1);
}

main()
{

	int i, j, k, l, m, p;
	long minLoop = INF;
	long minD = INF;

	infile >> m;

	for (i = 0; i < m; i++)
	{
		infile >> start[i] >>
		  end[i] >> dist[i];
		start[i]--;
		end[i]--;
		if (start[i] + 1 > n)
			n = start[i] + 1;
		if (end[i] + 1 > n)
			n = end[i] + 1;
	}

	for (i = 0; i < n; i++)
		nN[i] = 0;

	for (i = 0; i < m; i++)
		nN[start[i]]++;

	for (i = 0; i < n; i++)
	{
		neighbors[i] =
		(Iarray)malloc(nN[i] * sizeof(int));

		dN[i] =
		(Larray)malloc(nN[i] * sizeof(long));

		temp[i] = 0;
	}

	for (i = 0; i < m; i++)
	{
		j = start[i];
		neighbors[j][temp[j]] = end[i];
		dN[j][temp[j]++] = dist[i];
	}


	for (i = 0; i < n; i++)
	{

		for (j = 0; j < n; j++)
			d[j] = INF;

		for (j = 0; j < nN[i]; j++)
			d[neighbors[i][j]] = dN[i][j];

		heapSize = 0;

		buildHeap();

		while (1)
		{

			if (!heapSize)
				break;

			k = minHeap();

			if (d[k] == INF)
				break;

			minD = d[k];

			deleteHeap(0);

			if (k == i)
				break;

			p = nN[k];

			for (j = 0; j < p; j++)
			{
				l = neighbors[k][j];

				if (d[l] > minD + dN[k][j]) {
					d[l] = minD + dN[k][j];
					heapUp(heapIndex[l] - 1);
				}
			}
		}

		if (d[i] < minLoop)
			minLoop = d[i];

	}

	outfile << minLoop << endl;

	return 0;

}



//### End