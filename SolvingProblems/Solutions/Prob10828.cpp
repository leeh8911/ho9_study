#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <stdlib.h>

#ifdef TEST_MODE
#include "Prob10828.h"
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

void stack_push(Stack* s, int value)
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

int stack_pop(Stack* s)
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
int stack_size(Stack* s)
{
	int result = s->size;

	return result;
};
int stack_empty(Stack* s)
{
	int result = s->size > 0 ? 0 : 1;
	return result;
};
int stack_top(Stack* s)
{
	int result = s->top->value;
	return result;
};


#ifdef TEST_MODE
int BK_Prob_10828(void)
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
	int* result = (int*)malloc(sizeof(int) * n);
	memset(result, 0, sizeof(int) * n);


#ifdef TEST_MODE1
	stack_push(stack, 1);
	stack_push(stack, 2);
	stack_top(stack);
	stack_size(stack);
	stack_empty(stack);
	stack_pop(stack);
	stack_pop(stack);
	stack_pop(stack);
	stack_size(stack);
	stack_empty(stack);
	stack_pop(stack);
	stack_push(stack, 3);
	stack_empty(stack);
	stack_top(stack);

#else
	int res = 0;
	res += scanf("%d", &n);
	int iter = 0, count = 0;
	int push_value = 0;
	char input[256];
	char input_num[256];
	while (iter < n)
	{
		res += scanf("%s", input);

		if (strcmp(input, "top") == 0)
		{
			result[count] = stack_top(stack);
			count++;
		}
		else if (strcmp(input, "size") == 0)
		{
			result[count] = stack_size(stack);
			count++;
		}
		else if (strcmp(input, "empty") == 0)
		{
			result[count] = stack_empty(stack);
			count++;
		}
		else if (strcmp(input, "pop") == 0)
		{
			result[count] = stack_pop(stack);
			count++;
		}
		else
		{
			res += scanf("%s", input_num);
			push_value = 0;
			for (int i = 0; i < 256; i++)
			{
				if (input_num[i] != 0)
				{
					push_value *= 10;
					push_value += (input_num[i] - '0');
				}
				else
				{
					break;
				}
			}
			stack_push(stack, push_value);
		}
		iter++;
	}
#endif

	for (int i = 0; i < count; i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}