#define _CRT_SECURE_NO_WARNINGS 1
#include"QG训练营第一周大组作业.h"

void SearchList(ML* head, int a)
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head->next;
	int step = 1;
	while (L != NULL)
	{
		if (L->num == a)
		{
			printf("链表中有该数字，所在结点位置为：%d\n", step);
			return;
		}
		L = L->next;
		step++;
	}
	printf("链表中没有该数字！\n");
	return;
}