#include <stdio.h>
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


void print_list(DB_list);
void reverse_list(DB_list);
void remove_list(DB_list, int);
void insert_list(DB_list, int);

int linked_list_main(void)
{
	DB_list data_base = { 0 };

	char menu[255] = { 0 };

	while (1)
	{
		printf("����� �Է��ϼ��� [�Է�, ����, ���, �������]\n");
		printf(" : ");
		scanf("%s", menu);

		printf("\n");
		if (strcmp(menu, "���") == 0)
		{
			printf("��� ����\n");
		}
		else if (strcmp(menu, "�������") == 0)
		{
			printf("������� ����\n");
		}
		else if (strcmp(menu, "�Է�") == 0)
		{
			printf("�Է� ����\n");
		}
		else if (strcmp(menu, "����") == 0)
		{
			printf("���� ����\n");
		}
		else
		{
			printf("�߸� ����\n");
		}
	}


	return 0;
}

void print_list(DB_list db)
{

}
void reverse_list(DB_list db)
{

}
void remove_list(DB_list db, int index)
{

}
void insert_list(DB_list db, int value)
{

}
