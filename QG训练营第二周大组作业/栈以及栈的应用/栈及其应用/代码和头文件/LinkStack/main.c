#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkStack.h"
extern char tem[1024];

void menu()
{
	printf("\t\t\t****1.��ʼ����ջ****\n");
	printf("\t\t\t***2.�õ�ջ��Ԫ��***\n");
	printf("\t\t\t*****3.�����ջ*****\n");
	printf("\t\t\t*****4.������ջ*****\n");
	printf("\t\t\t***5.��ȡ��ջ����***\n");
	printf("\t\t\t*****6.��ջһλ*****\n");
	printf("\t\t\t*****7.��ջһλ*****\n");
	printf("\t\t\t*****8.��ӡ��ջ*****\n");
	printf("\t\t\t**** -1.�˳�����****\n");
}
int main()
{
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	s->top = NULL;
	s->count = NULL;
	menu();
	printf("����������Ҫ���еĲ���:\n");
	int a = 0;
	scanf("%d", &a);
	char ch;
	while (a <= 0&&a!=-1)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("��������ȷ������:\n");
		scanf("%d", &a);
	}
	while(a!=-1)
	{
		if (a == 1) {
			if (initLStack(s))
				printf("��ʼ����ջ�ɹ���\n");
			system("pause");
			system("cls");
		}
		if (a == 2) {
			int b = 0;
			if (getTopLStack(s, b))
				printf("ջ��Ԫ��Ϊ��%d\n", b);
			system("pause");
			system("cls");
		}
		if (a == 3) {
			if (clearLStack(s))
				printf("��ɲ�������ջ����գ�\n");
			system("pause");
			system("cls");
		}
		if (a == 4) {
			if (destroyLStack(s))
				printf("��ɲ�������ջ�����٣�\n");
			system("pause");
			system("cls");
		}
		if (a == 5) {
			int b = 0;
			if (LStackLength(s, &b))
				printf("��ջ����Ϊ��%d\n", b);
			else
				printf("��ջ��δ����!\n");
			system("pause");
			system("cls");
		}	
		if (a == 6) {
			printf("��������Ҫ��ջ��Ԫ��(�����ʽΪ����������)��\n");
			int b = 0;
			scanf("%d", &b);
			while (b <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("��������ȷ������:\n");
				scanf("%d", &b);
			}
			if (pushLStack(s, b)) {
				printf("��ջ�ɹ���\n");
				printf("��ǰ��ջΪ:");
				PrintStack(s);
			}
			else
				printf("��ջ��δ����!\n");
			//printf("\n%d", s->count);
			system("pause");
			system("cls");
		}	
		if (a == 7) {
			int b = 0;
			if (popLStack(s, &b)) {
				printf("��ջ�ɹ���\n");
				printf("��ջԪ��Ϊ��%d\n", b);
			}
			system("pause");
			system("cls");
		}
		if (a == 8) {
			printf("��ǰ��ջΪ(���Ϊջβ):\n");
			PrintStack(s);
			system("pause");
			system("cls");
		}
		menu();
		printf("����������Ҫ���еĲ���:\n");
		scanf("%d", &a);
		while (a <= 0 && a != -1)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("��������ȷ������:\n");
			scanf("%d", &a);
		}
	}
	system("cls");
	printf("����������ƭ�˰ɣ���������ʼջ��������������\n");
	system("pause");
	system("cls");
	char str[1024] = { 0 };
	printf("������ʽ��\n");
	scanf("%s", str);
	int result = transform(str);
	if (result == 0)	{
		printf("���ʽ����������������������");
	}
	else {
		printf("�������Ȼ����ĵ������ˣ��Ǳ����˾ʹ󷢴ȱ��ĸ���ת��һ�°ɣ�\n");
		printf("ת����ı��ʽΪ��%s\n", tem);
		printf("��������˳�������һ�½����%d\n", culculate(tem));
	}
	return 0;
}