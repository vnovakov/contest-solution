#include <fstream.h>

ifstream infile("preface.in");
ofstream outfile("preface.out");

int I = 0, V = 0, X = 0, L = 0, C = 0, D = 0, M = 0;

void procD(int n, int &a, int &b, int &c)
{
	if (!n)
		return;
	if (n < 4)
		a += n;
	else if (n == 4)
	{	a++; b++; }
	else if (n >= 5 && n < 9)
	{	b++; a += n - 5; }
	else
	{	c++; a++; }
}


void process(int N)
{
	procD(N % 10, I, V, X);
	procD(( N / 10) % 10, X, L, C);
	procD( (N / 100) % 10, C, D, M);
	procD( (N / 1000) , M, M, M);
}

main()
{
	int N;

	infile >> N;

	while(N)
		process(N--);

	if (I) outfile << "I " << I << endl;
	if (V) outfile << "V " << V << endl;
	if (X) outfile << "X " << X << endl;
	if (L) outfile << "L " << L << endl;
	if (C) outfile << "C " << C << endl;
	if (D) outfile << "D " << D << endl;
	if (M) outfile << "M " << M << endl;

	return 0;
}