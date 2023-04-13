#define _CRT_SECURE_NO_WARNINGS 1
#include"tree.h"

void menu() {
	printf("**************************\n");
	printf("********1.插入数据********\n");
	printf("********2.查找数据********\n");
	printf("********3.删除数据********\n");
	printf("********4.先序遍历********\n");
	printf("********5.中序遍历********\n");
	printf("********6.后序遍历********\n");
	printf("********7.层次遍历********\n");
	printf("********8.初始化树********\n");
	printf("******** -1. 退出 ********\n");
	printf("**************************\n");
}
int main() {
	BinarySortTreePtr p = (BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	p = BST_init();
	int a = 0;
	int n;
	int num;
	menu();
	printf("请输入你要进行的操作：\n");
	scanf("%d", &a);
	char ch;
	while (a <= 0&&a!=-1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("输入错误，请重新输入！\n");
		scanf("%d", &a);
	}
	while(a!=-1)
	{
		switch (a)
		{
		case 1:
		printf("请输入你要插入的***正数整数***数据(输入-1结束)：\n");
		scanf("%d", &n);
		while (n <= 0&&n!=-1)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("输入错误，请重新输入！\n");
			scanf("%d", &n);
		}
		while (n != -1) {
			if (BST_insert(p, n))	printf("插入成功！\n");
			else printf("插入失败！该数字不满足查找二叉树！\n");
			scanf("%d", &n);	
			while (n <= 0&&n!=-1)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("输入错误，请重新输入！\n");
				scanf("%d", &n);
			}
		}
		break;
		case 2:printf("请输入你要查找是否存在的数据：\n");
			scanf("%d", &num);		
			while (num <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("输入错误，请重新输入！\n");
				scanf("%d", &num);
			}
			BST_search(p, num);	break;
		case 3:printf("请输入你要删除的结点：\n");
			scanf("%d", &num);
			while (num <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("输入错误，请重新输入！\n");
				scanf("%d", &num);
			}
			BST_delete(p, num); break;
		case 4:if (p->root == NULL) printf("二叉树为空！\n"); else	BST_preorderR(p->root, Printf_tree); break;
			//if (p->root == NULL) printf("二叉树为空！\n"); else BST_preorderI(p->root, Printf_tree); break;
		case 5:if (p->root == NULL) printf("二叉树为空！\n"); else BST_inorderR(p->root, Printf_tree); break;
			//if (p->root == NULL) printf("二叉树为空！\n"); else BST_inorderI(p->root, Printf_tree); break;
		case 6	:if (p->root == NULL) printf("二叉树为空！\n"); else BST_postorderR(p->root, Printf_tree); break;
			//if (p->root == NULL) printf("二叉树为空！\n"); else BST_postorderI(p->root, Printf_tree); break;
		case 7:
		case 8:p = BST_init(); printf("初始化成功！树已被清空!\n"); break;
		default:printf("输入错误！请重新输入！\n");
		}
		system("pause");
		system("cls");
		menu();
		printf("请输入你要进行的操作：\n");
		scanf("%d", &a);
		while (a <= 0&&a!=-1)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("输入错误，请重新输入！\n");
			scanf("%d", &a);
		}
	}
	return 0;
}

//5 3 2 4