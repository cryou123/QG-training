#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
int temp[200010];
int j;
char ch;
int len;
int max;

void menu1() {
	printf("******************\n");
	printf("****1.��������****\n");
	printf("****2.�������****\n");
	printf("******************\n");
};
void menu2() {
	printf("******************\n");
	printf("****1.��������****\n");
	printf("****2.�鲢����****\n");
	printf("****3.��������****\n");
	printf("****4.��������****\n");
	printf("****5.��������****\n");
	printf("*****6.������*****\n");
	printf("****7.��������****\n");
	printf("***8.������һ��***\n");
	printf("****9.��������****\n");
	printf("******************\n");
};
int main()
{
	srand((unsigned)time(NULL));
	int b = 0;
	int c = 0;
	int d = 0;
s1:
	menu1();
	int* a = (int*)malloc(sizeof(int) * 200005);
	printf("�������ѡ��\n");
	scanf("%d", &b);
	system("cls");
	switch (b) {
	case 1: 
		printf("���������봴������鳤�ȣ�\n");
		scanf("%d", &j);
		len = j;
		while (j <= 0)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("����������������룡\n");
			scanf("%d", &j);
		}
		system("cls");

		for (int k = 0; k < j; k++) {
			printf("������������������ݷ��ڵ�%dλ(����������):\n", k + 1);
			scanf("%d", &a[k]);
			while (a[k] <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("����������������룡\n");
				scanf("%d", &a[k]);
			}
			system("pause");
			system("cls");
		}
		break;
	case 2:	
		Create_data(&c);
		if (c == 1)	len = 10000;
		else if (c == 2) len = 50000;
		else if (c == 3) len = 200000;
		FILE* fp;
		fp = fopen("Data.txt", "r");
		int i = 0;
		while (!feof(fp)) {
			fscanf(fp, "%d", &a[i]);
			i++;
		}
		fclose(fp);
		break;
	default:while ((ch = getchar()) != '\n' && ch != EOF); printf("����������������룡"); goto s1;
	}
	s2:
	menu2();
	printf("��ѡ������Ҫ�����򷽷�(��Ȼ�����һ����):\n");
	scanf("%d", &d);
	switch (d) {
	case 1:	insertSort(a, len); break;
	case 2:MergeArray(a, 0, (len - 1) / 2, len - 1, temp); break;
		//MergeSort(a, 0, len-1, temp); break;
	case 3:	QuickSort_Recursion(a, 0, len - 1); break;
		//QuickSort(a, 0, len-1); break;
	case 4:		
	max = 0;
	for (int i = 0; i < len; i++) {
		if (a[i] > max)	max = a[i];
	}
	CountSort(a, len, max);
	break;
	case 5:	RadixCountSort(a, len); break;
	case 6:My_func(a, len); break;
	case 7:break;
	case 8:system("cls"); goto s1; break;
	case 9:return 0;
	default:goto s2;
	}
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", a[i]);
	}

	system("pause");
	system("cls");

	printf("��������ʼ��ɫ����������һ��ֻ����0��1��2�����飡\n");
	printf("���������봴������鳤�ȣ�\n");
	scanf("%d", &j);
	len = j;
	while (j <= 0)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("����������������룡\n");
		scanf("%d", &j);
	}
	system("cls");
	int* aa = (int*)malloc(sizeof(int) * j);
	for (int k = 0; k < j; k++) {
		printf("������������������ݷ��ڵ�%dλ(����������):\n", k + 1);
		scanf("%d", &aa[k]);
		while (aa[k] != 0 && aa[k] != 1 && aa[k] != 2) {
			printf("����������������룡\n");
			scanf("%d", &aa[k]);
		}
		system("pause");
		system("cls");
	}
	printf("�����������Ϊ:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", aa[i]);
	}
	ColorSort(aa, len);	
	printf("���к������Ϊ:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", aa[i]);
	}
	//int a[] = { 0,0,0,0,0,0,0,1,1,1,2};
	return 0;
}