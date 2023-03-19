#define _CRT_SECURE_NO_WARNINGS 1
#include"QG训练营第一周大组作业.h"

void PrintList(ML* head)		//打印单链表
{
	if (head->next == NULL)
	{
		printf("链表为空");
		return;
	}
	ML* L = (ML*)malloc(sizeof(ML));
	printf("单链表数据如下：");
	L = head->next;
	while (L)
	{
		printf("%5d", L->num);
		L = L->next;
	}
	printf("\n");
	return;
}

void PrintDoubleList(MDL* head)		//打印双链表
{
	if (head->next == NULL)
	{
		printf("链表为空");
		return;
	}
	MDL* L = (ML*)malloc(sizeof(ML));
	L = head->next;
	printf("双链表数据如下：");
	while (L)
	{
		printf("%5d", L->num);
		L = L->next;
	}
	return;
}