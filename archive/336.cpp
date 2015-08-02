/* @JUDGE_ID: 3207EZ 336 C++ "BFS" */
#include <iostream.h>

int matrix[30][30];
int names[30];
int n;
int visited[30];
int dist[30];

struct node {
	int data;
	node* next;
	node* prev;
	node(int d, node* n, node* p);
};

node::node (int d, node* n, node* p) : data(d), next(n), prev(p) { }


class Queue
{
	public:
		Queue();
		void enQueue(int n);
		void deQueue(int &n);
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

void Queue::enQueue(int n)
{
	if (front && end)
	{
		front = new node(n, front, NULL);
		front -> next -> prev = front;
	}
	else
		 end = front = new node(n, NULL, NULL);
}

void Queue::deQueue(int &n)
{
	node* temp = end;
	if (temp) {
	n = temp -> data;
	end = end -> prev;
	delete temp; }
	if (end == NULL)
		front = NULL;
}


int Reach(int v, int m)
{
	int i, sum = 0;
	Queue Q;
	for (i = 0; i < n; i++)
	{	visited[i] = -1;
		dist[i] = -1;
	}
	visited[v] = 0;
	dist[v] = 0;
	Q.enQueue(v);

	while (!Q.isEmpty())
	{
		Q.deQueue(v);

		for (i = 0; i < n; i++)
			if (matrix[i][v] && visited[i] == -1)
			{	visited[i] = 0; dist[i] = dist[v] + 1; Q.enQueue(i); }
		visited[v] = 1;
	}

	for (i = 0; i < n; i++)
		if (dist[i] != -1 && dist[i] <= m)
			sum++;

	return sum;

}

int getNum(int a)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (names[i] == a)
			return i;
	}
	names[n] = a;
	n++;
	return n - 1;
}

main()
{
	int i, e, j, c = 1, a, b, aa, bb, g, h;
	while (1)
	{
		n = 0;
		cin >> e;
		if (!e)
			break;
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
				matrix[i][j] = 0;

		for (i = 0; i < e; i++)
		{
			cin >> a >> b;
			aa = getNum(a);
			bb = getNum(b);
			matrix[aa][bb] = matrix[bb][aa] = 1;
		}
		while (1)
		{
			cin >> g >> h;
			if (g + h == 0)
				break;
			for (i = 0; i < n; i++)
				visited[i] = 0;
			cout << "Case " << c << ": " << n - Reach(getNum(g), h) << " nodes "
				  << "not reachable from node " << g << " with TTL = " <<
				  h << "." << endl;
			c++;
		}
	}

	return 0;
}

