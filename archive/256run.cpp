/* @JUDGE_ID: 3207EZ 256 C++ */
#include <iostream.h>

typedef char * string;

string num2[3] = {"00","01","81"};
string num4[5] = {"0000","0001","2025","3025","9801"};
string num6[5] = {"000000","000001","088209","494209","998001"};
string num8[9] = {"00000000","00000001","04941729","07441984",
						"24502500","25502500","52881984","60481729","99980001"};

main()
{
	int m;
	int k;

	while (cin >> m)
	{
		if (m == 2)
			for (k = 0; k < 3; k++)
				cout << num2[k] << endl;
		else if (m == 4)
			for (k = 0; k < 5; k++)
				cout << num4[k] << endl;
		else if (m == 6)
			for (k = 0; k < 5; k++)
				cout << num6[k] << endl;
		else if (m == 8)
			for (k = 0; k < 9; k++)
				cout << num8[k] << endl;
	}

	return 0;
}
