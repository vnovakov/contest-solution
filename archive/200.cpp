#include <iostream.h>
#include <string.h>

int matrix[26][26];
int in[26]; int out[26];

main()
{
	char str[22]; char last[22];
	int length, ll;
	int nStr = 0; int i, j;
	int visited[26];

	for (i = 0; i < 26; i++)  {
		in[i] = 0;
		out[i] = 0;
		visited[i] = 1;
		for (j = 0; j < 26; j++)
			matrix[i][j] = 0;
	}

	while (cin.getline(str, 22))
	{
		if (str[0] == '#')
			break;
		nStr++;
		length = strlen(str);
		if (nStr != 1)
		{
			for (j = 0; j < ll && j < length && str[j] == last[j]; j++)
				;
			if (j != ll)
			{
				matrix[last[j]  - 'A'][str[j] - 'A'] = 1;
				out[last[j] - 'A']++;
				in[str[j] - 'A']++;
				visited[str[j] - 'A'] = visited[last[j] - 'A'] = 0;
			}
		}
			for (i = 0; i < length; i++)
				last[i] = str[i];
			ll = length;

	}

	while (1)
	{
		for (i = 0; i < 26; i++)
			if (out[i] == 1 && in[i] == 0)
			{	j = i; break; }
		if (i == 26)
			break;
		for (i = 0; i < 26; i++)
			if (matrix[j][i])
			{	in[i]--; matrix[j][i] = 0; }
		out[j] = 0;
		visited[j] = 1;
		cout << (char)('A' + j);
	}
	for (i = 0; i < 26; i++)
		if (!visited[i])
			cout << (char)('A' + i);

	cout << endl;


	return 0;
}

