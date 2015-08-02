/*
PROG: fact4
ID: rsc001
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void
main(void)
{
	FILE *fin, *fout;
	int n2, n5, i, j, n, digit;

	fin = fopen("fact4.in", "r");
	fout = fopen("fact4.out", "w");
	assert(fin != NULL && fout != NULL);

	fscanf(fin, "%d", &n);
	digit = 1;
	n2 = n5 = 0;
	for(i=2; i<=n; i++) {
		j = i;
		while(j%2 == 0) {
			n2++;
			j /= 2;
		}
		while(j%5 == 0) {
			n5++;
			j /= 5;
		}
		digit = (digit * j) % 10;
	}

	for(i=0; i<n2-n5; i++)
		digit = (digit * 2) % 10;

	fprintf(fout, "%d\n", digit);
	exit(0);
}