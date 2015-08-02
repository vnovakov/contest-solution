/* @JUDGE_ID: 3207EZ 424 C++ */
#include <iostream.h>
#include <string.h>

main()
{
	char s[100];
	int curr[100];
	int sum[102];
	int pn, i, n = 0, carry, ps;

	while (1)
	{
			cin >> s;
		if (s[0] == '0')
			break;
		pn = strlen(s);
		if (pn > n)
			n = pn;
		for (i = 0; i < pn; i++)
			curr[pn - 1 - i] = s[i] - '0';
		for (i = pn; i < n; i++)
			curr[i] = 0;
		carry = 0;
		for (i = 0; i < n; i++)
		{
			ps = sum[i] + curr[i] + carry;
			sum[i] = ps % 10;
			carry = ps / 10;
		}
		if (carry)
		{	n++; sum[n-1] = carry; }
	}

	for (i = n - 1; i >= 0; i--)
		cout << sum[i];
	cout << endl;

	return 0;
}


