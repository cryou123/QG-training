#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

void PrintList(ML* head)		//��ӡ������
{
	if (head == NULL||head->next == NULL)
	{
		printf("����Ϊ��\n");
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
		printf("����Ϊ��\n");
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

void menu()
{
	system("cls");
	printf("\t\t**************************\n");
	printf("\t\t********1.��������********\n");
	printf("\t\t********2.�ͷ�����********\n");
	printf("\t\t********3.��������********\n");
	printf("\t\t********4.ɾ������********\n");
	printf("\t\t********5.��������********\n");
	printf("\t\t**********-1.����*********\n");
	printf("\t\t**************************\n");
}