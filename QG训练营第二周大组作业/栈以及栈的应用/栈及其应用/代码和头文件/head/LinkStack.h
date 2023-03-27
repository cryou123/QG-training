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



//��ջ
Status initLStack(LinkStack* s);//��ʼ��ջ
Status isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack* s, ElemType* e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack* s);//���ջ
Status destroyLStack(LinkStack* s);//����ջ
Status LStackLength(LinkStack* s, int* length);//���ջ����
Status pushLStack(LinkStack* s, ElemType data);//��ջ
Status popLStack(LinkStack* s, ElemType* data);//��ջ

void menu();		//��ӡ�˵�
void PrintStack(LinkStack* s);		//��ӡ��ջ


//---------------------------------------------
//                ջ����������
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
