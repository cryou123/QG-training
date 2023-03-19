#define _CRT_SECURE_NO_WARNINGS 1
#include"QG训练营第一周大组作业.h"

ML* ReverseList1(ML* head)		//递归反转链表
{
	if (head->next == NULL || head->next->next == NULL)
		return head;
	int len = My_strlen(head);
	ML* L = (ML*)malloc(sizeof(ML));
	ML* P = (ML*)malloc(sizeof(ML));
	P = L;
	while (len)
	{
		ML* M = (ML*)malloc(sizeof(ML));
		ML* R = (ML*)malloc(sizeof(ML));
		R = head->next;
		for (int i = 0; i < len - 1; i++)
		{
			R = R->next;
		}
		M->num = R->num;
		M->next = NULL;
		P->next = M;
		P = P->next;
		len--;
	}
	return L;
}

ML* ReverseList2(ML* head)		//非递归反转链表，L跑的比R快一步
{
	ML* L = (ML*)malloc(sizeof(ML));
	ML* R = (ML*)malloc(sizeof(ML));
	if (head->next == NULL || head->next->next == NULL)	//空链表不需要反转
		return head;
	L = head->next;
	L = L->next;
	R = head->next;
	while (L->next != NULL)
	{
		ML* P = (ML*)malloc(sizeof(ML));
		P = R;
		//printf("%d ", R->num);
		R = L;
		L = L->next;
		R->next = P;

	}
	L->next = R;
	head->next->next = NULL;
	head->next = L;
	//printf("\n%d %d %d\n", R->next->num, R->num, L->num);
	//head->next = NULL;
	return head;
}