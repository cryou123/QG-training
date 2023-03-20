#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "QG训练营第一周大组作业.h"

int main()
{
	printf("1.单向链表and双向链表的创建\n");
	ML* head = initList();
	MDL* DoubleHead = initDoubleList();
	int b = 0;
	while (b != -1)
	{
		menu();
		printf("输入你想进行的操作:\n");
		scanf("%d", &b);
		if (b == 1)  CreateList(head); 
		if (b == 2) { DestroyList(&head); head = initList();}
		if (b == 3) { printf("输入你想插入的数据：\n"); int c = 0; scanf("%d", &c); head = InsertList(head, c); }
		if (b == 4) { printf("输入你想删除的数据：\n"); int c = 0; scanf("%d", &c); head = DeleteList(head, c); }
		if (b == 5) { printf("输入你想查找的数据：\n"); int c = 0; scanf("%d", &c); SearchList(head,c); }
		PrintList(head);
		system("pause");
	}
	system("cls");
	//CreateDoubleList(DoubleHead);
	//PrintDoubleList(DoubleHead);

	printf("\n2.单链表奇偶互换\n");
	//注：理解为有奇偶数相隔的时候互换,输入a>0,并且一个数只会被交换一次（即1  2  2会变成2  1  2 而不是2  2  1）
	head = initList();
	head = CreateList(head);
	printf("互换前的数据:\n");
	PrintList(head);
	printf("互换后的数据:\n");
	head = ChangeList(head);
	PrintList(head);
	system("pause");
	system("cls");
	
	printf("\n3.找到单链表的中点\n");
	//注：若数组长度为偶数，则找出前一位数，即（1，2，3，1）找出2
	head = initList();
	head = CreateList(head);
	PrintList(head);
	int len = My_strlen(head);
	printf("链表长度为:");
	printf("%d\n", len);
	int Mid_num = ListMid(head,len);
	printf("链表的中点数据为:%d\n", Mid_num);
	system("pause");
	system("cls");

	printf("\n4.判断链表是否为环\n");
	//注：成环or不成环得二选一，且成环结点不可为0或大于链表本身
	head = initList();
	int a = 0;
	printf("选择你要输入的链表类型（0为不成环链表，1为成环链表）：");
	scanf("%d", &a);
	if(a==0)
		head = CreateList(head);		//创造不成环链表
	if(a==1)
		head = CircleList(head);		//创造成环链表
	JudgeList(head);
	system("pause");
	system("cls");

	printf("\n5.反转链表\n");
	head = initList();
	head = CreateList(head);
	printf("请输入是否选择递归反转（0为不选择，1为选择）：");
	scanf("%d", &a);
	if(a == 1)
		head = ReverseList1(head);
	if(a == 0)
		head = ReverseList2(head);
	printf("反转后的链表为：");
	PrintList(head);

	return 0;
}