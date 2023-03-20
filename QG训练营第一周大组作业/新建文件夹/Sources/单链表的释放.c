#define _CRT_SECURE_NO_WARNINGS 1
#include"QG训练营第一周大组作业.h"

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