#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

My_list initList()		//��ʼ��������ͷ
{
	ML* L = (ML*)malloc(sizeof(ML));
	if (L == NULL)
	{
		printf("�޷���������");
		return;
	}
	L->next = NULL;
	return L;
}

My_Double_List initDoubleList()		//��ʼ��˫������ͷ
{
	MDL* L = (MDL*)malloc(sizeof(MDL));
	if (L == NULL)
	{
		printf("�޷���������");
		return;
	}
	L->front = NULL;
	L->next = NULL;
	return L;
}

ML* CreateList(ML* head)		//��������
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head;
	int a;
	printf("�������������ݣ�����-1����ֹ���룩��\n");
	scanf("%d", &a);
	while (a != -1)		//a = -1ֹͣ����
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

MDL* CreateDoubleList(MDL* head)		//����˫����
{
	MDL* L = head;
	int a;
	printf("�������������ݣ�����-1����ֹ���룩��\n");
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