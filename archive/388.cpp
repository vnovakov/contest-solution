/* @JUDGE_ID: 3207EZ 388 C++ */
#include <iostream.h>
#include <string.h>
#include <math.h>

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


int matrix[27][27];
int N;
char names[27];
int dist[27];
float value[27];
float cost[27];
int n;

int getName(char c)
{
	int i;
	for (i = 0; i < n; i++)
		if (names[i] == c)
			return i;
	names[n] = c;
	n++;
	return n - 1;
}

main()
{
	int i, v, j, l;
	float val;
	float min;
	char c;
   char S[100];
	Queue Q;

	while (cin >> N)
	{
		n = 1;
		names[0] = '*';
		value[0] = 0;
		dist[0] = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				matrix[i][j] = 0;

		for (i = 0; i < N; i++)
		{
			cin >> c >> val >> S;
			v = getName(c);
			value[v] = val;
			dist[v] = -1;
			for (l = 0; l < strlen(S); l++)
				matrix[v][getName(S[l])] = matrix[getName(S[l])][v] = 1;
		}
		N++;
		Q.enQueue(0);

		while (!Q.isEmpty())
		{
			Q.deQueue(v);

			for (i = 0; i < N; i++)
				if (matrix[v][i] && (dist[i] == -1 || dist[i] > dist[v] + 1))
				{	dist[i] = dist[v] + 1;
					Q.enQueue(i);
				}
		}

		for (i = 1; i < N; i++)
			cost[i] = value[i] * pow(0.95, dist[i]);

		min = 0;

		for (i = 1; i < N; i++)
			if (cost[i] > min || min == -1)
			{	min = cost[i]; j = i; }
			else if (cost[i] == min)
			{
				if (names[i] < names[j])
					j = i;
			}

		cout << "Import from " << names[j] << endl;

	}

	return 0;
}
