#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

My_list InsertList(ML* head,int a)
{
	ML* L = head;
	while (L->next != NULL)
	{
		L = L->next;
	}
	ML* P = (ML*)malloc(sizeof(ML));
	P->num = a;
	P->next = NULL;
	L->next = P;
	return head;
}

My_list DeleteList(ML* head,int a)
{
	ML* L = head;
	ML* P = (ML*)malloc(sizeof(ML));
	P = L;
	while (L->num != a)
	{
		P = L;
		L = L->next;
		if (L == NULL)
		{
			printf("δ�ҵ�������\n");
			return head;
		}
	}
	P->next = L->next;
	return head;
}