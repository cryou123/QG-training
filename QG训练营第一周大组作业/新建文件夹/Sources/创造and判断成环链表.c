#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

ML* CircleList(ML* head)		//����ɻ�����
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head;
	int b = 0;
	printf("ѡ����Ҫ�ɻ��Ľ��λ�ã����λ�ò���С��1��:\n");
	scanf("%d", &b);
	int a = 0;
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
	ML* P = (ML*)malloc(sizeof(ML));	//���ɻ�����ҳ�������ԭ��β����ָ��ý��
	P = head->next;
	while (b != 1)
	{
		P = P->next;
		b--;
	}
	L->next = P;
	return head;
}

void JudgeList(ML* head)		//�ж������Ƿ�ɻ�
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head->next;		//��һ��
	ML* R = (ML*)malloc(sizeof(ML));
	R = head->next;		//������
	while (R)
	{
		L = L->next;
		R = R->next;
		if (R == NULL)
		{
			printf("�����ɻ�");
			return;
		}
		R = R->next;
		if (R == L)
		{
			printf("����ɻ�");
			return;
		}
	}
	printf("�����ɻ�");
	return;
}