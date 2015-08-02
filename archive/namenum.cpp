//### PROGRAM
/*
ID: vnovako001
PROG: namenum
*/
#include <fstream.h>
#include <string.h>

ifstream infile("namenum.in");
ifstream dict("dict.txt");
ofstream outfile("namenum.out");

char huge words[5000][18];
	char number[18];

	char word[18];
	int wordL[5000];

main()
{
	int nWords = 0;
	int w, i, l, works, some = 0;
	char k;

	while (dict >> word)
	{
		wordL[nWords] = strlen(word);

		for (i = 0; i < wordL[nWords]; i++)
			words[nWords][i] = word[i];
		nWords++;
	}
	while (infile >> number)
	{
	some = 0;
	for (w = 0; w < nWords; w++)
	{
		for (i = 0; i < wordL[w]; i++)
			word[i] = words[w][i];
		l = wordL[w];
		if (l == strlen(number))
		{
			works = 1;

			for (i = 0; i < l; i++)

			{  	if (word[i] == 'Q' || word[i] == 'Z')
						works = 0;
					if (word[i] > 'Q')
					k = word[i] - 1;
			else
				k = word[i];
					if ('2' + (k - 'A') / 3 != number[i])
						works = 0;
			}
			if (works)
			{	some = 1;
				for (i = 0; i < wordL[w]; i++)
					outfile << words[w][i];
				outfile << endl;
			}
		}
	}

		if (!some)
			outfile << "NONE" << endl;

	}

	return 0;
}
//### END

