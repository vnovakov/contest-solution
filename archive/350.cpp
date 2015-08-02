/* @JUDGE_ID: 3207EZ 350 C++ */
#include <iostream.h>

int z, i, m, l, s[30000], k, p;
int ca = 1;


main()
{

	while (1)
	{
		 cin >> z >> i >> m;
		 if (!m)
			break;
		 cin >> l;

		 for (k = 0; k < m; k++)
			s[k] = -1;
		 k = 0;
		 s[l] = 0;
		 while (1)
		 {
			k++;
			l = ((long)z*l + i) % m;
			if (s[l] != -1) {
            p = k - s[l];
				cout << "Case " << ca++ << ": " << p << endl;
				goto next;
			} else {
			s[l] = k; }
		 }
		 next:
		 ;
	}

	return 0;
}