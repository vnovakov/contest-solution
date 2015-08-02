#include <fstream.h>

ifstream infile("concom.in");
ofstream outfile("concom.out");

typedef struct node	 node;

struct node {
	int data1;
	node* next;
	node* prev;
	node(int d1,  node* n, node* p);
};

node::node (int d1, node* n, node* p) :
	data1(d1), next(n), prev(p) { }

typedef class Queue 	Queue;

class Queue
{
	public:
		Queue();
		void enQueue(int x);
		void deQueue();
		void deQueue(int &x);
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

void Queue::enQueue(int x)
{
	if (front && end)
	{
		front = new node(x, front, NULL);
		front -> next -> prev = front;
	}
	else
		 end = front = new node(x, NULL, NULL);
}

void Queue::deQueue()
{
	node* temp = end;
	end = end -> prev;
	delete temp;
}

void Queue::deQueue(int &x)
{
	node* temp = end;
	if (temp) {
	x = temp -> data1;
	end = end -> prev;
	delete temp; }
	if (end == NULL)
		front = NULL;
}

int N;
int matrix[100][100];

Queue Q;

void process(int root)
{
	int control[100];
	int share[100];
	int visited[100];
	int i, j;
	int node;

	for (i = 0; i < N; i++)
	{
		control[i] = 0;
		share[i] = 0;
		visited[i] = 0;
	}
	share[root] = 100;

	Q.enQueue(root);

	while (!Q.isEmpty())
	{

		Q.deQueue(node);
		visited[node] = 1;

			control[node] = 1;

			for (j = 0; j < N; j++)
				if (!visited[j] && matrix[node][j])
				{
					share[j] += matrix[node][j];
					if (share[j] > 50)
						Q.enQueue(j);
				}
	
	}

	for (i = 0; i < N; i++)
		if (control[i] && i != root)
			outfile << root + 1 << " " << i + 1 << endl;
}

main()
{
	int i, j, M;
	N = 0;

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			matrix[i][j] = 0;

	infile >> M;

	while (M--)
	{
		infile >> i >> j;
		i--;
		j--;
		infile >> matrix[i][j];
		if (i + 1 > N)
			N = i + 1;
		if (j + 1 > N)
			N = j + 1;
	}

	for (i = 0; i < N; i++)
		process(i);

	return 0;
}

