### Program


/*

Problem: 4
Name: Vladimir Novakovski
Email: vnovakov@lan.tjhsst.edu
School: Thomas Jefferson High School for Science and Technology
Grade: 9
Age: 13
CityState: Springfield, VA
Country: USA

*/

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define min(a, b)  (((a) < (b)) ? (a) : (b))
#define max(a, b)  (((a) > (b)) ? (a) : (b))

struct cow {
	int n;
	int absPos;
};

char* TARGET = "Begin the Escape execution at the Break of Dawn";
 ofstream outfile("OUTPUT.TXT");

time_t time0, time1;

const LENGTH = 47;

struct util {
	char c;
	int howMany;
	int positions[LENGTH];
};

	char* U = "Begin the Escape execution at the Break of Dawn";
	char T[100];
	util C[LENGTH];
	int V[LENGTH][LENGTH];

int convert(int a, int b, int c, int index)
{
	if (index < a || index >= c)
		return index;
	else if (index >= a && index < b)
		return index + c - b;
	else
		return index - (b - a);
}

cow convertCow(cow a, cow b, cow c, cow x)
{
	cow r;

	if (x.absPos < a.absPos)
	{ r.n = x.n; r.absPos = x.absPos;	return r; }
	else if (x.absPos > c.absPos)
	{ r.n = x.n; r.absPos = x.absPos - 3;	return r; }
	else if (x.absPos > a.absPos && x.absPos < b.absPos)
	{  r.n = x.n + (c.n - b.n);
		r.absPos = x.absPos + (c.absPos - b.absPos) - 2;
		return r;}
	else
	{
		r.n = x.n - (b.n - a.n);
		r.absPos = x.absPos - (b.absPos - a.absPos) - 1;
		return r;
	}
}



int canBeDone(int nswaps, cow a[], cow b[], cow c[], int array[47])
{
	int i, j, k, l; int x, y, z, cc;
	cow na[20], nb[20], nc[20];
	int la, lb, lc;
	int newarray[47];

//	time1 = ;
//	if (abs(difftime(time(NULL), time0)) > 4)
//		return -1;
//	cout << nswaps << endl;

	if (nswaps == 0)
	{
		for (i = 0; i < 47; i++)
			if (array[i] != TARGET[i])
				return 0;
		return 1;
	}


	for (i = 0; i < nswaps; i++)
		for (j = 0; j < nswaps; j++)
			for (k = 0; k < nswaps; k++)
			{
				la = 0; lb = 0; lc = 0;
				x = a[i].n;
				y = b[j].n;
				z = c[k].n;
				if ((z >= y) && (y >= x))
				{
					for (l = 0; l < 47; l++)
						newarray[convert(x,y,z,l)] = array[l];

//					outfile << nswaps << endl;
//						for (l = 0; l < 47; l++)
//							outfile << (char)newarray[l];


//					outfile << i << " " << j << " " << k << ", " << x << " " << y << " " << z << endl;
//

					for (l = 0; l < nswaps; l++)
					{
						if (l != i) na[la++] = convertCow(a[i],b[j],c[k],a[l]);
						if (l != j) nb[lb++] = convertCow(a[i],b[j],c[k],b[l]);
						if (l != k) nc[lc++] = convertCow(a[i],b[j],c[k],c[l]);
					}
					cc = canBeDone(nswaps-1,na,nb,nc,newarray);
					if (cc = 1)
						return 1;
					if (cc = -1)
						return -1;
				}
			}
	return 0;
}

void versionB()
{


	ifstream infile("INPUT.TXT");
	char S[100]; int C = 0, O = 0, W = 0, k = 0, l = 0, i, cc;
	int T[100]; cow a[20], b[20], c[20];


	infile.getline(S, 100, '\n');

	for (i = 0; i < strlen(S); i++)
	{
		if (S[i] == 'C')
		{	a[C].n = k; a[C].absPos = l; C++; l++; }
		else if (S[i] == 'O')
		{	b[O].n = k; b[O].absPos = l; O++; l++; }
		else if (S[i] == 'W')
		{	c[W].n = k; c[W].absPos = l; W++; l++; }
		else if (S[i] == '\n')
			;
		else
			{ T[k] = S[i]; k++; l++; }
	}

	if (C != O || O != W || k != 47)
	{  outfile << "0 0" << endl; return; }

	if (C > 7)
   { 	outfile << 1 << " " << C << endl; return; }
	cc = canBeDone(C, a, b, c, T);

	if (cc == 1)
		outfile << 1 << " " << C << endl;
	else if (cc == 0)
		outfile << "0 0" << endl;
	else
   	outfile << 1 << " " << C << endl;

	return;
}


void swap2(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}


