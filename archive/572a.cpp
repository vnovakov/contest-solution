/* @JUDGE_ID: 572 C */

#include <stdio.h>

const int dirrow[8] = {0,0,1,1,1,-1,-1,-1};
const int dircol[8] = {1,-1,1,-1,0,1,-1,0};

int count, row, col;
int grid[101][101];

spread(int r, int c) {
	int i;
	for (i=0;i<=7;i++)
		if ((r+dirrow[i]>=1) && (r+dirrow[i]<=row) && (c+dircol[i]>=1) && (c+dircol[i]<=col))
			if (grid[r+dirrow[i]][c+dircol[i]] == 0) {
				grid[r+dirrow[i]][c+dircol[i]] = count;
				spread(r+dirrow[i], c+dircol[i]);
			}
}

main() {


	int i, j;
	char s[102];
	scanf("%d %d", &row, &col);
	while (row!=0) {

		for (i=1;i<=row;i++) {
			scanf("%s", s);
			for (j=1;j<=col;j++)
				if (s[j-1] == '*') grid[i][j] = -1;
				else grid[i][j] = 0;
			}

      count = 0;
		for (i=1;i<=row;i++)
			for (j=1;j<=col;j++)
				if (grid[i][j] == 0) {
					count++;
					grid[i][j] = count;
					spread(i,j);
				}

		printf("%d\n", count);
		scanf("%d %d", &row, &col);
	}
}
