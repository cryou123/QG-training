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

CStackNode* CgetTopLStack(CLinkStack* s) {		//获取栈顶结点
	if (s->count == 0)
	{
		printf("怎么不输入符号呢！\n");
		return NULL;
	}
	return s->top;
}

void CpushLStack(CLinkStack* s, char ch) {		//入栈
	CStackNode* p = (CStackNode*)malloc(sizeof(CStackNode));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！\n");
		system("pause");
		exit(-1);
	}
	p->data = ch;
	p->next = s->top;
	s->top = p;
	s->count++;
}

CStackNode* CpopLStack(CLinkStack* s) {			//出栈
	if (s->top == NULL) {
		printf("链栈为空！\n");
		exit(-1);
	}

	CStackNode* p = (CStackNode*)malloc(sizeof(CStackNode));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！\n");
		system("pause");
		exit(-1);
	}
	p = s->top;
	s->top = p->next;
	s->count--;
	return p;
}

int prior(char ch){		//比较优先级
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

//判断该位置为何种元素
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

Status transform(char str[]) {			//进行中辍表达式到后辍表达式的转化
	CLinkStack* s = (CLinkStack*)malloc(sizeof(CLinkStack));
	s->top = NULL;
	s->count = 0;
	int i = 0;
	while (str[i] != '\0')		//遍历数组
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
				printf("不合法输入！\n");
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
			while (is_left(CgetTopLStack(s)->data) != 1)		//将左括号与右括号间的符号出栈进入数组
			{
				char_put(CpopLStack(s)->data);
				if (CgetTopLStack == NULL)
				{
					printf("未找到左括号与右括号匹配！\n");
					return ERROR;
				}
			}
			CpopLStack(s);		//找到左括号后让左括号出栈
		}
		else {
			printf("不合法输入！\n");
			return ERROR;
		}
		i++;
	}
	if (str[i] == '\0') {		//遍历完毕，将栈全部退出
		while (!is_empty(s))
		{
			if (CgetTopLStack(s)->data == '(') {
				printf("未找到右括号与左括号匹配！\n");
				return 0;
			}
			char_put(CpopLStack(s)->data);
		}
	}
	else
		printf("遍历没有完成！\n");
	return 1;
}

//-----------------------------下面开始进行后缀表达式的运算

Status is_empty2(CLinkStack2* s)
{
	if (s->top == NULL)
	{
		return SUCCESS;
	}
	return ERROR;
}

int CgetTopLStack2(CLinkStack2* s) {		//获取栈顶元素
	if (s->count == 0)
	{
		printf("怎么不输入符号呢！\n");
		return NULL;
	}
	return s->top->data;
}

void CpushLStack2(CLinkStack2* s, int a) {		//入栈
	CStackNode2* p = (CStackNode2*)malloc(sizeof(CStackNode2));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！\n");
		system("pause");
		exit(-1);
	}
	p->data = a;
	p->next = s->top;
	s->top = p;
	s->count++;
}

int CpopLStack2(CLinkStack2* s) {			//出栈
	if (s->top == NULL) {
		printf("链栈为空！\n");
		exit(-1);
	}
	CStackNode2* p = (CStackNode2*)malloc(sizeof(CStackNode2));
	if (p == NULL)
	{
		printf("系统内存出错，程序即将终止！\n");
		system("pause");
		exit(-1);
	}
	p = s->top;
	s->top = p->next;
	s->count--;
	return p->data;
}

//进行四则运算
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
			CpushLStack2(s, atoi(index));		//整个数入栈
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