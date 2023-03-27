#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkStack.h"
extern char tem[1024];

void menu()
{
	printf("\t\t\t****1.初始化链栈****\n");
	printf("\t\t\t***2.得到栈顶元素***\n");
	printf("\t\t\t*****3.清空链栈*****\n");
	printf("\t\t\t*****4.销毁链栈*****\n");
	printf("\t\t\t***5.获取链栈长度***\n");
	printf("\t\t\t*****6.入栈一位*****\n");
	printf("\t\t\t*****7.出栈一位*****\n");
	printf("\t\t\t*****8.打印链栈*****\n");
	printf("\t\t\t**** -1.退出程序****\n");
}
int main()
{
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = NULL;
	menu();
	printf("请输入你想要进行的操作:\n");
	int a = 0;
	scanf("%d", &a);
	char ch;
	while (a <= 0&&a!=-1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("请输入正确的数字:\n");
		scanf("%d", &a);
	}
	while(a!=-1)
	{
		if (a == 1) {
			if (initLStack(s))
				printf("初始化链栈成功！\n");
			system("pause");
			system("cls");
		}
		if (a == 2) {
			int b = 0;
			if (getTopLStack(s, b))
				printf("栈顶元素为：%d\n", b);
			system("pause");
			system("cls");
		}
		if (a == 3) {
			if (clearLStack(s))
				printf("完成操作！链栈已清空！\n");
			system("pause");
			system("cls");
		}
		if (a == 4) {
			if (destroyLStack(s))
				printf("完成操作！链栈已销毁！\n");
			system("pause");
			system("cls");
		}
		if (a == 5) {
			int b = 0;
			if (LStackLength(s, &b))
				printf("链栈长度为：%d\n", b);
			else
				printf("链栈尚未创建!\n");
			system("pause");
			system("cls");
		}	
		if (a == 6) {
			printf("请输入想要入栈的元素(输入格式为非零正整数)：\n");
			int b = 0;
			scanf("%d", &b);
			while (b <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("请输入正确的数字:\n");
				scanf("%d", &b);
			}
			if (pushLStack(s, b)) {
				printf("入栈成功！\n");
				printf("当前链栈为:");
				PrintStack(s);
			}
			else
				printf("链栈尚未创建!\n");
			//printf("\n%d", s->count);
			system("pause");
			system("cls");
		}	
		if (a == 7) {
			int b = 0;
			if (popLStack(s, &b)) {
				printf("出栈成功！\n");
				printf("出栈元素为：%d\n", b);
			}
			system("pause");
			system("cls");
		}
		if (a == 8) {
			printf("当前链栈为(左边为栈尾):\n");
			PrintStack(s);
			system("pause");
			system("cls");
		}
		menu();
		printf("请输入你想要进行的操作:\n");
		scanf("%d", &a);
		while (a <= 0 && a != -1)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("请输入正确的数字:\n");
			scanf("%d", &a);
		}
	}
	system("cls");
	printf("哈哈哈哈给骗了吧！接下来开始栈的四则运算辣！\n");
	system("pause");
	system("cls");
	char str[1024] = { 0 };
	printf("输入表达式：\n");
	scanf("%s", str);
	int result = transform(str);
	if (result == 0)	{
		printf("表达式都能输歪来！不给你玩辣");
	}
	else {
		printf("桀桀桀，既然你诚心的输入了，那本大人就大发慈悲的给你转换一下吧！\n");
		printf("转化后的表达式为：%s\n", tem);
		printf("聪明的我顺便帮你算一下结果：%d\n", culculate(tem));
	}
	return 0;
}