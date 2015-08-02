/* @JUDGE_ID: 574 C */

#include <stdio.h>

int total, num, p;
int number[13], count[13], curcount[13];


permutate(int level, int sum) {
	int i, j, printed;
	if (level > num) {
		if (sum == total) {
			printed = 0;
			p = 1;
			for (i=1;i<=num;i++)
				for (j=1;j<=curcount[i];j++)
					if (printed == 0) {
						printf("%d", number[i]);
						printed = 1;
					}
					else printf("+%d", number[i]);
			printf("\n");
		}
	}
	else {
		for (i=count[level];i>=0;i--) {
			if (sum + i*number[level] <= total) {
				curcount[level] = i;
				permutate(level+1, sum + i*number[level]);
			}
		}
	}
}

main() {

	int i, j, present, tempnum, n;

	scanf("%d %d", &total, &tempnum);
	while (tempnum!=0) {
		num = 0;
		for (i=1;i<=tempnum;i++) {
			scanf("%d", &n);
			present = 0;
			for (j=1;j<=num;j++)
				if (n == number[j]) {
					present = 1;
					count[j]++;
				}
			if (present == 0) {
				num++;
				number[num] = n;
				count[num] = 1;
			}
		}
		p = 0;
		printf("Sums of %d:\n", total);
		for (i=1;i<=12;i++) curcount[i] = 0;
		permutate(1, 0);
		if (p == 0) printf("NONE\n");
		scanf("%d %d", &total, &tempnum);
	}
}