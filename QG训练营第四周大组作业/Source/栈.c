#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"

void initLStack(LinkStack* s) {
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if (!s->top)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		exit(-1);
	}
	s->top->next = NULL;
	s->top->site = 0;
	s->count = 0;
}

void pushLStack(LinkStack* s, int data) {
	if (s->top == NULL)
		return;
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->site = 0;
	if (p == NULL)
	{
		printf("ϵͳ�ڴ�������򼴽���ֹ��");
		system("pause");
		exit(-1);
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return;
}

//��ջ
void popLStack(LinkStack* s, int* data) {
	if (s->top == NULL) {
		printf("��ջ��δ���죡\n");
		return;
	}
	if (s->top->next == NULL) {
		printf("��ջΪ�գ�\n");
		return;
	}
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("ϵͳ�ڴ�������򼴽���ֹ��");
		system("pause");
		exit(-1);
	}
	p = s->top;
	*data = p->data;
	s->top = p->next;
	free(p);
	s->count--;
	return;
}

int isEmptyLStack(LinkStack* s) {
	if (s->count == 0)
		return 1;
	return 0;
}
//�õ�ջ��Ԫ��
void getTopLStack(LinkStack* s,int* data) {
	if (s->top == NULL || s->count == 0)
	{
		printf("��ջ��δ������");
		return 0;
	}
	if (s->top->next == NULL)
	{
		printf("��ջΪ�գ�");
		return 0;
	}
	*data = s->top->data;
	return;
}