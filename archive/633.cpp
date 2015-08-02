#include <fstream.h>

typedef struct node	 node;

struct node {
	int data1;
	int data2;
	int data3;
	node* next;
	node* prev;
	node(int d1, int d2, int d3, node* n, node* p);
};

node::node (int d1, int d2, int d3, node* n, node* p) :
	data1(d1), data2(d2), data3(d3), next(n), prev(p) { }

typedef class Queue 	Queue;

class Queue
{
	public:
		Queue();
		void enQueue(int x, int y, int z);
		void deQueue();
		void deQueue(int &x, int &y, int &z);
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

void Queue::enQueue(int x, int y, int z)
{
	if (front && end)
	{
		front = new node(x, y, z, front, NULL);
		front -> next -> prev = front;
	}
	else
		 end = front = new node(x, y, z, NULL, NULL);
}

void Queue::deQueue()
{
	node* temp = end;
	end = end -> prev;
	delete temp;
}

void Queue::deQueue(int &x, int &y, int &z)
{
	node* temp = end;
	if (temp) {
	x = temp -> data1;
	y = temp -> data2;
	z = temp -> data3;
	end = end -> prev;
	delete temp; }
	if (end == NULL)
		front = NULL;
}

ifstream infile("633.in");
ofstream outfile("633.out");

int ob[40][40];
int N;
int visited[40][40][3];
int best[40][40][3];

int good(int a, int b)
{
	return (a >= 0 && b >= 0 && a  < 2*N && b < 2*N &&
		!ob[a][b]);
}

void BFS(int a, int b)
{
	int i, j, u, v, w, k, d;
	Queue Q;

	for (i = 0; i < 2*N; i++)
		for (j = 0; j < 2*N; j++)
			for (k = 0; k < 3; k++)
			{
				visited[i][j][k] = 0;
				best[i][j][k] = -1;
			}

	visited[a][b][0] = 1;
	visited[a][b][1] = 1;
	visited[a][b][2] = 1;
	best[a][b][0] = 0;
	best[a][b][1] = 0;
	best[a][b][2] = 0;

	Q.enQueue(a, b, 0);
	Q.enQueue(a, b, 1);
	Q.enQueue(a, b, 2);

	while (!Q.isEmpty())
	{

		Q.deQueue(u, v, w);
		d = best[u][v][w];

		if (ob[u][v])
      	cout << "h";

		if (w != 0)
		{
			if (good(u-2,v-1) && !visited[u-2][v-1][0])
			{
				visited[u-2][v-1][0] = 1;
				best[u-2][v-1][0] = d + 1;
				Q.enQueue(u-2,v-1,0);
			}
			if (good(u-1,v-2) && !visited[u-1][v-2][0])
			{
				visited[u-1][v-2][0] = 1;
				best[u-1][v-2][0] = d + 1;
				Q.enQueue(u-1,v-2,0);
			}
			if (good(u+2,v-1) && !visited[u+2][v-1][0])
			{
				visited[u+2][v-1][0] = 1;
				best[u+2][v-1][0] = d + 1;
				Q.enQueue(u+2,v-1,0);
			}
			if (good(u-2,v+1) && !visited[u-2][v+1][0])
			{
				visited[u-2][v+1][0] = 1;
				best[u-2][v+1][0] = d + 1;
				Q.enQueue(u-2,v+1,0);
			}
			if (good(u+2,v+1) && !visited[u+2][v+1][0])
			{
				visited[u+2][v+1][0] = 1;
				best[u+2][v+1][0] = d + 1;
				Q.enQueue(u+2,v+1,0);
			}
			if (good(u+1,v-2) && !visited[u+1][v-2][0])
			{
				visited[u+1][v-2][0] = 1;
				best[u+1][v-2][0] = d + 1;
				Q.enQueue(u+1,v-2,0);
			}
			if (good(u+1,v+2) && !visited[u+1][v+2][0])
			{
				visited[u+1][v+2][0] = 1;
				best[u+1][v+2][0] = d + 1;
				Q.enQueue(u+1,v+2,0);

			}
			if (good(u-1,v+2) && !visited[u-1][v+2][0])
			{
				visited[u-1][v+2][0] = 1;
				best[u-1][v+2][0] = d + 1;
				Q.enQueue(u-1,v+2,0);
			}
		}
		if (w != 1)
		{
			if (good(u-2,v-2) && !visited[u-2][v-2][1])
			{
				visited[u-2][v-2][1] = 1;
				best[u-2][v-2][1] = d + 1;
				Q.enQueue(u-2,v-2,1);

			}
			if (good(u+2,v-2) && !visited[u+2][v-2][1])
			{
				visited[u+2][v-2][1] = 1;
				best[u+2][v-2][1] = d + 1;
				Q.enQueue(u+2,v-2,1);
			}
			if (good(u-2,v+2) && !visited[u-2][v+2][1])
			{
				visited[u-2][v+2][1] = 1;
				best[u-2][v+2][1] = d + 1;
				Q.enQueue(u-2,v+2,1);
			}
			if (good(u+2,v+2) && !visited[u+2][v+2][1])
			{
				visited[u+2][v+2][1] = 1;
				best[u+2][v+2][1] = d + 1;
				Q.enQueue(u+2,v+2,1);
			}
		}
		if (w != 2)
		{
			if (good(2*N - 1 - u,v) && !visited[2*N - 1 - u][v][2])
			{
				visited[2*N - 1 - u][v][2] = 1;
				best[2*N - 1 - u][v][2] = d + 1;
				Q.enQueue(2*N - 1 - u,v,2);
			}
			if (good(u,2*N - 1 - v) && !visited[u][2*N - 1 - v][2])
			{
				visited[u][2*N - 1 - v][2] = 1;
				best[u][2*N - 1 - v][2] = d + 1;
				Q.enQueue(u,2*N - 1 - v,2);
			}
		}
	}
}

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

main()
{
	int a, b, c, d, theBest;
	int x, y, i, j;

	while (1)
	{
		infile >> N;
		if (!N)
      	break;
		infile >> a >> b;
		infile >> c >> d;
		a--;
		b--;
		c--;
		d--;

		for (i = 0; i < 2*N; i++)
			for (j = 0; j < 2*N; j++)
         	ob[i][j] = 0;

		while (1)
		{
			infile >> x >> y;
			if (!x && !y)
				break;
			ob[x-1][y-1] = 1;
		}

		BFS(a, b);

		if (!visited[c][d][0] && !visited[c][d][1] && !visited[c][d][2])
			outfile << "Solution doesn't exist" << endl;
		else
		{
			theBest = 10000;
			if (visited[c][d][0])
				theBest = min(theBest, best[c][d][0]);
			if (visited[c][d][1])
				theBest = min(theBest, best[c][d][1]);
			if (visited[c][d][2])
				theBest = min(theBest, best[c][d][2]);
			outfile << "Result: " << theBest << endl;

		}
	}

	return 0;
}


