#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

void PrintList(ML* head)		//��ӡ������
{
	if (head->next == NULL)
	{
		printf("����Ϊ��");
		return;
	}
	ML* L = (ML*)malloc(sizeof(ML));
	printf("�������������£�");
	L = head->next;
	while (L)
	{
		printf("%5d", L->num);
		L = L->next;
	}
	printf("\n");
	return;
}

void PrintDoubleList(MDL* head)		//��ӡ˫����
{
	if (head->next == NULL)
	{
		printf("����Ϊ��");
		return;
	}
	MDL* L = (ML*)malloc(sizeof(ML));
	L = head->next;
	printf("˫�����������£�");
	while (L)
	{
		printf("%5d", L->num);
		L = L->next;
	}
	return;
}