/* @JUDGE_ID: 3207EZ 537 C++ */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {

	float concept[4];
	float prefix;
	int start, i, j, n, cur, length;
	char s[401], temp[100];


	scanf("%d\n", &n);
	for (i=1;i<=n;i++) {
		gets(s);
		for (j=1;j<=3;j++) concept[j] = -1;
		start = 0;
		for (j=0;j<=strlen(s)-1 && s[i] != '\n';j++) {
			if (start == 1) {
				switch (s[j]) {
					case 'M': prefix = 1000000; start = 0; break;
					case 'm': prefix = 0.001; start = 0; break;
					case 'k': prefix = 1000; start = 0; break;
					case 'V': start = 0; break;
					case 'A': start = 0; break;
					case 'W': start = 0; break;
					default: temp[length] = s[j];
								length++;
								break;
				}
				if (start == 0) {
					temp[length] = '\0';
					concept[cur] = prefix * atof(temp);
				}
			}
			if (s[j] == '=') {
				switch (s[j-1]) {
					case 'I': cur = 1; break;
					case 'U': cur = 2; break;
					case 'P': cur = 3; break;
				}
				start = 1; prefix = 1; length = 0;
			}
		}

		printf("Problem #%d\n", i);
		if (concept[1] == -1) printf("I=%.2fA\n\n", concept[3] / concept[2]);
		if (concept[2] == -1) printf("U=%.2fV\n\n", concept[3] / concept[1]);
		if (concept[3] == -1) printf("P=%.2fW\n\n", concept[1] * concept[2]);
	}
}
      	
