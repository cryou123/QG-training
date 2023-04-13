#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"
int temp[200010];
int j;
char ch;
int len;
int max;

void menu1() {
	printf("******************\n");
	printf("****1.自行输入****\n");
	printf("****2.随机创造****\n");
	printf("******************\n");
};
void menu2() {
	printf("******************\n");
	printf("****1.插入排序****\n");
	printf("****2.归并排序****\n");
	printf("****3.快速排序****\n");
	printf("****4.计数排序****\n");
	printf("****5.基数排序****\n");
	printf("*****6.找数字*****\n");
	printf("****7.继续程序****\n");
	printf("***8.返回上一步***\n");
	printf("****9.结束程序****\n");
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
	printf("输入你的选择：\n");
	scanf("%d", &b);
	system("cls");
	switch (b) {
	case 1: 
		printf("请输入你想创造的数组长度：\n");
		scanf("%d", &j);
		len = j;
		while (j <= 0)
		{
			while ((ch = getchar()) != '\n' && ch != EOF);
			printf("输入错误，请重新输入！\n");
			scanf("%d", &j);
		}
		system("cls");

		for (int k = 0; k < j; k++) {
			printf("请输入你想输入的数据放在第%d位(非零正整数):\n", k + 1);
			scanf("%d", &a[k]);
			while (a[k] <= 0)
			{
				while ((ch = getchar()) != '\n' && ch != EOF);
				printf("输入错误，请重新输入！\n");
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
	default:while ((ch = getchar()) != '\n' && ch != EOF); printf("输入错误，请重新输入！"); goto s1;
	}
	s2:
	menu2();
	printf("请选择你需要的排序方法(虽然结果都一样啦):\n");
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

	printf("接下来开始颜色排序！请输入一个只含有0，1，2的数组！\n");
	printf("请输入你想创造的数组长度：\n");
	scanf("%d", &j);
	len = j;
	while (j <= 0)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("输入错误，请重新输入！\n");
		scanf("%d", &j);
	}
	system("cls");
	int* aa = (int*)malloc(sizeof(int) * j);
	for (int k = 0; k < j; k++) {
		printf("请输入你想输入的数据放在第%d位(非零正整数):\n", k + 1);
		scanf("%d", &aa[k]);
		while (aa[k] != 0 && aa[k] != 1 && aa[k] != 2) {
			printf("输入错误，请重新输入！\n");
			scanf("%d", &aa[k]);
		}
		system("pause");
		system("cls");
	}
	printf("你输入的数组为:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", aa[i]);
	}
	ColorSort(aa, len);	
	printf("排列后的数组为:\n");
	for (int i = 0; i < len; i++)
	{
		printf("%d\n", aa[i]);
	}
	//int a[] = { 0,0,0,0,0,0,0,1,1,1,2};
	return 0;
}