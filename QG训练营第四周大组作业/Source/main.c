#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"

void menu() {
	printf("**************************\n");
	printf("********1.��������********\n");
	printf("********2.��������********\n");
	printf("********3.ɾ������********\n");
	printf("********4.�������********\n");
	printf("********5.�������********\n");
	printf("********6.�������********\n");
	printf("********7.��α���********\n");
	printf("********8.��ʼ����********\n");
	printf("******** -1. �˳� ********\n");
	printf("**************************\n");
}
int main() {
	BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	p = BST_init();
	int a = 0;
	int n;
	int num;
	menu();
	printf("��������Ҫ���еĲ�����\n");
	scanf("%d", &a);
	char ch;
	while (a <= 0&&a!=-1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("����������������룡\n");
		scanf("%d", &a);
	}
	while(a!=-1)
	{
		switch (a)
		{
		case 1:
		printf("��������Ҫ�����***��������***����(����-1����)��\n");
		scanf("%d", &n);
		while (n <= 0&&n!=-1)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("����������������룡\n");
			scanf("%d", &n);
		}
		while (n != -1) {
			if (BST_insert(p, n))	printf("����ɹ���\n");
			else printf("����ʧ�ܣ������ֲ�������Ҷ�������\n");
			scanf("%d", &n);	
			while (n <= 0&&n!=-1)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("����������������룡\n");
				scanf("%d", &n);
			}
		}
		break;
		case 2:printf("��������Ҫ�����Ƿ���ڵ����ݣ�\n");
			scanf("%d", &num);		
			while (num <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("����������������룡\n");
				scanf("%d", &num);
			}
			BST_search(p, num);	break;
		case 3:printf("��������Ҫɾ���Ľ�㣺\n");
			scanf("%d", &num);
			while (num <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("����������������룡\n");
				scanf("%d", &num);
			}
			BST_delete(p, num); break;
		case 4:if (p->root == NULL) printf("������Ϊ�գ�\n"); else	BST_preorderR(p->root, Printf_tree); break;
			//if (p->root == NULL) printf("������Ϊ�գ�\n"); else BST_preorderI(p->root, Printf_tree); break;
		case 5:if (p->root == NULL) printf("������Ϊ�գ�\n"); else BST_inorderR(p->root, Printf_tree); break;
			//if (p->root == NULL) printf("������Ϊ�գ�\n"); else BST_inorderI(p->root, Printf_tree); break;
		case 6	:if (p->root == NULL) printf("������Ϊ�գ�\n"); else BST_postorderR(p->root, Printf_tree); break;
			//if (p->root == NULL) printf("������Ϊ�գ�\n"); else BST_postorderI(p->root, Printf_tree); break;
		case 7:
		case 8:p = BST_init(); printf("��ʼ���ɹ������ѱ����!\n"); break;
		default:printf("����������������룡\n");
		}
		system("pause");
		system("cls");
		menu();
		printf("��������Ҫ���еĲ�����\n");
		scanf("%d", &a);
		while (a <= 0&&a!=-1)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("����������������룡\n");
			scanf("%d", &a);
		}
	}
	return 0;
}

//5 3 2 4