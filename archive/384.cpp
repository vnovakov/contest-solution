#include <iostream.h>

main()
{
	int N;

	cin >> N;
	cout << "SLURPYS OUTPUT" <<  endl;
	while (N--)
	{
		cin >> S;

		for (i = 1; i < strlen(S) - 1; i++)
			if (isSlimp(0, i) && isSlump(i + 1, strlen(S) - 1))
			{	cout << "YES"; break; }
		if (i == strlen(S) + 1)
			cout << "NO";
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;

	return 0;
}
