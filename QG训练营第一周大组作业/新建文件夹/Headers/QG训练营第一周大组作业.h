#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct MyList		//创造结构体链表
{
	int num;
	struct MyList* next;
} ML, * My_list;

typedef struct MyDoubleList		//创造结构体双链表
{
	struct MyDoubleList* front;
	int num;
	struct MyDoubleList* next;
}MDL, * My_Double_List;


My_list initList();		//初始化单链表头
ML* CreateList(ML* head);		//单链表创建
void PrintList(ML* head);		//打印单链表

My_Double_List initDoubleList();	//初始化双向链表头
MDL* CreateDoubleList(MDL* head);		//创建双链表
void PrintDoubleList(MDL* head);		//打印双链表

My_list InsertList(ML* head, int a);		//单链表的插入
My_list DeleteList(ML* head, int a);		//单链表的删除
void DestroyList(My_list* head);		//单链表的释放
void SearchList(ML* head, int a);		//单链表数据查找

ML* CircleList(ML* head);		//创建成环链表

ML* ChangeList(ML* head);		//奇偶互换

int My_strlen(ML* head);		//计算链表长度
int ListMid(ML* head, int len);		//找出链表中点元素

void JudgeList(ML* head);		//判断链表是否成环，成环返回0，不成环返回1

ML* ReverseList1(ML* head);		//递归反转链表
ML* ReverseList2(ML* head);		//非递归反转链表

void menu();