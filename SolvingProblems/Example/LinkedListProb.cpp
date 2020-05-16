#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedListProb.h"

typedef struct linked_list* list_pointer;
typedef struct linked_list 
{
	int val;
	list_pointer next;
};
typedef struct DB_list
{
	list_pointer head;
	list_pointer tail;
	int number_of_list;
};


void print_list(DB_list*);
void reverse_print_list(DB_list*);
void remove_list(DB_list*, int);
void insert_list(DB_list*, int);

int linked_list_main(void)
{
	DB_list data_base = { 0 };

	char menu[255] = { 0 };

	while (1)
	{
		printf("기능을 입력하세요 [입력, 삭제, 출력, 역순출력]\n");
		printf(" : ");
		scanf("%s", menu);

		printf("\n");
		if (strcmp(menu, "출력") == 0)
		{
			printf("출력 선택\n");
			print_list(&data_base);
		}
		else if (strcmp(menu, "역순출력") == 0)
		{
			printf("역순출력 선택\n");
			reverse_print_list(&data_base);
		}
		else if (strcmp(menu, "입력") == 0)
		{
			int n = 0;
			printf("입력 선택 : ");
			scanf("%d", &n);
			printf("\n %d 를 입력하셨습니다.\n", n);
			insert_list(&data_base, n);
		}
		else if (strcmp(menu, "삭제") == 0)
		{
			int n = 0;
			printf("삭제 선택 : ");
			scanf("%d", &n);
			printf("\n %d 를 입력하셨습니다.\n", n);
			remove_list(&data_base, n);

		}
		else
		{
			printf("잘못 선택\n");
		}
	}


	return 0;
}

void print_list(DB_list *db)
{
	list_pointer cur = db->head;
	if (db->number_of_list == 0)
	{
		printf("ERROR[2] : List가 비어있습니다.\n");
		return;
	}
	for (int i = 0; i < db->number_of_list; i++)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}
void reverse_print_list(DB_list *db)
{
	list_pointer cur = db->head;
	int* val_arr = new int[db->number_of_list];
	if (db->number_of_list == 0)
	{
		printf("ERROR[2] : List가 비어있습니다.\n");
		return;
	}

	for (int i = 0; i < db->number_of_list; i++)
	{
		val_arr[db->number_of_list - i - 1] = cur->val;
		cur = cur->next;
	}

	for (int i = 0; i < db->number_of_list; i++)
	{
		printf("%d ", val_arr[i]);
	}
	printf("\n");

}
void remove_list(DB_list *db, int item)
{
	list_pointer cur = db->head;
	list_pointer prev = NULL;
	list_pointer temp = NULL;
	bool removed_flag = 0;
	if (db->number_of_list == 0)
	{
		printf("ERROR[2] : List가 비어있습니다.\n");
		return;
	}
	for (int i = 0; i < db->number_of_list; i++)
	{
		if (cur->val == item)
		{
			if (prev != NULL)
			{
				temp = cur;
				prev->next = cur->next;
				temp = NULL;
				free(temp);
				db->number_of_list--;
				removed_flag = 1;
				break;
			}
			else if (prev == NULL)
			{
				temp = cur;
				db->head = cur->next;
				temp = NULL;
				free(temp);
				db->number_of_list--;
				removed_flag = 1;
				break;
			}
			else if (cur->next == NULL)
			{
				temp = cur;
				prev->next = NULL;
				temp = NULL;
				free(temp);
				db->number_of_list--;
				removed_flag = 1;
				break;
			}

			return;
		}

		prev = cur;
		cur = cur->next;
	}
	if (removed_flag != 1)
	{
		printf("ERROR[]: 데이터가 없습니다.\n");
	}
}
void insert_list(DB_list *db, int value)
{
	list_pointer temp = (list_pointer)malloc(sizeof(linked_list));
	temp->val = value;
	temp->next = NULL;

	if (db->head == NULL)
	{
		db->head = temp;
		db->tail = db->head;
		db->number_of_list = 1;
	}
	else
	{
		list_pointer cur = db->head;
		for (int i = 0; i < db->number_of_list; i++)
		{
			if (cur->val > value && cur == db->head)
			{
				db->head = temp;
				temp->next = cur;
				db->number_of_list++;
				break;
			}
			else if (cur->val == value)
			{
				printf("ERROR[1] : 중복된 데이터 입니다.\n");
				return;
			}
			else if (cur->next == NULL)
			{
				cur->next = temp;
				db->tail = temp;
				db->number_of_list++;
				break;
			}
			else if (cur->val < value && value <= cur->next->val)
			{
				list_pointer next = cur->next;
				cur->next = temp;
				temp->next = next;
				db->number_of_list++;
				break;
			}
			cur = cur->next;
		}
	}
}
