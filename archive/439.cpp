/* @JUDGE_ID: 3207EZ 439 C++ */
#include <iostream.h>
#include <stdlib.h>
//#include <fstream.h>

//ofstream outfile("KNIGHT.OUT");

int matrix[6][6] = { {0,3,2,3,2,3},
							{3,2,1,2,3,4},
							{2,1,4,3,2,3},
							{3,2,3,2,3,4},
							{2,3,2,3,4,3},
							{3,4,3,4,3,4} };

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
		void enQueue(int m, int n);
		void deQueue(int &m, int &n);
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

void Queue::enQueue(int m, int n)
{
	if (front && end)
	{
		front = new node(m, n, front, NULL);
		front -> next -> prev = front;
	}
	else
		 end = front = new node(m, n, NULL, NULL);
}

void Queue::deQueue(int &m, int &n)
{
	node* temp = end;
	if (temp) {
	m = temp -> data1;
	n = temp -> data2;
	end = end -> prev;
	delete temp; }
	if (end == NULL)
		front = NULL;
}


int board[8][8]; int visited[8][8];

int ok(int a, int b)
{
	if (a >= 0 && b >= 0 && a <= 7 && b <= 7 && visited[a][b] == 0)
		return 1;
	return 0;
}

int dist(int a1, int a2, int b1, int b2)
{
	int i, j, k, b, x, y; Queue Q;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		{	board[i][j] = -1; visited[i][j] = 0; }
	board[a1][a2] = 0;
	visited[a1][a2] = 1;
	Q.enQueue(a1, a2);

	while (!Q.isEmpty())
	{
		Q.deQueue(a1, a2); b = board[a1][a2];
		for (i = -1; i <= 1; i += 2)
			for (j = -1; j <= 1; j += 2)
				for (k = 1; k <= 2; k++)
				{	x = a1 + i*k; y = a2 + j*(3 - k);
					if (ok(x,y))
					{
						Q.enQueue(x,y);
						board[x][y] = b + 1;
						if (x == b1 && y == b2)
						{	 return b + 1; }
						visited[x][y] = 1;
					}
				}

		visited[a1][a2] = 2;
	}

	return board[b1][b2];
}

main()
{
	char s[8]; int a1, a2, b1, b2, p, q;
//	int i, j, k, l, d, min, max;
/*
	while (cin.getline(s, 10))
	{
		a1 = s[0] - 'a';
		a2 = s[1] - '1';
		b1 = s[3] - 'a';
		b2 = s[4] - '1';
		cout << "To get from " << s[0] << s[1] << " to " << s[3] << s[4] << " takes ";
*/
		for (a1 = 0; a1 < 8; a1++)
			for (a2 = 0; a2 < 8; a2++)
				for (b1 = 0; b1 < 8; b1++)
					for (b2 = 0; b2 < 8; b2++) {
			if (a1 >= 1 && a2 >= 1 && a1 <= 6 && a2 <= 6 &&
			 b1 >= 1 && b2 >= 1 && b1 <= 6 && b2 <= 6)
			{	 p =  matrix[abs(b1-a1)][abs(b2-a2)]; 		q =  dist(a1,a2,b1,b2);
				if (p != q)
					cout << "Bad!" << endl;
			}
//		cout 			 << " knight moves." << endl;
	 }

/*
	outfile << "int matrix[6][6] = {";
	for (i = 0; i < 6; i++)
	{	outfile << " {";
		for (j = 0; j < 6; j++)
		{
			min = 10;
			max = 0;
			for (k = 1; k + i < 7; k++)
				for (l = 1; l + j < 7; l++) {
					d = dist(k,l,k+i,l+j);
					if (d > max)
						max = d;
					if (d < min)
						min = d;
				}
			if (min == max)
				outfile << max;
			else
				outfile << "-1";
			if (j < 5)
				outfile << ",";
			else
				outfile << "}";
		}
		if (i < 5)
			outfile << ", " << endl;
		else
			outfile << "};";
	} */
	return 0;
}
