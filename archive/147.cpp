/* @JUDGE_ID: 3207EZ 147 C++ "Dynamic Programming" */
#include <iostream.h>
#include <iomanip.h>


	int value[10] = {1,2,4,10,20,40,100,200,400,1000};
	unsigned long array[1001]; int i, j, n; double d;

void out(double S)
{
	double R = 100*S;
	long Q = R;
	int array[10];
	int i, k = 0;
	if (S < 10)
		cout << " ";

	if (Q < 10) {
		cout  << "0.0" << Q ; return; }
	else if (Q < 100) {
		cout  << "0." << Q ; return; }
	while (Q)
	{
		array[k++] = Q % 10;
		Q /= 10;
	}
	for (i = k - 1; i >= 0; i--)
	{
			cout << array[i];
		if (i == 2)
			cout << '.';
	}

}

main()
{

	while(cin >> d)
	{
			n = 20*d;
			if (!n)
				break;

			for (i = 0; i <= n; i++)
				array[i] = 1;
			for (i = 1; i < 10; i++)
				for (j = 0; j <= n; j++)
				{	if (j >= value[i])
						array[j] += array[j - value[i]];
				}


			out(d);
			cout <<  setw(12) << array[n] << endl;

	}

	return 0;
}
