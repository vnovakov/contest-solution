/* @JUDGE_ID: 3207EZ 264 C++ */
#include <iostream.h>

main()
{

	long N;
	long count;
	int x, y;
   int move;

	while (cin >> N)
	{
		count = 1;
		x = 1;
		y = 1;

		while (count++ < N)
		{
			if ((x + y) % 2 == 0)
			{
				x--;
				y++;
				if (!x)
				{
					x++;
					move = x + y - 2;
					if (count + move <= N)
					{
						x += move;
						y -= move;
						count += move;
					}
				}
			}
			else {
				x++;
				y--;
				if (!y)
				{
					y++;
					move = x + y - 2;
					if (count + move <= N)
					{
						x -= move;
						y += move;
						count += move;
					}
				}
			}
		}

		cout << "TERM " << N << " is " << x << "/" << y << endl;

	}

	return 0;
}
