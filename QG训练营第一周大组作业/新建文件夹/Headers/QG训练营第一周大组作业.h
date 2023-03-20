#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
typedef struct MyList		//����ṹ������
{
	int num;
	struct MyList* next;
} ML, * My_list;

typedef struct MyDoubleList		//����ṹ��˫����
{
	struct MyDoubleList* front;
	int num;
	struct MyDoubleList* next;
}MDL, * My_Double_List;


My_list initList();		//��ʼ��������ͷ
ML* CreateList(ML* head);		//��������
void PrintList(ML* head);		//��ӡ������

My_Double_List initDoubleList();	//��ʼ��˫������ͷ
MDL* CreateDoubleList(MDL* head);		//����˫����
void PrintDoubleList(MDL* head);		//��ӡ˫����

My_list InsertList(ML* head, int a);		//������Ĳ���
My_list DeleteList(ML* head, int a);		//�������ɾ��
void DestroyList(My_list* head);		//��������ͷ�
void SearchList(ML* head, int a);		//���������ݲ���

ML* CircleList(ML* head);		//�����ɻ�����

ML* ChangeList(ML* head);		//��ż����

int My_strlen(ML* head);		//����������
int ListMid(ML* head, int len);		//�ҳ������е�Ԫ��

void JudgeList(ML* head);		//�ж������Ƿ�ɻ����ɻ�����0�����ɻ�����1

ML* ReverseList1(ML* head);		//�ݹ鷴ת����
ML* ReverseList2(ML* head);		//�ǵݹ鷴ת����

void menu();