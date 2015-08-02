/* @JUDGE_ID: 3207EZ 538 C++ */
#include <iostream.h>
#include <stdio.h>
#include <string.h>

char names[32][32];
int amounts[32];
char name1[32], name2[32];

int GetName(char * ptr)
{
	int i;
	i = 0;
	while (strcmp(ptr, names[i])) ++i;
	return i;
}

int main(void)
{
	int n, t, i, j, k, probn;

	probn = 0;
	while (1) {
		cin >> n >> t;
		if (n == 0) break;
		memset(amounts, 0, sizeof(amounts));
		for (i = 0; i < n; ++i)
			cin >> names[i];
		while (t--) {
			cin >> name1 >> name2 >> i;
			amounts[GetName(name1)] += i;
			amounts[GetName(name2)] -= i;
		}

		i = j = 0;
		printf("Case #%d\n", ++probn);
		while (1) {
			while ((i < n) && (amounts[i] <= 0)) ++i;
			if (i == n) break;
			while (amounts[j] >= 0) ++j;
			k = (amounts[i] > -amounts[j])?-amounts[j]:amounts[i];
			amounts[i] -= k;
			amounts[j] += k;
			printf("%s %s %d\n", names[j], names[i], k);
		}
		printf("\n");
	}

 return 0;
}