/* @JUDGE_ID: 3207EZ 443 C++ */
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct ugly {
	int p2;
	int p3;
	int p5;
	int p7;
};

float log2 = log10(2), log3 = log10(3), log5 = log10(5), log7 = log10(7);
long nums[5842];
int perm[5842];
ugly huge array[5842];

int icmp(void const *a, void const *b)
{
	int A = *(int *)a;
	int B = *(int *)b;
	if (nums[A] > nums[B])
		return 1;
	return -1;
}

main()
{

	int A, B, C, D, i, j, k, l; int count = 0;
	unsigned long big = 2000000000; int n; // float bigLog = log10(2) + 9;
	float subs;
	double t1, t2;
	long num = 1;

	A = 30;

	for (i = 0; i <= A; i++)
	{
		B = (bigLog - i*log2) / log3;
		for (j = 0; j <= B; j++) {
			C = (bigLog - i*log2 - j*log3) / log5;
			for (k = 0; k <= C; k++)
			{
				D = (bigLog - i*log2 - j*log3 - k*log5) / log7;
				subs = (float)i*log2 + j*log3 + k*log5 - log7;
				for (l = 0; l <= D; l++)
				{
					subs += log7;
					if (subs < 9.4) {
					array[count].p2 = i;
					array[count].p3 = j;
					array[count].p5 = k;
					array[count].p7 = l;
				//	logs[count] = subs;
					nums[count] = num;
					perm[count] = count;
					count++; }
				}
			}
		}
	}
	t1 = clock() / CLOCKS_PER_SEC;
	qsort(perm, count, sizeof(int), icmp);
	t2 = clock() / CLOCKS_PER_SEC;
	while (cin >> n)
	{
		if (n != 5842) {
		big = (unsigned long)pow(2,array[perm[n - 1]].p2);
		big *= 	pow(3,array[perm[n - 1]].p3);
		big *=	pow(5,array[perm[n - 1]].p5);
		big *= 		pow(7,array[perm[n - 1]].p7); }
		else big = 2000000000;
		cout << "The " << n;
		if ((n / 10) % 10 != 1 && n % 10 == 1)
			cout << "st";
		else if ((n / 10) % 10 != 1 && n % 10 == 2)
			cout << "nd";
		else if ((n / 10) % 10 != 1 && n % 10 == 3)
			cout << "rd";
		else
			cout << "th";
		cout << " humble number is " << big << "." << endl;
	 }

	return 0;
}