void swap(int a[], int i, int j, int k)
{
	int b[LENGTH]; int l;
	for (l = 0; l < i; l++)
		b[l] = a[l];
	for (l = j; l <= k; l++)
		b[i+l-j]=a[l];
	for (l = i; l < j; l++)
		b[k-j+l+1]=a[l];
	for (l = k+1; l < LENGTH; l++)
		b[l] = a[l];
	for (l = 0; l < LENGTH; l++)
		a[l] = b[l];
}

int swap_sort(int b[])
{
	int i, j, k, s=0;
	int a[LENGTH];
	for (i = 0; i < LENGTH; i++)
   	a[i] = b[i];
	for (i = 0; i < LENGTH; i++)
		if (a[i] != i)
		{
			j = i;
			while (a[j] != i)
				j++;
			k = j;
			while (k != LENGTH - 1 && a[k+1] < a[i])
				k++;
			swap(a, i, j, k); s++;
		}
	return s;
}


main()
{
	randomize();
	ifstream infile("INPUT.TXT"); ofstream outfile("OUTPUT.TXT");
	char S[100]; int c = 0, o = 0, w = 0, k = 0, l = 0, r, j, ii, jj, m = 0;
	int A[LENGTH]; time0 = time(NULL); time1;

	infile.getline(S, 100, '\n');

	for (int i = 0; i < strlen(S); i++)
	{
		if (S[i] == 'C')
			c++;
		else if (S[i] == 'O')
			o++;
		else if (S[i] == 'W')
			w++;
		else if (S[i] == '\n')
			;
		else
			{ T[k] = S[i]; k++; }
	}

	if (c != o || o != w || strlen(T) != LENGTH)
	{  outfile << 0 << " " << 0 << endl; return 0; }


	for (i = 0; i < LENGTH; i++)
	{
		r = 1;
		for (j = 0; j < l; j++)
			 if (C[j].c == U[i])
			 { 	C[j].howMany++; r = 0; C[j].positions[C[j].howMany-1] = i; }
		if (r == 1)
		{  C[l].c = U[i];
			C[l].howMany = 1;
			C[l].positions[0] = i;
				l++;
		}
	}

	for (i = 0; i < LENGTH; i++)
		for (j = 0; j < LENGTH; j++)
				V[i][j] = -1;

	for (i = 0; i < LENGTH; i++)
	{
		j = 0;
		while (C[j].c != T[i] && j < l)
			j++;
		if (C[j].c != T[i])
		{		outfile << 0 << " " << 0 << endl; return 0; }
		if (C[j].howMany == 1)
		{	A[i] = C[j].positions[0];
				V[j][0] = i;
					}
		else
			A[i] = -1;
	}

	for (i = 0; i < LENGTH; i++)
	{
		j = 0;
		while (C[j].c != T[i] && j < l)
			j++;
		if (C[j].c != T[i])
		{		outfile << 0 << " " << 0 << endl; return 0; }
		ii = -1; jj = -1;
		for (k = 0; k < C[j].howMany; k++)
			if (i && (C[j].positions[k] == (A[i-1] + 1)))
			{	ii = k; break; }
		for (k = 0; k < C[j].howMany; k++)
			if (i != (LENGTH - 1) && (C[j].positions[k] == (A[i+1] - 1)))
			{	jj = k; break; }
		if (ii != -1 && jj != -1)
			ii = min(ii, jj);
		else if (ii == -1 && jj != -1)
			ii = jj;
		if (ii == -1 && jj == -1)
		{  ii = 0;
			for (k = 0; k < C[j].howMany; k++)
				if (C[j].positions[k] < C[j].positions[ii]) ii = k;
		}

		A[i] = C[j].positions[ii];
		m = 0;
		while (V[j][m] != -1)
			m++;
		V[j][m] = i;
		for (k = ii; k < C[j].howMany-1; k++)
			C[j].positions[k] = C[j].positions[k+1];

		C[j].howMany--;

		if (C[j].howMany == -1)
		{		outfile << 0 << " " << 0 << endl; return 0; }
	}

	int q, qq, r1, r2, i1, i2;

	q = swap_sort(A);
	if (q <= c)
		{ 		infile.close(); versionB(); }
	else {
	i = 0;

	while (q > c)
	{
		time1 = time(NULL);
		if (abs(difftime(time1, time0)) > 1)
			break;
		for (j = 0; j < l; j++)
			if (V[j][0] != -1 && V[j][1] != -1)
			  { m = 0;
				while (V[j][m] != -1)
					m++;
				r1 = 0; r2 = 0;
				while (r1 == r2)
				 {	r1 = rand() % m;	r2 = rand() % m; }

				swap2(A[V[j][r1]], A[V[j][r2]]);
				qq = swap_sort(A);
				if (qq == q)
					;
				else if (qq < q)
					q = qq;
				else
				  swap2(A[V[j][r1]], A[V[j][r2]]);
				}
	}

	if (q > (c + 1))
		outfile << "0 0" << endl;
	else
	{	infile.close(); versionB(); }

	}


	 return 0;

}

### End



