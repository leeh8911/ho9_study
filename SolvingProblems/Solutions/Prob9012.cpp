#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <stdlib.h>

#ifdef TEST_MODE
#include "Prob9012.h"
#include <time.h>
#endif

typedef struct tNode {
	int value;
	tNode* next;
}Node;

typedef struct tStack {
	int size;
	Node* top;
}Stack;

static void stack_push(Stack* s, int value)
{
	Node* node = (Node*)malloc(sizeof(Node));

	if (node != NULL)
	{
		node->value = value;
		node->next = s->top;

		s->top = node;
		s->size++;
	}
};

static int stack_pop(Stack* s)
{
	int result = 0;
	Node* temp = s->top;

	if (temp == NULL)
	{
		result = 0;
	}
	else
	{
		result = temp->value;
		s->top = temp->next;

		temp->value = 0;
		free(temp);
		s->size--;
	}

	return result;

};

static void stack_clear(Stack* s)
{
	while (stack_pop(s) != 0)
	{
	}
}

static int stack_size(Stack* s)
{
	int result = s->size;

	return result;
};
static int stack_empty(Stack* s)
{
	int result = s->size > 0 ? 0 : 1;
	return result;
};
static int stack_top(Stack* s)
{
	int result = s->top->value;
	return result;
};
static void stack_print(Stack* s)
{
	Node* temp = s->top;
	for (int i = 0; i < s->size; i++)
	{

		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
};


#ifdef TEST_MODE
int BK_Prob_9012(void)
#else
int main(void)


#endif
{
	int n = 0;

	Stack *stack = (Stack*)malloc(sizeof(Stack));
	if (stack != NULL)
	{
		memset(stack, 0, sizeof(Stack));
	}


#ifdef TEST_MODE
	n = 6;
	char input[6][50] = { {")()()("}, {"(((()())()"}, {"(()())((()))"}, {"((()()(()))(((())))()"}, {"()()()()(()()())()"}, {"(()((())()("} };
#else
	scanf("%d", &n);
	char** input = (char**)malloc(sizeof(char*) * n);
	for (int i = 0; i < n; i++)
	{
		input[i] = (char*)malloc(sizeof(char) * 50);
		scanf("%s", input[i]);
	}

#endif
	int* result = (int*)malloc(sizeof(int) * n);
	if (result != NULL)
	{
		memset(result, 0, sizeof(int) * n);
	}
	else
	{
		return 1;
	}
	
	int wrong_flag = 0, empty_flag = 0;
	for (int i = 0; i < n; i++)
	{
		stack_clear(stack);
		wrong_flag = 0;
		for (int j = 0; j < 50; j++)
		{
			if (input[i][j] - '(' == 0)
			{
				stack_push(stack, 1);
			}
			else if (input[i][j] - ')' == 0)
			{
				empty_flag = stack_pop(stack);
				if (empty_flag == 0)
				{
					wrong_flag = 1;
					break;
				}
			}
			else
			{
				break;
			}
		}
		if (wrong_flag == 1)
		{
			/* do nothing */
			/* already wrong */
		}
		else
		{
			if (stack_empty(stack))
			{
				/* do nothing */
				/* correct */
			}
			else
			{
				wrong_flag = 1;
			}
		}
		if (wrong_flag == 1)
		{
			result[i] = 1;
		}
		else
		{
			result[i] = 0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (result[i] == 1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
		}
	}


	return 0;
}