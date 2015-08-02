
#include <fstream.h>

ifstream input ("beads.in");
ofstream output ("beads.out");

int n;
char array[500];
int max[500];

int same(char a, char b)
{
	if (a == 'w' || b == 'w')
		return 1;
	if (a == b)
		return 1;
	return 0;
}

char getArray(int i)
{
	i %= n;
	if (i >= 0)
		return array[i];
	else
		return array[n+i];
}

main()
{
	int i, j, k, l, index;
	char nw;

	input >> n;
	for (i = 0; i < n; i++)
		input >> array[i];
	for (i = 0; i < n; i++)
	{
		// break before the ith bead
		j = i - 1; k = 0;
		nw = getArray(i - 1);
		while (j != i - 1 - n && same(getArray(j),nw))
		{
			if (getArray(j) != 'w')
				nw = getArray(j);
			k++;
			j--;
		}
		l = j + 1;
		j = i;
		nw = getArray(i);
		while (j != i + n && (j - l) % n && same(getArray(j),nw))
		{
			if (getArray(j) != 'w')
				nw = getArray(j);
			k++;
         j++;
		}
		max[i] = k;
	}

	index = 0;

	for (i = 0; i < n; i++)
		if (max[i] > max[index])
			index = i;

	output << max[index] << endl;

	return 0;
}
