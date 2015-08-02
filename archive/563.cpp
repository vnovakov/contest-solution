/* @JUDGE_ID: 3207EZ 563 C++ */
#include <iostream.h>

struct node {
	int data1;
	int data2;
	node* next;
	node* prev;
	node(int d1, int d2, node* n, node* p);
};

node::node (int d1, int d2, node* n, node* p) : data1(d1), data2(d2), next(n), prev(p) { }

const NONE = -1;

class Queue
{
	public:
		Queue();
		void enQueue(int m, int n);
		void deQueue(int &m, int &n);
		int isEmpty();
	private:
		node* front;
		node* end;
};

Queue::Queue()
{
	front = NULL;
	end = NULL;
}

int Queue::isEmpty()
{
	return front ? 0 : 1;
}

void Queue::enQueue(int m, int n)
{
	if (front && end)
	{
		front = new node(m, n, front, NULL);
		front -> next -> prev = front;
	}
	else
		 end = front = new node(m, n, NULL, NULL);
}

void Queue::deQueue(int &m, int &n)
{
	node* temp = end;
	if (temp) {
	m = temp -> data1;
	n = temp -> data2;
	end = end -> prev;
	delete temp; }
	if (end == NULL)
		front = NULL;
}

int grid[52][52];
int parentX[52][52];
int parentY[52][52];
int visited[52][52];
int m, n;
int nBanks;
int banksX[5000];
int banksY[5000];

main()
{
	int city, nCity, b, x, y, u, v, ok;
	Queue Q;

	cin >> nCity;

	for (city = 0; city < nCity; city++)
	{
		cin >> m >> n >> nBanks;

		for (x = 0; x <= m + 1; x++)
			for (y = 0; y <= n + 1; y++)
				grid[x][y] = 1;

		for (b = 0; b < nBanks; b++)
		{
			cin >> x >> y;
			banksX[b] = x; banksY[b] = y;
			grid[x][y] = 0;
		}

		for (b = 0; b < nBanks; b++)
		{
			x = banksX[b];
			y = banksY[b];

			parentX[x][y] = NONE;
			parentY[x][y] = NONE;

			ok = 0;

			for (u = 0; u <= m + 1; u++)
				for (v = 0; v <= n + 1; v++)
					visited[u][v] = 0;

			Q.enQueue(x, y); visited[x][y] = 1;

			while (!Q.isEmpty())
			{
				Q.deQueue(x, y);
				if (x == 0 || y == 0 || x == m + 1 || y == n + 1)
				{
					while (parentX[x][y] != NONE)
					{
						u = parentX[x][y];
						v = parentY[x][y];
						x = u; y = v;
						grid[u][v] = 0;
					}
					while (!Q.isEmpty())
               	Q.deQueue(x, y);
					ok = 1;
					break;
				}

				for (u = x - 1; u <= x + 1; u++)
					for (v = y - 1; v <= y + 1; v++)
						if (!(u == x && v == y) && !((u - x)*(v - y)) && grid[u][v]
										&&	!visited[u][v])
						{	visited[u][v] = 1;
							parentX[u][v] = x;
                     parentY[u][v] = y;
							Q.enQueue(u, v); }
			}

			if (!ok)
				break;
	  }
	  if (b != nBanks)
			cout << "not ";
	  cout << "possible" << endl;
	}

	return 0;
}

