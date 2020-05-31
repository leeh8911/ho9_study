#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>

#ifdef TEST_MODE
#include "Prob1967.h"
#endif

#define ABS(A) (((A)>0)?(A):(-(A)))
#define MAX(A,B) (((A)+(B) - ABS((A)-(B)))/2)

typedef struct Tree
{
	int item;
	int weight;
	Tree* parent;
	Tree* left;
	Tree* right;
}Tree;

Tree* MakeNode(int item, int weight)
{
	Tree* temp = (Tree*)malloc(sizeof(Tree));
	memset(temp, 0, sizeof(Tree));
	temp->item = item;
	temp->weight = weight;
	return temp;
}

void SetLeftNode(Tree* pa, Tree* ch)
{
	if (pa->left != NULL)
	{
		pa->left = NULL;
	}
	pa->left = ch;
	ch->parent = pa;
}
void SetRightode(Tree* pa, Tree* ch)
{
	if (pa->right != NULL)
	{
		pa->right = NULL;
	}
	pa->right = ch;
	ch->parent = pa;
}

Tree* FindTarget(Tree* tree, int target)
{
	Tree* temp;

	if (tree != NULL)
	{
		if (tree->item == target)
		{
			return tree;
		}
		temp = FindTarget(tree->left, target);
		if (temp != NULL && temp->item == target)
		{
			return temp;
		}
		temp = FindTarget(tree->right, target);
		if (temp != NULL && temp->item == target)
		{
			return temp;
		}
	}
	else
	{
		return NULL;
	}
}

int CalculateDistance(Tree* tree)
{
	int left_weight = 0;
	int right_weight = 0;
	if (tree->left == NULL)
	{
		left_weight = 0;
	}
	else
	{
		left_weight = tree->left->weight;
	}
	if (tree->right == NULL)
	{
		right_weight = 0;
	}
	else
	{
		right_weight = tree->right->weight;
	}

	if (left_weight == 0 && right_weight == 0)
	{
		return 0;
	}
	if (left_weight > right_weight)
	{
		return left_weight + CalculateDistance(tree->left);
	}
	else
	{
		return right_weight + CalculateDistance(tree->right);
	}
}

#ifdef TEST_MODE
int BK_Prob_1967(void)
#else
int main(void)
#endif
{

	int number_of_node = 0;
	Tree* tr = MakeNode(1,0);
	Tree* temp = NULL;
#ifdef TEST_MODE

	scanf("%d", &number_of_node);

	int j = 0, value = 0;
	int input[3] = { 0 };
	for (int i = 0; i < number_of_node -1; i++)
	{
		j = 0;
		temp = NULL;

		scanf("%d %d %d", input,input+1, input+2);

		temp = FindTarget(tr, input[0]);
		if (temp->left == NULL)
		{
			temp->left = MakeNode(input[1], input[2]);
		}
		else
		{
			temp->right = MakeNode(input[1], input[2]);
		}
	}
#else
#endif

	int dist = CalculateDistance(tr);


	return 0;
}