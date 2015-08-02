#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>

struct Item {
	int num;
	long freq;
	int length;
};

int a, b, n;
long huge howMany[13][8192];
Item theBest[1900];
long theNumber[13];
ifstream infile("contact.in");
ofstream outfile("contact.out");


int ItemCmp(const void *a, const void *b)
{
	Item aa, bb;
	aa = *(Item *)a;
	bb = *(Item *)b;
	if (aa.freq == bb.freq)
	{
		if (aa.length > bb.length) {
			return 1;                }
		else if (aa.length == bb.length) {
			if (aa.num > bb.num)
			{	return 1; }
			else if (aa.num == bb.num)
			{	return 0; }
			else {
				return -1; } }
		else {
			return -1; }
	}
	else if (aa.freq < bb.freq) {
		return 1;              }
	else {
		return -1; }
}

void printLength(long num, int length)
{
	int pow2 = 1;
	for (int i = 0; i < length; i++)
		pow2 *= 2;
	if (length)
	{
		printLength(num/2, length-1);
		outfile << num % 2;
	}
}

int main()
{
	char c; int d, i, j, l, ll; long max, p, next; long k = 0; int pow2;
	long q;
	infile >> a >> b >> n;
	for (i = a; i <= b; i++)
	{	theNumber[i] = 0;
		for (j = 0; j < 4096; j++)
			howMany[i][j] = 0;
	}
	while (infile >> c && c != '2')
	{
		k++;
		d = c - '0';
		pow2 = 1;
		for (i = 1; i < a; i++)
			pow2 *= 2;
		for (i = a; i <= b; i++)
		{
			pow2 *= 2;
			theNumber[i] = (theNumber[i]*2 + d) % pow2;
			if (k >= i)
				howMany[i][theNumber[i]]++;
		}
	}
	pow2 = 1; p = 0;
	for (i = 1; i <= b; i++)
		pow2 *= 2;
	for (i = b; i >= a; i--)
	{


		for (j = 0; j < 1800 && j < pow2; j++)
		{
			max = 0; ll = 0;
			for (l = 0; l < pow2; l++)
				if (howMany[i][l] > max)
					{ max = howMany[i][l]; ll = l; }
			theBest[p].num = ll;
			theBest[p].freq = howMany[i][ll];
			theBest[p++].length = i;
			howMany[i][ll] = 0;
		}

		pow2 /= 2;
	}
	qsort(theBest, p, sizeof(Item), ItemCmp);
	i = 0; l = 0;

	while (l < n && theBest[i].freq != 0)
	{
		next = theBest[i].freq;
		outfile << next;
		q = 0;
		while (theBest[i].freq == next)
		{
			if (q % 6) 			outfile << " ";
         else outfile << endl;
			q++;

			printLength(theBest[i].num, theBest[i].length);
			i++;
		}
		outfile << endl;
		l++;
	}
	return 0;
}



