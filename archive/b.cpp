#include <iostream.h>
#include <string.h>

int grid[10][10];
int incX[10][10];
int incY[10][10];
int decX[10][10];
int decY[10][10];
int best[10][10];

int M, N;

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


main()
{
	int nCase;
	int sX, sY, fX, fY;
	int a, b, i, j;
	char S[105];
	Queue Q;

	cin >> nCase;

	while (nCase--)
	{

		cin >> M >> N;
		cin >> sX >> sY >> fX >> fY;
		cin.getline(S, 100);
	  cin.getline(S, 100);

		for (i = 1; i <= M; i++)
			for (j = 1; j <= N; j++)
			{
				incX[i][j] = 1;
				incY[i][j] = 1;
				decX[i][j] = 1;
				decY[i][j] = 1;
            best[i][j] = 100;
			}

		for (i = 1; i <= N; i++)
		{
			decX[1][i] = 0;
			incX[M-1][i] = 0;
		}
		for (i = 1; i <= M; i++)
		{
			decY[i][1] = 0;
			incY[i][M-1] = 0;
		}


		while (1)
		{
	  cin.getline(S, 100);
			if (S[0] == 'h')
				break;
			a = 0;
			b = 0;
			for (i = 0; i < strlen(S); i++)
			{
				if (S[i] == ' ')
					break;
				a = 10*a + S[i] - '0';
			}

			for (i++; i < strlen(S); i++)
				b = 10*b + S[i] - '0';
			incX[a][b] = 0;
			decX[a+1][b] = 0;
		}
		while (1)
		{
	  cin.getline(S, 100);
			if (!strlen(S))
				break;
			a = 0;
			b = 0;
			for (i = 0; i < strlen(S); i++)
			{
				if (S[i] == ' ')
					break;
				a = 10*a + S[i] - '0';
			}

			for (i++; i < strlen(S); i++)
				b = 10*b + S[i] - '0';
			incY[a][b] = 0;
			decY[a][b+1] = 0;

		}

		Q.enQueue(sX, sY);
		best[sX][sY] = 0;

		while (!Q.isEmpty())
		{
			Q.deQueue(a, b);
			if (decX[a][b] && best[a-1][b] > best[a][b] + 1)
			{	best[a-1][b] = best[a][b] + 1;
				Q.enQueue(a-1,b);
			}
			if (incX[a][b] && best[a+1][b] > best[a][b] + 1)
			{	best[a+1][b] = best[a][b] + 1;
				Q.enQueue(a+1,b);
			}
			if (decY[a][b] && best[a][b-1] > best[a][b] + 1)
			{	best[a][b-1] = best[a][b] + 1;
				Q.enQueue(a,b-1);
			}
			if (incY[a][b] && best[a][b+1] > best[a][b] + 1)
			{	best[a][b+1] = best[a][b] + 1;
				Q.enQueue(a,b+1);
			}
		}
		if (best[fX][fY] == 100)
			cout <<  "No solution" << endl;
		else
			cout << best[fX][fY] << endl;
		if (nCase)
      	cout << endl;
	}
	return 0;
}