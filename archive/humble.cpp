#include <fstream.h>
#include <math.h>
#include <stdlib.h>

ifstream infile("humble.in");
ofstream outfile("humble.out");

double huge heap[200001];
double TOL = 0.0000001;
long index;

long primes[100];

void swap(double &a, double &b)
{
	double c = a;
	a = b;
	b = c;
}

void reHeap(long i)
{
	if (2*i > index)
		return;

	if (heap[2*i] + TOL > heap[i] && (
				2*i + 1 > index || heap[2*i] + TOL > heap[2*i + 1]))
	{
		swap(heap[i], heap[2*i]);
			reHeap(2*i);
	}
	else if (2*i + 1 <= index && heap[2*i + 1] + TOL > heap[i] &&
			heap[2*i + 1] + TOL > heap[2*i])
	{
		swap(heap[i], heap[2*i + 1]);
			reHeap(2*i + 1);
	}
}

int icmp(void const *a, void const *b)
{
	long A = *(long *)a;
	long B = *(long *)b;

	if (A < B)
		return 1;
	else
		return -1;
}

long closest(double a)
{
	long B = (long)a;
	if (a - B > 0.5)
		B++;
	return B;
}

main()
{

	int N;

	int power[100];
	long  est, sum = 0; long count;
	int i, j;
	long max = 0;
	double upper;
	double curr;

	infile >> N >> index;

	for (i = 0; i < N; i++)
	{
		infile >> primes[i];
		if (primes[i] > max)
			max = primes[i];
	}

	i = 1;    est = sum = N;

	while (index > sum)
	{
		i++;
		est *= (double)(N + i - 1) / i;
		sum += est;
	}

	upper = pow((double)max, i);

	for (i = 1; i <= index; i++)
		heap[i] = upper;

	curr = 1;

	for (i = 0; i < N; i++)
		power[i] = 0;

	count = 0;

	qsort(primes, N, sizeof(long), icmp);

	while (1)
	{

		j = N - 1;
		power[j]++;
		curr *= (double)primes[j];

		while (curr > upper + TOL)
		{
			if (!j)
				goto finish;
			curr *= (double)primes[j - 1];
			curr /= (double)pow((double)primes[j], power[j]);
			power[j] = 0;
			j--;
			power[j]++;

		}

		if (heap[1] < upper)
			upper = heap[1];

		if (heap[1] > curr)
			heap[1] = curr;

		reHeap(1);

		count++;


	}

	finish:
	;

	outfile << closest(heap[1]) << endl;

	return 0;
}
