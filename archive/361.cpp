/* @JUDGE_ID: 3207EZ 361 C++ "2D Convex Hull" */
#include <fstream.h>
#include <math.h>
#include <stdlib.h>

ifstream infile("INPUT.TXT");
ofstream outfile("OUTPUT.TXT");

struct node {
	int data;
	node* next;
	node(int d, node* n);
};

node::node (int d, node* n) : data(d), next(n) { }

class Stack
{
	public:
		Stack();
		void pop();
		int top();
		int nextToTop();
		void push(int n);
		int isEmpty();
	private:
		node* head;
};

Stack::Stack()
{
	head = NULL;
}

void Stack::pop()
{
	head = head -> next;
}

void Stack::push(int n)
{
	head = new node(n, head);
}

int Stack::top()
{
	return head -> data;
}

int Stack::nextToTop()
{
	return head -> next -> data;
}

int Stack::isEmpty()
{
	if (!head)
		return 1;
	return 0;
}


struct Pt {
	int x;
	int y;
};

int c, r, o;
Pt cops[200];
Pt robbers[200];
Pt other[200];
Pt CH[200];
Pt RH[200];
int perm[200];
float angle[200];

float d(int x1, int y1, int x2, int y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	if (dx == 0)   {
		if (dy < 0)
			dy = -dy;
		return dy; }
	return dx*sqrt(1 + (dy*dy)/(dx*dx));
}

int inside(Pt poly[200], int n, int x, int y)
{
	int i, x1, y1, x2, y2, count = 0;
	float yy, dd, a, b1, b2, c;

	for (i = 0; i < n; i++)
	{	if (poly[i].x == x && poly[i].y == y)
			return 1;
		dd = d(poly[i].x,poly[i].y,x,y) +
			d(x,y,poly[(i+1)%n].x,poly[(i+1)%n].y) - d(poly[i].x,poly[i].y,
														  poly[(i+1)%n].x,poly[(i+1)%n].y);
		if (dd*dd < 0.00001)
				return 1;
	}

	for (i = 0; i < n; i++)
	{
		x1 = poly[i].x;
		y1 = poly[i].y;
		x2 = poly[(i + 1) % n].x;
		y2 = poly[(i + 1) % n].y;

		if (((x < x2 && x >= x1) || (x <= x1 && x > x2)))
		{
		  a = (float)x*(y2 - y1);
		  b1 = (float)y1*x2;
		  b2 = (float)y2*x1;
		  c = (float)(x2 - x1);
			yy = (a + b1 - b2)/c;
			if (yy <= y)
				count++;
			if (count > 1)
				return 0;
		}
	}
	if (count == 1)
		return 1;
	else
		return 0;
}

int cmp(void const *a, void const *b)
{
	int aa = *(int *)a;
	int bb = *(int *)b;
	float A = angle[aa-1];
	float B = angle[bb-1];

	if (A - B > 0.001)
		return 1;
	else if ((A - B)*(A - B) <= 0.001)
		return 0;
	return -1;
}

long crossprod(int x1, int y1, int x2, int y2)
{
	return (long)(x1*y2 - y1*x2);
}

int badAngle(Pt a, Pt b, Pt c)
{
	Pt p, q;
	p.x = a.x - b.x;
	p.y = a.y - b.y;
	q.x = c.x - b.x;
	q.y = c.y - b.y;
	if (crossprod(p.x,p.y,q.x,q.y) >= 0)
		return 1;
	return 0;
}

void swap(Pt &a, Pt &b)
{
	Pt c; c.x = a.x; c.y = a.y;
	a.x = b.x; a.y = b.y;
	b.x = c.x; b.y = c.y;
}

void convexHull(Pt points[200], int npoints, Pt hull[200], int &hullsize)
{
	int i, ii, miny = 2000, minx = 2000;
	Stack S;

	for (i = 0; i < npoints; i++)
	{
		if (points[i].y < miny)
		{
			miny = points[i].y;
			minx = points[i].x;
			ii = i;
		} else if (points[i].y == miny && points[i].x < minx)
		{
			minx = points[i].x;
			ii = i;
		}
	}

	swap(points[0], points[ii]);

	for (i = 1; i < npoints; i++)
	{	angle[i - 1] = atan2(points[i].y - points[0].y, points[i].x - points[0].x);
		perm[i - 1] = i;
	}

	qsort(perm, npoints - 1, sizeof(int), cmp);

	S.push(0);
	S.push(perm[0]);
	S.push(perm[1]);

	for (i = 2; i < npoints - 1; i++)
	{
		while (badAngle(points[S.nextToTop()], points[S.top()], points[perm[i]]))
			S.pop();
		S.push(perm[i]);
	}
	hullsize = 0;
	while (!S.isEmpty())
	{
		i = S.top();
		S.pop();
		hull[hullsize].x = points[i].x;
		hull[hullsize++].y = points[i].y;
	}


}

main()
{
	int set = 1;
	int a, b, i, sc, sr;


	while (1)
	{
		cin >> c >> r >> o;

		if (c + r + o == 0)
			break;

		for (i = 0; i < c; i++)
			cin >> cops[i].x >> cops[i].y;
		for (i = 0; i < r; i++)
			cin >> robbers[i].x >> robbers[i].y;
		for (i = 0; i < o; i++)
			cin >> other[i].x >> other[i].y;
		if (c >= 3)
			convexHull(cops, c, CH, sc);
		if (r >= 3)
		convexHull(robbers, r, RH, sr);

		cout << "Data set " << set++ << ":" << endl;
		for (i = 0; i < o; i++)
		{
			cout << "     Citizen at (";
			cout << other[i].x << "," << other[i].y << ") is ";
			if (c >= 3)
				a = inside(CH, sc, other[i].x, other[i].y);
			else
				a = 0;
			if (r >= 3)
				b = inside(RH, sr, other[i].x, other[i].y);
			else
				b = 0;

			if (a)
				cout << "safe";
			else {
				if (b)
					cout << "robbed";
				else
					cout << "neither";
			}

			cout << "." << endl;
		}
		cout << endl;
	}


	return 0;
}