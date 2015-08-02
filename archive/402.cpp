/* @JUDGE_ID: 3207EZ 402 C++ "Linked list" */
#include <iostream.h>

struct node {
	int data;
	node* next;
	node(int d, node* n);
};

node::node (int d, node* n) : data(d), next(n) { }


main()
{
	int N, rem, i, j, card, select = 1;
	node* head;
	node* prev;
	node* curr;

	while (cin >> N)
	{
		cin >> rem;
		head = NULL;
		for (i = 0; i < N; i++)
			head = new node(N - 1 - i, head);

		for (i = 0; i < 20 && N > rem; i++)
		{
			cin >> card;
			j = 0;

			for (curr = head,	prev = NULL; curr && N > rem; curr = curr -> next, j++)
			{
				if ((j + 1) % card == 0)
				{
					N--;
					if (prev)
					{
						prev -> next = curr -> next;
						prev = curr;
					}
					else
						head = head -> next;
				} else
				  prev = curr;
			}

		}
		for (; i < 20; i++)
			cin >> card;
		cout << "Selection #" << select++ << endl;
		while (head && rem)
		{
			cout << head -> data + 1 << " ";
			head = head -> next;
		}
		cout << endl << endl;
	}

	return 0;
}







