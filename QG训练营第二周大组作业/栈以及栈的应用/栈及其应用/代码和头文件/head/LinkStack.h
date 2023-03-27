#pragma once
#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;



//链栈
Status initLStack(LinkStack* s);//初始化栈
Status isEmptyLStack(LinkStack* s);//判断栈是否为空
Status getTopLStack(LinkStack* s, ElemType* e);//得到栈顶元素
Status clearLStack(LinkStack* s);//清空栈
Status destroyLStack(LinkStack* s);//销毁栈
Status LStackLength(LinkStack* s, int* length);//检测栈长度
Status pushLStack(LinkStack* s, ElemType data);//入栈
Status popLStack(LinkStack* s, ElemType* data);//出栈

void menu();		//打印菜单
void PrintStack(LinkStack* s);		//打印链栈


//---------------------------------------------
//                栈的四则运算
typedef  struct CStackNode
{
	char data;
	struct CStackNode* next;
}CStackNode, * CLinkStackPtr;

typedef  struct	CLinkStack
{
	CLinkStackPtr top;
	int	count;
}CLinkStack;

typedef  struct CStackNode2
{
	int data;
	struct CStackNode2* next;
}CStackNode2, * CLinkStackPtr2;

typedef  struct	CLinkStack2
{
	CLinkStackPtr2 top;
	int	count;
}CLinkStack2;

void char_put(char ch);
Status is_empty(CLinkStack* s);
CStackNode* CgetTopLStack(CLinkStack* s);
void CpushLStack(CLinkStack* s, char ch);
CStackNode* CpopLStack(CLinkStack* s);
int prior(char ch);
Status transform(char str[]);
int culculate(char tem[]);

#endif
