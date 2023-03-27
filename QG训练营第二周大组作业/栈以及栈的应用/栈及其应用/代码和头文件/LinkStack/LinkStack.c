#include "LinkStack.h" 
//链栈

//初始化栈
Status initLStack(LinkStack* s) {
	if (s->top != NULL)
	{
		printf("内存中已有链栈！请先销毁！\n");
		return ERROR;
	}
	s->top = (StackNode*)malloc(sizeof(StackNode));
	if (!s->top)
	{
		printf("初始化失败！\n");
		return ERROR;
	}
	s->top->next = NULL;
	s->count = 0;
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (s->count == 0)
		return SUCCESS;
	return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s->top == NULL||s->count ==0)
	{
		printf("链栈尚未创建！");
		return ERROR;
	}
	if (s->top->next == NULL)
	{
		printf("链栈为空！");
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS;
}

//清空栈
Status clearLStack(LinkStack* s) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p = s->top;
	if (p == NULL)
	{
		printf("链栈尚未创建！");
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

//销毁栈
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

//检测栈长度
Status LStackLength(LinkStack* s, int* length) {
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！");
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

//入栈
Status pushLStack(LinkStack* s, ElemType data) {
	if (s->top == NULL)
		return ERROR;
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！");
		system("pause");
		exit(-1);
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}	

//出栈
Status popLStack(LinkStack* s, ElemType* data) {
	if (s->top == NULL){
		printf("链栈尚未创造！\n");
		return ERROR;
	}
	if (s->top->next == NULL){
		printf("链栈为空！\n");
		return ERROR;
	}
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！");
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

//遍历打印链栈
void PrintStack(LinkStack* s)
{
	if (s->top == NULL)
	{
		printf("链栈尚未创建！\n");
		return;
	}
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！");
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