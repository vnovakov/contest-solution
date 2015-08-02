#include <fstream.h>
#include <stdlib.h>

ifstream infile("camelot.in");
ofstream outfile("camelot.out");

int R, C;
int kingX, kingY;
int K;
int Kx[1040], Ky[1040];
int theKnight[1040];
int orderR[40];
int orderC[26];
int total;

int huge knightMove[40][26][40][26];
int visited[40][26];

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


void computeKM (int m, int n)
{
	int u, v, i, a, b, d;

	Queue Q;


	for (a = 0; a < R; a++)
		for (b = 0; b < C; b++)
		{
			knightMove[m][n][a][b] = -1;
			visited[a][b] = 0;
		}

	knightMove[m][n][m][n] = 0;
	Q.enQueue(0, 0);
	visited[m][n] = 1;

	while (!Q.isEmpty())
	{
		Q.deQueue(u, v);
		d = knightMove[m][n][m+u][n+v];

		for (a = u - 2; a <= u + 2; a++)
			for (b = v - 2; b <= v + 2; b++)
				if (a + m >= 0 && b  + n >= 0 && a  + m < R  && b + n < C &&

				(a - u)*(a - u)*(b - v)*(b - v) == 4 &&
					!visited[m+a][n+b])
					{
						visited[m+a][n+b] = 1;
						knightMove[m][n][m+a][n+b] = d + 1;
						Q.enQueue(a, b);
					}
	}
}

int max (int a, int b)
{
	if (a > b)
		return a;
	return b;
}

main()
{
	int i, j, k, l, a, b, ii, jj, s;
	int min, curr, ccurr;
	char c;

	infile >> R >> C;

	infile >> c >> kingX;
	kingX--;
	kingY = c - 'A';

	K = 0;

	for (i = 0; i < R; i++)
		for (j  = 0; j < C; j++)
			computeKM(i, j);

	while (infile >> c >> Kx[K])
	{
		Ky[K] = c - 'A';
		Kx[K++]--;
	}

	min = 10000;

	a = (R-1)/2;
	b = 1;
	s = 1;
	for (i = 0; i < R; i++)
	{
		orderR[i] = a;
		a += s*b;
		b++;
		s *= -1;
	}
	a = (C-1)/2;
	b = 1;
	s = 1;
	for (i = 0; i < C; i++)
	{
		orderC[i] = a;
		a += s*b;
		b++;
      s *= -1;
	}

	for (ii = 0; ii < R ; ii++)
		for (jj = 0; jj < C; jj++)
		{
			i = orderR[ii];
			j = orderC[jj];
			curr = 0;


			for (k = 0; k < K; k++)
			{
				theKnight[k] = knightMove [Kx[k]][Ky[k]][i][j];
				if (theKnight[k] == -1)
            	goto next;
				curr += theKnight[k];
			}
			total = curr;
			curr += max ( abs(kingX - i), abs(kingY - j) );


			if (curr < min)
				min = curr;

			for (k = 0; k < K; k++)
			{
				if (total < min)
				for (a = 0; a < R; a++)
				{
					for (b = 0; b < C; b++)
					{
						curr = total - theKnight[k];
						if (knightMove[Kx[k]][Ky[k]][a][b] == -1)
							goto nextK;
						curr += knightMove [Kx[k]][Ky[k]][a][b];
						curr += max ( abs(kingX - a), abs ( kingY - b) );
						if (knightMove [a][b][i][j] == -1)
							goto nextK;
						curr += knightMove [a][b][i][j];

						if (curr < min)
							min = curr;
						nextK:
                  ;
					}
				}

			}
			next:
         ;
		}

	outfile << min << endl;

	return 0;
}
