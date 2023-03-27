#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkStack.h"

char tem[1024] = {0};
void char_put(char ch)
{
	static int step = 0;
	tem[step] = ch;
	step++;
}

Status is_empty(CLinkStack*s)
{
	if (s->top == NULL)
	{
		return SUCCESS;
	}
	return ERROR;
}

CStackNode* CgetTopLStack(CLinkStack* s) {		//��ȡջ�����
	if (s->count == 0)
	{
		printf("��ô����������أ�\n");
		return NULL;
	}
	return s->top;
}

void CpushLStack(CLinkStack* s, char ch) {		//��ջ
	CStackNode* p = (CStackNode*)malloc(sizeof(CStackNode));
	if (p == NULL)
	{
		printf("ϵͳ�ڴ�������򼴽���ֹ��\n");
		system("pause");
		exit(-1);
	}
	p->data = ch;
	p->next = s->top;
	s->top = p;
	s->count++;
}

CStackNode* CpopLStack(CLinkStack* s) {			//��ջ
	if (s->top == NULL) {
		printf("��ջΪ�գ�\n");
		exit(-1);
	}

	CStackNode* p = (CStackNode*)malloc(sizeof(CStackNode));
	if (p == NULL)
	{
		printf("ϵͳ�ڴ�������򼴽���ֹ��\n");
		system("pause");
		exit(-1);
	}
	p = s->top;
	s->top = p->next;
	s->count--;
	return p;
}

int prior(char ch){		//�Ƚ����ȼ�
	int ret = 0;
	switch (ch)
	{
	case'+':
	case'-':
		ret = 1;
		break;
	case'*':
	case'/':
		ret = 2;
		break;
	default:
		break;
	}
	return ret;
}

//�жϸ�λ��Ϊ����Ԫ��
int is_num(char ch) {
	return (ch >= '0' && ch <= '9');
}
int is_operation(char ch) {
	return(ch == '+' || ch == '-' || ch == '*' || ch == '/)');
}
int is_left(char ch) {
	if (ch == '(')
		return 1;
	else
		return 0;
}
int is_right(char ch) {
	if (ch == ')')
		return 1;
	else
		return 0;
}

Status transform(char str[]) {			//������ꡱ��ʽ����ꡱ��ʽ��ת��
	CLinkStack* s = (CLinkStack*)malloc(sizeof(CLinkStack));
	s->top = NULL;
	s->count = 0;
	int i = 0;
	while (str[i] != '\0')		//��������
	{
		if(is_num(str[i])==1){
			if (is_num(str[i + 1]) == 1){
				char_put(str[i]);
			}
			else {
				char_put(str[i]);
				char_put(' ');
			}
		}
		else if (is_operation(str[i]) == 1){
			if (str[i + 1] == '0' && str[i] == '/') {
				printf("���Ϸ����룡\n");
				return ERROR;
			}
			while(is_empty(s) == '0' && (prior(str[i]) <= prior(CgetTopLStack(s)->next))) 
			{
				char_put(CpopLStack(s)->data);
				char_put(' ');
			}
			CpushLStack(s, str[i]);
		}
		else if (is_left(str[i]) == 1){
			CpushLStack(s, str[i]);
		}
		else if (is_right(str[i]) == 1) {
			while (is_left(CgetTopLStack(s)->data) != 1)		//���������������ż�ķ��ų�ջ��������
			{
				char_put(CpopLStack(s)->data);
				if (CgetTopLStack == NULL)
				{
					printf("δ�ҵ���������������ƥ�䣡\n");
					return ERROR;
				}
			}
			CpopLStack(s);		//�ҵ������ź��������ų�ջ
		}
		else {
			printf("���Ϸ����룡\n");
			return ERROR;
		}
		i++;
	}
	if (str[i] == '\0') {		//������ϣ���ջȫ���˳�
		while (!is_empty(s))
		{
			if (CgetTopLStack(s)->data == '(') {
				printf("δ�ҵ���������������ƥ�䣡\n");
				return 0;
			}
			char_put(CpopLStack(s)->data);
		}
	}
	else
		printf("����û����ɣ�\n");
	return 1;
}

//-----------------------------���濪ʼ���к�׺���ʽ������

Status is_empty2(CLinkStack2* s)
{
	if (s->top == NULL)
	{
		return SUCCESS;
	}
	return ERROR;
}

int CgetTopLStack2(CLinkStack2* s) {		//��ȡջ��Ԫ��
	if (s->count == 0)
	{
		printf("��ô����������أ�\n");
		return NULL;
	}
	return s->top->data;
}

void CpushLStack2(CLinkStack2* s, int a) {		//��ջ
	CStackNode2* p = (CStackNode2*)malloc(sizeof(CStackNode2));
	if (p == NULL)
	{
		printf("ϵͳ�ڴ�������򼴽���ֹ��\n");
		system("pause");
		exit(-1);
	}
	p->data = a;
	p->next = s->top;
	s->top = p;
	s->count++;
}

int CpopLStack2(CLinkStack2* s) {			//��ջ
	if (s->top == NULL) {
		printf("��ջΪ�գ�\n");
		exit(-1);
	}
	CStackNode2* p = (CStackNode2*)malloc(sizeof(CStackNode2));
	if (p == NULL)
	{
		printf("ϵͳ�ڴ�������򼴽���ֹ��\n");
		system("pause");
		exit(-1);
	}
	p = s->top;
	s->top = p->next;
	s->count--;
	return p->data;
}

//������������
int cul(int left, int right, char ch){
		switch (ch)
		{
		case'+':
			return left + right;
		case'-':
			return left-right;
		case'*':
			return left * right;
		case'/':
			return left / right;
		default:
			break;
		}
		return -1;
}

int culculate(char tem[]){
	CLinkStack2* s = (CLinkStack2*)malloc(sizeof(CLinkStack));
	s->top = NULL;
	s->count = 0;
	int i = 0;
	while (tem[i] != '\0')
	{
		char index[5] = { 0 };
		int step = 0;
		if (is_num(tem[i]) == 1) {
			while (is_num(tem[i]) == 1)
			{
				index[step] = tem[i];
				step++;
				i++;
			}
			CpushLStack2(s, atoi(index));		//��������ջ
		}
		else if (is_operation(tem[i]) == 1)
		{
			int right = CpopLStack2(s);
			int left = CpopLStack2(s);
			int ret = cul(left, right, tem[i]);
			CpushLStack2(s, ret);
		}
		i++;
	}
	return CgetTopLStack2(s);
}