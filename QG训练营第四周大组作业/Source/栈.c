#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"

void initLStack(LinkStack* s) {
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if (!s->top)
	{
		printf("³õÊ¼»¯Ê§°Ü£¡\n");
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
		printf("ÏµÍ³ÄÚ´æ³ö´í£¬³ÌĞò¼´½«ÖÕÖ¹£¡");
		system("pause");
		exit(-1);
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return;
}

//³öÕ»
void popLStack(LinkStack* s, int* data) {
	if (s->top == NULL) {
		printf("Á´Õ»ÉĞÎ´´´Ôì£¡\n");
		return;
	}
	if (s->top->next == NULL) {
		printf("Á´Õ»Îª¿Õ£¡\n");
		return;
	}
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("ÏµÍ³ÄÚ´æ³ö´í£¬³ÌĞò¼´½«ÖÕÖ¹£¡");
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
//µÃµ½Õ»¶¥ÔªËØ
void getTopLStack(LinkStack* s,int* data) {
	if (s->top == NULL || s->count == 0)
	{
		printf("Á´Õ»ÉĞÎ´´´½¨£¡");
		return 0;
	}
	if (s->top->next == NULL)
	{
		printf("Á´Õ»Îª¿Õ£¡");
		return 0;
	}
	*data = s->top->data;
	return;
}