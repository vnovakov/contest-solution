/* @JUDGE_ID: 3207EZ 155 C++  */

#include <iostream.h>
#include <iomanip.h>
#include <math.h>

int px, py; int count;

void insertSquare(float x, float y, int a)
{
	float x1, x2, y1, y2;

	if (a < 1)
		return;
	else {
		x1 = x - a;
		x2 = x + a;
		y1 = y - a;
		y2 = y + a;
		if (px >= x1 && px <= x2 && py >= y1 && py <= y2)
			count++;
		if (px <= x && py <= y) insertSquare(x1,y1,a/2);
		if (px <= x && py >= y) insertSquare(x1,y2,a/2);
		if (px >= x && py >= y) insertSquare(x2,y2,a/2);
		if (px >= x && py <= y) insertSquare(x2,y1,a/2);
	}
}

main()
{
	int a;

	while (cin >> a >> px >> py)
	{
		if (a + px + py == 0)
			break;
		count = 0;
		insertSquare(1024.5,1024.5,a);
		cout << setw(3) << count << endl;
	}

   return 0;
}