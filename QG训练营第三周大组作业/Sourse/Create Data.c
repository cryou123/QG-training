#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void Create_data(int*a)
{
	FILE* f;
	f = fopen("Data.txt", "w");
	if (f != NULL)
	{
		ss:
		printf("1------10000\n");
		printf("2------50000\n");
		printf("3------200000\n");
		printf("��������Ҫ������ɵ����ݹ�ģ��\n");
		*a = 0;
		scanf("%d", a);
		char ch;
		while (*a <= 0||*a>3)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("��������ȷ������:\n");
			scanf("%d", a);
		}
		int max = 0;
		printf("��������Ҫ������ɵ����ݴ�С��Χ����ֻ�������ֵ��Ĭ����СΪ0��\n");
		scanf("%d", &max);
		while (max <= 0)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("��������ȷ������:\n");
			scanf("%d", &max);
		}
		switch (*a)
		{
		case 1:
			for (int i = 0; i < 10000; i++)
			{
				int b = rand() % max;
				fprintf(f, "%d\n", b);
			}
			break;
		case 2:
			for (int j = 0; j < 50000; j++)
			{
				int b = rand() % max;
				fprintf(f, "%d\n", b);
			}
			break;
		case 3:
			for (int j = 0; j < 200000; j++)
			{
				int b = rand() % max;
				fprintf(f, "%d\n", b);
			}
			break;
		default:
			printf("�����������������룡");
			system("pause");
			system("cls");
			goto ss;
		}
	}
}