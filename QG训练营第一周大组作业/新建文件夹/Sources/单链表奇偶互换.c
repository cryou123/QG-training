#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

ML* ChangeList(ML* head)
{
	int tem = 0;		//�����������Ľ���
	ML* L = (ML*)malloc(sizeof(ML));
	L = head;
	while (L->next)
	{
		ML* P = (ML*)malloc(sizeof(ML));
		P = L->next;
		if (L->num % 2 == 1)
		{
			if (P->num % 2 == 0)
			{
				tem = L->num;
				L->num = P->num;
				P->num = tem;
				L = L->next;
				if (L->next == NULL)
				{
					break;
				}
				L = L->next;
				continue;
			}
		}
		if (L->num % 2 == 0)
		{
			if (P->num % 2 == 1)
			{
				tem = L->num;
				L->num = P->num;
				P->num = tem;
				L = L->next;
				if (L->next == NULL)
				{
					break;
				}
				L = L->next;
				continue;
			}
		}
		L = L->next;
	}
	return head;
}