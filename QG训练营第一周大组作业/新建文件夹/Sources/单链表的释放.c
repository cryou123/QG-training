#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

void DestroyList(My_list* head)
{
	My_list P;
	P = *head;
	while (*head != NULL)
	{
		P = *head;
		*head = P->next;
		free(P);
	}
}