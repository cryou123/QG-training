#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

int My_strlen(ML* head)		//����������
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


int ListMid(ML* head, int len)		//����  len/2  �ҳ��е�����
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