#include <iostream.h>

int huge team[1000000];
int teamPos[1000];
int teamSize[1000];
int teamInQ[1000];
int huge Q[1000000];
int front;
int Qsize;

main()
{
	int scen = 1;
	int nTeam, i, j, a;

	while (1)
	{
		cin >> nTeam;
		if (!nTeam)
			break;
		Qsize = 0;
		front = 0;

		for (i = 0; i < nTeam; i++)
		{	cin >> teamSize[i];
      	teamInQ[i] = 0;
			for (j = 0; j < teamSize[i]; j++)
			{
				cin >> a;
				team[a] = i;
			}
		}

		while (1)
		{
			cin >> S;
			if (S[0] == 'E')
			{	cin >> a;
				if (teamInQe

			}
			else if (S[0] == 'D')
			{

			}
			else
				break;
		}
