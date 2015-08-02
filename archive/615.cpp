/* @JUDGE_ID: 3207EZ 615 C++ */
#include <iostream.h>

int nums[100];
int outNodes[100][100];
int in[100];
int out[100];
int visited[100];
int done[100];
int N;

int getIndex(int num)
{
	int i;
	for (i = 0; i < N; i++)
		if (nums[i] == num)
			return i;
	nums[N] = num;
	return N++;
}

main()
{
	int c = 1, i, nDone, j, k, tree, a, b, A, B, root;

	while (1)
	{

		for (i = 0; i < 100; i++)
			in[i] = out[i] = visited[i] = done[i] = 0;
		N = 0;

		while (1)
		{
			cin >> a >> b;
			if (a == -1 && b == -1)
				return 0;
			if (a == 0 && b == 0)
				break;
			A = getIndex(a);
			B = getIndex(b);
			in[B]++;
			outNodes[A][out[A]++] = B;
		}

		root = -1;
		tree = 1;
		for (i = 0; i < N; i++)
		{
			if (in[i] == 0)
			{
				if (root != -1)
				{
					tree = 0; break; }
				else
					root = i;
			}
			if (in[i] > 1)
			{	tree = 0; break; }
		}
		if (!N)
			cout << "Case " << c << " is a tree." << endl;
		else if (!tree || root == -1)
			cout << "Case " << c << " is not a tree." << endl;
		else {
			nDone = 0;
			visited[root] = 1;
			while (nDone < N)
			{
				for (i = 0; i < N; i++)
					if (visited[i] && !done[i])
					{	j = i; break; }
				if (i == N)
				{	tree = 0; break; }
				done[j] = 1;
				nDone++;
				for (i = 0; i < out[j]; i++)
				{
					k = outNodes[j][i];
					if (visited[k])
					{	tree = 0; goto done; }
					visited[k] = 1;
				}
			}
			done:
			;
			if (tree)
				cout << "Case " << c << " is a tree." << endl;
			else
				cout << "Case " << c << " is not a tree." << endl;
		}
		c++;
	}

	return 0;
}
