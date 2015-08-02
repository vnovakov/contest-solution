#include <fstream.h>

ifstream input("castle.in");
ofstream output("castle.out");

int m, n;
int roomSizes[2500];
int nR;
int castle[50][50];
int rooms[50][50];

enum whichWay {EAST, SOUTH, WEST, NORTH};

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

void discover(int i, int j, int rmNum)
{
	Queue Q;
	int c;
	Q.enQueue(i, j);
	while (!Q.isEmpty())
	{
		Q.deQueue(i, j);
		if (i >= 0 && i < m && j >= 0 && j < n && rooms[i][j] == -1)
		{
		rooms[i][j] = rmNum;
		roomSizes[rmNum]++;
		c = castle[i][j];
		if (!(c % 2)) Q.enQueue(i,j-1);
		if (!((c/2)%2)) Q.enQueue(i-1,j);
		if (!((c/4)%2)) Q.enQueue(i,j+1);
		if (!((c/8)%2)) Q.enQueue(i+1,j);
		 }
	}

}



main()
{
	int i, j, max;
	int max_i = 0, max_j = 0;
	whichWay w;
	input >> n >> m;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		  { 	input >> castle[i][j];
				rooms[i][j] = -1; }

	nR = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (rooms[i][j] == -1)
				discover(i, j, nR++);

	output << nR << endl;

	max = 0;

	for (i = 0; i < nR; i++)
		if (roomSizes[i] > max)
			max = roomSizes[i];

	output << max << endl;

	max = 0;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if ((castle[i][j]/4)%2 && j < n - 1) {
				if ((roomSizes[rooms[i][j]] + roomSizes[rooms[i][j+1]] > max
					|| (roomSizes[rooms[i][j]] + roomSizes[rooms[i][j+1]] == max
						&& (j < max_j || (j == max_j && i > max_i))))
					 &&
					rooms[i][j] != rooms[i][j+1])
				{
					max = roomSizes[rooms[i][j]] + roomSizes[rooms[i][j+1]];
					max_i = i;
					max_j = j;
					w = EAST;
				} }
			else if ((castle[i][j]/2)%2 && i) {
				if ((roomSizes[rooms[i][j]] + roomSizes[rooms[i-1][j]] > max
					|| (roomSizes[rooms[i][j]] + roomSizes[rooms[i-1][j]] == max
						&& (j < max_j || (j == max_j && i > max_i))))
				&&
					rooms[i-1][j] != rooms[i][j])
				{
					max = roomSizes[rooms[i][j]] + roomSizes[rooms[i-1][j]];
					max_i = i;
					max_j = j;
					w = NORTH;
				} }
	output << max << endl;
	output << max_i + 1 << " " << max_j + 1 << " ";
	if (w == EAST)
		output << "E";
	else if (w == NORTH)
		output << "N";

	output << endl;

	return 0;
}
