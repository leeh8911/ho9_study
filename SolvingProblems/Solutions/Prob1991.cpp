#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#ifdef TEST_MODE
#include "Prob1991.h"
#endif

typedef struct Node
{
	char value;
	Node* left;
	Node* right;
}Node;

enum order { PRE, IN, POST };

Node* MakeBinaryTree(void)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	memset(temp, 0, sizeof(Node));

	return temp;
}


void MergeLeftBT(Node* parent, Node* child)
{
	if (parent->left == NULL)
	{
		parent->left = NULL;
	}
	parent->left = child;
}
void MergeRightBT(Node* parent, Node* child)
{
	if (parent->right == NULL)
	{
		parent->right = NULL;
	}
	parent->right = child;
}
void SetValueInBT(Node* bt, char value)
{
	bt->value = value;
}

char GetValueBT(Node* bt)
{
	return bt->value;
}

void Traversal(Node* bt, enum order o)
{
	if (bt == NULL)
	{
		return;
	}

	switch (o)
	{
	case(PRE):
		printf("%c", bt->value);
		Traversal(bt->left, o);
		Traversal(bt->right, o);
		break;
	case(IN):
		Traversal(bt->left, o);
		printf("%c", bt->value);
		Traversal(bt->right, o);
		break;
	case(POST):
		Traversal(bt->left, o);
		Traversal(bt->right, o);
		printf("%c", bt->value);
		break;
	default:
		break;
	}
}

Node* FindData(Node* bt, char data)
{
	Node *left, *right;
	if (bt == NULL)
	{
		return NULL;
	}

	if (bt->value == data)
	{
		return bt;
	}
	left = FindData(bt->left, data);
	right = FindData(bt->right, data);
	if (left != NULL && left->value == data)
	{
		return left;
	}
	else if (right != NULL && right->value == data)
	{
		return right;
	}
}


#ifdef TEST_MODE
int BK_Prob_1991(void)
#else
int main(void)
#endif
{
	int n = 0;
#ifdef TEST_MODE
	scanf("%d", &n);

	char** value = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		value[i] = (char*)malloc(sizeof(char) * 10);
		memset(value[i], 0, sizeof(char) * 10);
	}

	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while(j < 3)
		{
			scanf("%c", &value[i][j]);
			int data = value[i][j] - 'A';
			if (0 <= data && data < 26)
			{
				j++;
			}
			if (value[i][j] == 46)
			{
				value[i][j] = 0;
				j++;
			}

		}
	}
#else
	scanf("%d", &n);

	char** value = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		value[i] = (char*)malloc(sizeof(char) * 10);
		memset(value[i], 0, sizeof(char) * 10);
	}

	for (int i = 0; i < n; i++)
	{
		int j = 0;
		while (j < 3)
		{
			scanf("%c", &value[i][j]);
			int data = value[i][j] - 'A';
			if (0 <= data && data < 26)
			{
				j++;
			}
			if (value[i][j] == 46)
			{
				value[i][j] = 0;
				j++;
			}

}
	}
#endif
	Node* bt = NULL;
	char pa, left, right;
	for (int i = 0; i < n; i++)
	{
		if (bt == NULL)
		{
			bt = MakeBinaryTree();
			Node* bt_left = MakeBinaryTree();
			Node* bt_right = MakeBinaryTree();

			SetValueInBT(bt, value[i][0]);
			if (value[i][1] != 0)
			{
				SetValueInBT(bt_left, value[i][1]);
				MergeLeftBT(bt, bt_left);
			}
			if (value[i][2] != 0)
			{
				SetValueInBT(bt_right, value[i][2]);
				MergeRightBT(bt, bt_right);
			}

		}
		else
		{
			if (value[i][0] == 'A')
			{
				Node* temp = MakeBinaryTree();
				SetValueInBT(temp, value[i][0]);

				if (value[i][1] != 0)
				{
					Node* temp_left = FindData(bt, value[i][1]);
					MergeLeftBT(bt, temp_left);
				}
				if (value[i][2] != 0)
				{
					Node* temp_right = FindData(bt, value[i][2]);
					MergeRightBT(bt, temp_right);
				}

			}
			else
			{
				Node* temp = FindData(bt, value[i][0]);
				Node* temp_left = MakeBinaryTree();
				Node* temp_right = MakeBinaryTree();

				if (value[i][1] != 0)
				{
					SetValueInBT(temp_left, value[i][1]);
					MergeLeftBT(temp, temp_left);
				}

				if (value[i][2] != 0)
				{
					SetValueInBT(temp_right, value[i][2]);
					MergeRightBT(temp, temp_right);
				}
			}
		}
	}

	Traversal(bt, PRE);
	printf("\n");
	Traversal(bt, IN);
	printf("\n");
	Traversal(bt, POST);

	return 0;
}