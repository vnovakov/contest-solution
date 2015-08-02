#include <fstream.h>

typedef struct node	 node;

struct node {
	int data1;
	int data2;
	node* next;
	node* prev;
	node(int d1, int d2, node* n, node* p);
};

node::node (int d1, int d2, node* n, node* p) :
	data1(d1), data2(d2), next(n), prev(p) { }

typedef class Queue 	Queue;

class Queue
{
	public:
		Queue();
		void enQueue(int x, int y);
		void deQueue();
		void deQueue(int &x, int &y);
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

void Queue::enQueue(int x, int y)
{
	if (front && end)
	{
		front = new node(x, y, front, NULL);
		front -> next -> prev = front;
	}
	else
		 end = front = new node(x, y, NULL, NULL);
}

void Queue::deQueue()
{
	node* temp = end;
	end = end -> prev;
	delete temp;
}

void Queue::deQueue(int &x, int &y)
{
	node* temp = end;
	if (temp) {
	x = temp -> data1;
	y = temp -> data2;
	end = end -> prev;
	delete temp; }
	if (end == NULL)
		front = NULL;
}


ifstream infile("maze1.in");
ofstream outfile("maze1.out");

int M, N;
int huge array[201][201];
int huge visited[201][201];
int huge d[201][201];
int INF = 10000;

main()
{
	int i, j, k, l, max = 0;
	char str[202];
	Queue Q;

	infile >> N >> M;
	N = 2*N + 1;
	M = 2*M + 1;

	infile.getline(str, 202);

	for (i = 0; i < M ; i++)
	{
		infile.getline(str, 202);
		for (j = 0; j < N; j++)
			array[i][j] = (str[j] == ' ') ? 0 : 1;
	}

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
		{	visited[i][j] = 0;
			d[i][j] = INF;
		}
	for (i = 0; i < M; i++)
	{	if (array[i][0] == 0)
		{
			d[i][0] = 0;
			Q.enQueue(i, 0);
			visited[i][0] = 1;
		}
		if (array[i][N-1] == 0)
		{
			d[i][N-1] = 0;
			visited[i][N-1] = 1;
			Q.enQueue(i, N-1);
		}
	}
	for (i = 0; i < N; i++)
	{
		if (array[0][i] == 0)
		{
			d[0][i] = 0;
			visited[0][i] = 1;
			Q.enQueue(0, i);
		}
		if (array[M-1][i] == 0)
		{
			Q.enQueue(M-1, i);
			d[M-1][i] = 0;
			visited[M-1][i] = 1;
		}
	}

	while (!Q.isEmpty())
	{
		Q.deQueue(i, j);

		for (l = i - 1; l <= i + 1; l++)
			for (k = j - 1; k <= j + 1; k++)
				if ((l - i)*(k - j) == 0 &&
					(l - i + k - j != 0) &&
					l >= 0 && k >= 0 && l < M &&
					k < N && !array[l][k] &&
					!visited[l][k])
			{
			Q.enQueue(l, k);
			if (d[l][k] > d[i][j] + 1)
				d[l][k] = d[i][j] + 1;
			visited[l][k] = 1;
			}
	}

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++)
			if (!array[i][j] && d[i][j] > max)
				max = d[i][j];

	outfile << (max + 1)/2 << endl;



	return 0;
}