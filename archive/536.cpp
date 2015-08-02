/* @JUDGE_ID: 3207EZ 536 C++ "Recursive split" */
#include <iostream.h>
#include <string.h>

void process(char Pre[30], char In[30], int n)
{
	int i, ii;
	char PreLeft[30], InLeft[30], PreRight[30], InRight[30];
	if (!n)
		return;
	if (n == 1)
		cout << Pre[0];
	else {
		for (i = 0; i < n; i++)
			if (In[i] == Pre[0])
			{	ii = i; break; }
		for (i = 1; i <= ii; i++)
		{ PreLeft[i-1] = Pre[i]; InLeft[i-1] = In[i - 1]; }
		for (i = ii + 1; i < n; i++)
		{ PreRight[i - ii - 1] = Pre[i]; InRight[i - ii - 1] = In[i]; }
		process(PreLeft , InLeft, ii);
		process(PreRight, InRight, n - ii - 1);
		cout << Pre[0];
	}
}

main()
{

	char Pre[30], In[30];

	while (cin >> Pre >> In)
	{
		process(Pre, In, strlen(Pre));
		cout << endl;
	}

	return 0;
}