/* @JUDGE_ID: 3207EZ 440 C++ */
#include <iostream.h>

int array[100] = {0,0,0,0,0,0,0,0,0,0,0,0,0,7,18,
10,11,7,17,11,15,29,5,21,13,26,14,11,23,22,9,
73,17,42,7,98,15,61,22,84,24,30,9,38,15,54,
27,9,61,38,22,19,178,38,53,79,68,166,20,9,22,
7,21,72,133,
41,10,82,92,64,129,86,73,67,19,66,115,52,
24,22,176,10,57,137,239,41,70,60,116,81,79,
55,102,49,5,22,54,52,113,15};

/*
long m(int n)
{
	int array[100]; long M = 2; int pos, cover, ok; long i;

	while (1)
	{
		for (i = 0; i < n; i++)
			array[i] = 1;
		cover = n - 1;
		pos = 0;
		array[0] = 0;
		while (1)
		{
			for (i = 0; i < M; i++)
			{
				pos++;
				pos = pos % n;
				while (!array[pos])
				{
					pos++; pos = pos % n;
				}
			}
			array[pos] = 0;
			cover--;
			if (pos == 12 && !cover)
			{ ok = 1;		break; }
			if (!cover && pos != 12)
         {	ok = 0; break; }
		}
		if (ok)
			return M;
		else
			M++;
	}

}
*/
main()
{
	int i;

	while (1)
	{
		cin >> i;
		if (!i)
			break;
		cout << array[i] << endl;
	}

	return 0;
}