#include "LinkStack.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack* s) {
	if (s->top != NULL)
	{
		printf("�ڴ���������ջ���������٣�\n");
		return ERROR;
	}
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if (!s->top)
	{
		printf("��ʼ��ʧ�ܣ�\n");
		return ERROR;
	}
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s->count == 0)
		return SUCCESS;
	return ERROR;
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL||s->count ==0)
	{
		printf("��ջ��δ������");
		return ERROR;
	}
	if (s->top->next == NULL)
	{
		printf("��ջΪ�գ�");
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//���ջ
Status clearLStack(LinkStack* s) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p = s->top;
	if (p == NULL)
	{
		printf("��ջ��δ������");
		return ERROR;
	}
	while (p->next != NULL)
	{
		s->top = s->top->next;
		free(p);
		p = s->top;
	}
	return SUCCESS;
}

//����ջ
Status destroyLStack(LinkStack* s) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p = s->top;
	while (p != NULL)
	{
		s->top = s->top->next;
		free(p);
		p = s->top;
	}
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* length) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("ϵͳ�ڴ�������򼴽���ֹ��");
		system("pause");
		exit(-1);
	}
	p = s->top;
	if (p == NULL)
		return ERROR;
	int len = 0;
	while (p->next != NULL)
	{
		p = p->next;
		len++;
	}
	*length = len;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data) {
	if (s->top == NULL)
		return ERROR;
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
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
	return SUCCESS;
}	

//��ջ
Status popLStack(LinkStack* s, ElemType* data) {
	if (s->top == NULL){
		printf("��ջ��δ���죡\n");
		return ERROR;
	}
	if (s->top->next == NULL){
		printf("��ջΪ�գ�\n");
		return ERROR;
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
	return SUCCESS;
}

//������ӡ��ջ
void PrintStack(LinkStack* s)
{
	if (s->top == NULL)
	{
		printf("��ջ��δ������\n");
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
	while (p->next != NULL)
	{
		printf("%d     ", p->data);
		p = p->next;
	}
	printf("\n");
}