### PROGRAM
/*

ID: vnovako001
PROG: fence8

*/

#include <iostream.h>
#include <fstream.h>

int board_lengths[50];
int board_remainders[50];
int rail_lengths[1023];
int rail_boards[1023];
int nb, nr, ir, max_rem;

void init()
{
	int i;
	ifstream infile("fence8.in");
	infile >> nb;
	for (i = 0; i < nb; i++)
		infile >> board_lengths[i];
	infile >> nr;
	for (i = 0; i < nr; i++)
	{	infile >> rail_lengths[i]; rail_boards[i] = -1; }
}

void swap (int &a, int &b)
{	int temp = a;
	a = b;
	b = temp;
}

void Split(int first, int last, int & splitPoint)
{
	int splitVal =  rail_lengths[first];
	splitPoint =  first;
	first++;
	while (first <=  last)
	{
		if (rail_lengths[first] <=  splitVal )
			first++;

		else if (rail_lengths[last] >=  splitVal)
			last--;
		else
			{   swap (rail_lengths[first], rail_lengths[last]);
				first++;
				last--;
			}
	}
	swap (rail_lengths[splitPoint], rail_lengths[last]);
	splitPoint =  last;
}

void sortRails ( int first, int last)
{
	int splitPoint;
	if (first < last)	// general case
	{
		Split (first, last, splitPoint);
		sortRails (first, splitPoint - 1);
		sortRails (splitPoint + 1, last);
	}
}


int arrange()
{
	int changes = 1, i, j, k, a, b, x, y;
	max_rem = 0;
	for (i = 0; i < nb; i++)
		 if (board_remainders[i] > max_rem) max_rem = board_remainders[i];

	while(changes && max_rem < rail_lengths[ir])
	{  changes = 0;
		for (i = 0; i < nr; i++)
		if (rail_boards[i] != -1)
			for (j = 0; j < nr; j++)
			if (rail_boards[j] != -1 && rail_boards[j] != rail_boards[i])
			{	// Proposed swap
				x = board_remainders[rail_boards[i]];
				y = board_remainders[rail_boards[j]];
				a = x + rail_lengths[i] - rail_lengths[j];
				b = y + rail_lengths[j] - rail_lengths[i];
				if ((a > 0) && (b > 0) && ((a > x && a > y) || (b > x && b > y)))
				{   changes = 1;
					 board_remainders[rail_boards[i]] = a;
					 board_remainders[rail_boards[j]] = b;
					 k = rail_boards[i];
					 rail_boards[i] = rail_boards[j];
					 rail_boards[j] = k;
				}
			}
		for (i = 0; i < nb; i++)
			for (j = 0; j < nr; j++)
				if (rail_boards[j] >= 0 && rail_boards[j] != i &&
				    rail_lengths[j] <= board_remainders[i] &&
					 board_remainders[rail_boards[j]] + rail_lengths[j] >
					 board_remainders[i])
				{  board_remainders[rail_boards[j]] += rail_lengths[j];
					rail_boards[j] = i;
					board_remainders[i] -= rail_lengths[j];
				}

		for (i = 0; i < nb; i++)
			 if (board_remainders[i] > max_rem) max_rem = board_remainders[i];
	}
	if (max_rem >= rail_lengths[ir])
		return 1;
	else
		return 0;
}

void doSelection()
{
	int i, j;
	sortRails(0, nr - 1);
	for (i = 0; i < nb; i++)
		board_remainders[i] = board_lengths[i];

	for (i = 0; i < nr; i++)
	{  j = 0;
		while (j < nb && rail_boards[i] == -1)
		{	if (board_remainders[j] >= rail_lengths[i])
			{	rail_boards[i] = j;  board_remainders[j] -= rail_lengths[i]; }
			j++;
		}
		if (rail_boards[i] == -1)
		{	ir = i;
			goto doneForNow;
		}
	}
	ir = i;
   return;
	doneForNow:
	;

	while (arrange())
	{
		j = 0;
		while (j < nb && rail_boards[ir] == -1)
		{	if (board_remainders[j] >= rail_lengths[ir])
			{	rail_boards[ir] = j;  board_remainders[j] -= rail_lengths[ir]; }
			j++;
		}
		ir++;
	}
}

void main()
{
	ofstream outfile("fence8.out");
	init();
	doSelection();
	outfile << ir << endl;

}
### END
