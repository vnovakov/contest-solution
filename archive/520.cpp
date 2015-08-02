#include <iostream.h>
#include <math.h>
#include <string.h>

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


int graph[100][100];

void init()
{
	int i, j;
	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
			graph[i][j] = 0;
}

main()
{

	char s[7]; int visited[100];
	int n = 0, i, j, ok, N;
	Queue Q;

	while (cin.getline(s,10))
	{
		if (strlen(s) == 0)
		{
			N = 0;
			for (i = 0; i < n; i++)
				visited[i] = -1;
			visited[0] = 0;
			while (1)
			{
				ok = 0;
				for (i = 0; i < n; i++)
					if (visited[i] != 1)
					{	j = i; ok = 1; break; }
				if (!ok)
					break;
				Q.enQueue(j);
				N++;
				while (!Q.isEmpty())
				{
					Q.deQueue(j);
					for (i = 0; i < n; i++)
					{
						if (graph[i][j] && visited[i] == -1)
						{	visited[i] = 0; Q.enQueue(i); }
					}
					visited[j] = 1;
				}
			}
			n = 0;
         cout << pow(2, N - 1) - 1 << endl;
		}
		else
		{
			for (i = 1; i <= s[0] - '0'; i++)
			{	graph[n - i][n] = 1; graph[n][n - i] = 1; }
			n++;
		}
	}

	return 0;
}
