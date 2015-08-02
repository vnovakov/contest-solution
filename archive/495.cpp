/* @JUDGE_ID: 3207EZ 495 C++ */
#include <iostream.h>

unsigned long stor[48];

main()
{
	int i;
	stor[0] = 0;
	stor[1] = 1;

	for (i = 2; i < 48; i++)
		stor[i] = stor[i - 1] + stor[i - 2];

	while (cin >> i)
		cout << "The Fibonacci number for " << i << " is " << stor[i] << endl;

	return 0;
}
