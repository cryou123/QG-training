#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "QGѵ��Ӫ��һ�ܴ�����ҵ.h"

int main()
{
	printf("1.��������and˫������Ĵ���\n");
	ML* head = initList();
	MDL* DoubleHead = initDoubleList();
	int b = 0;
	while (b != -1)
	{
		menu();
		printf("����������еĲ���:\n");
		scanf("%d", &b);
		if (b == 1)  CreateList(head); 
		if (b == 2) { DestroyList(&head); head = initList();}
		if (b == 3) { printf("���������������ݣ�\n"); int c = 0; scanf("%d", &c); head = InsertList(head, c); }
		if (b == 4) { printf("��������ɾ�������ݣ�\n"); int c = 0; scanf("%d", &c); head = DeleteList(head, c); }
		if (b == 5) { printf("����������ҵ����ݣ�\n"); int c = 0; scanf("%d", &c); SearchList(head,c); }
		PrintList(head);
		system("pause");
	}
	system("cls");
	//CreateDoubleList(DoubleHead);
	//PrintDoubleList(DoubleHead);

	printf("\n2.��������ż����\n");
	//ע�����Ϊ����ż�������ʱ�򻥻�,����a>0,����һ����ֻ�ᱻ����һ�Σ���1  2  2����2  1  2 ������2  2  1��
	head = initList();
	head = CreateList(head);
	printf("����ǰ������:\n");
	PrintList(head);
	printf("�����������:\n");
	head = ChangeList(head);
	PrintList(head);
	system("pause");
	system("cls");
	
	printf("\n3.�ҵ���������е�\n");
	//ע�������鳤��Ϊż�������ҳ�ǰһλ��������1��2��3��1���ҳ�2
	head = initList();
	head = CreateList(head);
	PrintList(head);
	int len = My_strlen(head);
	printf("������Ϊ:");
	printf("%d\n", len);
	int Mid_num = ListMid(head,len);
	printf("������е�����Ϊ:%d\n", Mid_num);
	system("pause");
	system("cls");

	printf("\n4.�ж������Ƿ�Ϊ��\n");
	//ע���ɻ�or���ɻ��ö�ѡһ���ҳɻ���㲻��Ϊ0�����������
	head = initList();
	int a = 0;
	printf("ѡ����Ҫ������������ͣ�0Ϊ���ɻ�����1Ϊ�ɻ�������");
	scanf("%d", &a);
	if(a==0)
		head = CreateList(head);		//���첻�ɻ�����
	if(a==1)
		head = CircleList(head);		//����ɻ�����
	JudgeList(head);
	system("pause");
	system("cls");

	printf("\n5.��ת����\n");
	head = initList();
	head = CreateList(head);
	printf("�������Ƿ�ѡ��ݹ鷴ת��0Ϊ��ѡ��1Ϊѡ�񣩣�");
	scanf("%d", &a);
	if(a == 1)
		head = ReverseList1(head);
	if(a == 0)
		head = ReverseList2(head);
	printf("��ת�������Ϊ��");
	PrintList(head);

	return 0;
}