#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

#ifdef TEST_MODE
#include "Prob10828.h"
#include <time.h>
#endif

enum STACK_CMD {
	STACK_CMD_PUSH,
	STACK_CMD_SIZE,
	STACK_CMD_TOP,
	STACK_CMD_POP,
	STACK_CMD_EMPTY,
};


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
	memset(node, 0, sizeof(Node));

	node->value = value;
	node->next = s->top;

	s->top = node;
	s->size++;
};
int stack_pop(Stack* s)
{
	int result = 0;
	Node* temp = s->top;

	if (temp == NULL)
	{
		result = -1;
	}
	else
	{
		result = temp->value;
		s->top = temp->next;

		temp->value = 0;
		free(temp);
		s->size--;
	}

	printf("%d\n", result);
	return result;

};
int stack_size(Stack* s)
{
	int result = s->size;

	printf("%d\n", result);
	return result;
};
int stack_empty(Stack* s)
{
	int result = s->size > 0 ? 0 : 1;
	printf("%d\n", result);
	return result;
};
int stack_top(Stack* s)
{
	int result = s->top->value;
	printf("%d\n", result);
	return result;
};

void do_command(enum STACK_CMD cmd, Stack* s, int value)
{
	switch (cmd)
	{
	case(STACK_CMD_PUSH):
		stack_push(s, value);
		break;
	case(STACK_CMD_SIZE):
		stack_size(s);
		break;
	case(STACK_CMD_TOP):
		stack_top(s);
		break;
	case(STACK_CMD_POP):
		stack_pop(s);
		break;
	case(STACK_CMD_EMPTY):
		stack_empty(s);
		break;
	default:
		break;
	}
}


#ifdef TEST_MODE
int BK_Prob_10828(void)
#else
int main(void)


#endif
{
	int n = 0;

	Stack *stack = (Stack*)malloc(sizeof(Stack));
	memset(stack, 0, sizeof(Stack));


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
	scanf("%d", &n);
	int iter = 0;
	char input[10];
	while (iter < n)
	{
		scanf("%s", input);

		if (strcmp(input, "top") == 0)
		{

		}
		else if (strcmp(input, "size") == 0)
		{

		}
		else if (strcmp(input, "empty") == 0)
		{

		}
		else if (strcmp(input, "pop") == 0)
		{

		}
		else
		{

		}



		iter++;
	}
#endif


	return 0;
}