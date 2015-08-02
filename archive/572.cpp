#include <iostream.h>

int matrix[100][100];
int visited[100][100];

int a, b;
struct node {
	int data1;
	int data2;
	node* next;
	node* prev;
	node(int d1, int d2, node* n, node* p);
};

node::node (int d1, int d2, node* n, node* p) : data1(d1), data2(d2), next(n), prev(p) { }

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

main()
{