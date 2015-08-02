/* @JUDGE_ID: 3207EZ 334 C++ "Breadth-first search" */
#include <iostream.h>
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


int nameL[100];
char names[100][6];
int matrix[100][100];
int full[100][100];
int aux[100];
int nconc;
int conca[1000];
int concb[1000];
int n;

void explore(int v)
{
	int i; Queue Q;

	for (i = 0; i < n; i++)
		aux[i] = 0;

	Q.enQueue(v);

	while(!Q.isEmpty())
	{
		Q.deQueue(v);

		aux[v] = 1;
		for (i = 0; i < n; i++)
			if (!aux[i] && matrix[v][i])
				Q.enQueue(i);
	}
}

void add(int i, int j)
{
	full[i][j] += 1; full[j][i] += 1;
}

void addr(int i, int j)
{
	conca[nconc] = i;
	concb[nconc] = j;
	nconc++;
}

int insertName(char c[])
{
	int i, j, equal;
	for (i = 0; i < n; i++) {
		equal = 1;
		if (nameL[i] != strlen(c))
			equal = 0;
		else {
			for (j = 0; j < nameL[i]; j++)
				if (names[i][j] != c[j])
				{	equal = 0; break; }
		}
		if (equal)
			return i;
	}
	nameL[n] = strlen(c);
	for (j = 0; j < strlen(c); j++)
		names[n][j] = c[j];
	n++;
	return n - 1;
}

main()
{
	char d[6]; char e[6];
	int i, j, a, b, c, dd, ee, ca = 1;
	while(1)
	{
		n = 0;
		nconc = 0;

		for (i = 0; i < 100; i++)
			for (j = 0; j < 100; j++)
			{ matrix[i][j] = 0; full[i][j] = 0; }

		cin >> a;
		if (!a)
			break;

		for (i = 0; i < a; i++)
		{
			cin >> c;
			cin >> d;
			dd = insertName(d);
			for (j = 1; j < c; j++)
			{
				cin >> e; ee = insertName(e);
				matrix[dd][ee] = 1;
				dd = ee;
			}
		}

		cin >> b;

		for (i = 0; i < b; i++)
		{
			cin >> d >> e;
			dd = insertName(d);
			ee = insertName(e);
			matrix[dd][ee] = 1;
		}

		for (i = 0; i < n; i++)
		{
			explore(i);
			for (j = 0; j < n; j++)
				if (aux[j] == 0)
					add(i,j);
		}

		for (i = 0; i < n; i++)
			for (j = i + 1; j < n; j++)
					if (full[i][j] == 2)
						addr(i,j);


		cout << "Case " << ca << ", ";
      ca++;
		if (nconc)
		{
			cout << nconc << " concurrent events:" << endl;
			cout << "(" << names[conca[0]] << "," << names[concb[0]] << ")";
			if (nconc > 1)
				cout << " (" << names[conca[1]] << "," << names[concb[1]] << ")";
			cout << endl;
		}
		else
			cout << "no concurrent events." << endl;
	}

	return 0;
}
