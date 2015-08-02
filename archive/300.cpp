#include <stdio.h>

main()
{
	int N;
   int month, day, year;
	scanf("%d", &N);

	while (N--)
	{
		scanf("%d. %s %d", &month, &day, &year);
	}

	return 0;
}