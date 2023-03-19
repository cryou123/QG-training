#define _CRT_SECURE_NO_WARNINGS 1
#include"QG训练营第一周大组作业.h"

My_list initList()		//初始化单链表头
{
	ML* L = (ML*)malloc(sizeof(ML));
	if (L == NULL)
	{
		printf("无法创造链表");
		return;
	}
	L->next = NULL;
	return L;
}

My_Double_List initDoubleList()		//初始化双向链表头
{
	MDL* L = (MDL*)malloc(sizeof(MDL));
	if (L == NULL)
	{
		printf("无法创造链表");
		return;
	}
	L->front = NULL;
	L->next = NULL;
	return L;
}

ML* CreateList(ML* head)		//单链表创建
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head;
	int a;
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
	L->next = NULL;
	return head;
}

MDL* CreateDoubleList(MDL* head)		//创建双链表
{
	MDL* L = head;
	int a;
	printf("请输入链表数据（输入-1即中止输入）：\n");
	scanf("%d", &a);
	while (a != -1)
	{
		MDL* R = (MDL*)malloc(sizeof(MDL));
		R->front = NULL;
		R->next = NULL;
		R->num = a;
		L->next = R;
		R->front = L;
		L = L->next;
		scanf("%d", &a);
	}
	L->next = NULL;
}