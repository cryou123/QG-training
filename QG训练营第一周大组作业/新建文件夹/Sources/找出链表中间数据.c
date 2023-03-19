#define _CRT_SECURE_NO_WARNINGS 1
#include"QG训练营第一周大组作业.h"

int My_strlen(ML* head)		//计算链表长度
{
	int a = 0;
	ML* P = (ML*)malloc(sizeof(ML));
	P = head->next;
	while (P)
	{
		a++;
		P = P->next;
	}
	return a;
}


int ListMid(ML* head, int len)		//运用  len/2  找出中点数据
{
	int a = len / 2;
	ML* P = (ML*)malloc(sizeof(ML));
	P = head->next;
	if (len % 2 == 0)
	{
		while (a != 1)
		{
			P = P->next;
			a--;
		}
	}
	if (len % 2 == 1)
	{
		while (a != 0)
		{
			P = P->next;
			a--;
		}
	}
	return P->num;
}