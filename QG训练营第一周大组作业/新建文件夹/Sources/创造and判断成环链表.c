#define _CRT_SECURE_NO_WARNINGS 1
#include"QG训练营第一周大组作业.h"

ML* CircleList(ML* head)		//创造成环链表
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head;
	int b = 0;
	printf("选择你要成环的结点位置（结点位置不可小于1）:\n");
	scanf("%d", &b);
	int a = 0;
	printf("请输入链表数据（输入-1即中止输入）：\n");
	scanf("%d", &a);
	while (a != -1)		//a = -1停止创建
	{
		ML* R = (ML*)malloc(sizeof(ML));
		R->num = a;
		L->next = R;
		L = L->next;
		scanf("%d", &a);
	}
	ML* P = (ML*)malloc(sizeof(ML));	//将成环结点找出，并用原本尾链表指向该结点
	P = head->next;
	while (b != 1)
	{
		P = P->next;
		b--;
	}
	L->next = P;
	return head;
}

void JudgeList(ML* head)		//判断链表是否成环
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head->next;		//走一步
	ML* R = (ML*)malloc(sizeof(ML));
	R = head->next;		//走两步
	while (R)
	{
		L = L->next;
		R = R->next;
		if (R == NULL)
		{
			printf("链表不成环");
			return;
		}
		R = R->next;
		if (R == L)
		{
			printf("链表成环");
			return;
		}
	}
	printf("链表不成环");
	return;
}