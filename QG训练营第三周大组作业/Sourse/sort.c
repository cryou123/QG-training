#define _CRT_SECURE_NO_WARNINGS 1
#include"sort.h"

void insertSort(int* a, int n)
{
	int tem = 0;
	for (int i = 0; i < n; i++){
		for (int j = i; j >= 1; j--){
			if (a[j] < a[j - 1]) {
				tem = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tem;
			}
			else
				break;
		}
	}
}

void MergeArray(int a[], int begin, int mid, int end, int temp[]){
	if (begin >= end)
		return;
	int len = end - begin;
	int start1 = begin, end1 = mid;
	int start2 = mid + 1, end2 = end;
	MergeArray(a, start1, (len >> 1) + begin, end1, temp);
	MergeArray(a, start2, (len >> 1) + begin, end2, temp);
	int k = begin;
	while (start1 <= end1 && start2 <= end2)
		temp[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
	while (start1 <= end1)
		temp[k++] = a[start1++];
	while (start2 <= end2)
		temp[k++] = a[start2++];
	for (k = begin; k <= end; k++)
		a[k] = temp[k];
}

void MergeSort(int* a, int begin, int end, int* temp){
	int len = end+1 - begin;
	int *b = a;
	int *c = (int*)malloc(len * sizeof(int));
	for (int cop = 1; cop < len; cop += cop){
		for (begin = 0; begin < len; begin += cop +cop) {
			int start = begin, mid = min(begin + cop, len), end = min(begin + cop + cop, len);
			int k = start;
			int start1 = start, end1 = mid;
			int start2 = mid, end2 = end;
			while (start1 < end1 && start2 < end2)
				c[k++] = b[start1] < b[start2] ? b[start1++] : b[start2++];
			while (start1 < end1)
				c[k++] = b[start1++];
			while (start2 < end2)
				c[k++] = b[start2++];
		}
		temp = b;
		b = c;
		c = temp;
	}
	if (b != a) {
		for (int i = 0; i < len; i++)
			c[i] = b[i];
		c = b;
	}
	free(c);
}

void swap(int* a, int* b){
	int tem = *a;
	*a = *b;
	*b = tem;
}
int Partition(int* a, int begin, int end) {
	int mid = a[end];
	int left = begin, right = end - 1;
	while (left < right) {
		while (a[left] < mid && left < right)
			left++;
		while (a[right] > mid && left < right)
			right--;
		swap(&a[left], &a[right]);
	}
	if (a[left] >= a[end])
		swap(&a[left], &a[end]);
	else
		left++;
	return left;
}
void QuickSort_Recursion(int* a, int begin, int end){
	if (begin >= end)
		return;
	int left = Partition(a,begin,end);
	if (left) {
		QuickSort_Recursion(a, begin, left - 1);
	}
	QuickSort_Recursion(a, left + 1, end);
}

//int Q_quicksort(int* a, int begin, int end) {		//挖坑法找出key值
//	int key = a[begin];
//	int hole = begin;
//	int left = begin;
//	int right = end;
//	while (left < right) {
//		while (left < right && a[right] >= key) {
//			right--;
//		}
//		a[hole] = right;
//		hole = right;
//		while (left < right && a[left] <= key) {
//			left++;
//		}
//		a[hole] = a[left];
//		hole = left;
//	}
//	a[hole] = key;
//	return hole;
//}
void QuickSort(int* a, int begin,int end) {		//用栈来存储
	LinkStack st;
	initLStack(&st);
	if (end > begin){
		pushLStack(&st, begin);
		pushLStack(&st, end);
	}
	while (!isEmptyLStack(&st)){
		int tem;
		int right; popLStack(&st,&right);
		int left; popLStack(&st, &left);
		int mid = Partition(a, left, right);
		if (left < mid - 1) {
			pushLStack(&st, left);
			pushLStack(&st, mid-1);
		}
		if (mid + 1 < right) {
			pushLStack(&st, mid + 1);
			pushLStack(&st, right);
		}
	}
}

void CountSort(int* a, int size, int max) {
	int* b = (int*)malloc(sizeof(int)*(max+1));
	for (int i = 0; i <= max; i++) {
		b[i] = 0;
	}
	for (int i = 0; i < size; i++)	{
		b[a[i]]++;
	}
	int step = 0;
	for (int j = 0; j <= max; j++)	{
		while (b[j]!=0)	{
			a[step] = j;
			step++;
			//printf("%d", b[a[j]]);
			b[j]--;
		}
	}
}

void RadixCountSort(int* a, int size) {
	int* b = (int*)malloc(sizeof(int) * size);
	int count = 0;
	int rat = 1;
	int bow[10] = {0};
	for (int i = 0; i < size; i++) {
			if (a[i] != 0)	{
				count = 1;
				break;
			}
	}
	while (count)
	{
		for (int i = 0; i < size; i++) {
			if (a[i] / rat % 10 != 0) {
				count = 1;
				break;
			}
			count = 0;
		}
		for (int i = 0; i < 10; i++){		//清零桶
			bow[i] = 0;
		}
		for (int i = 0; i < size; i++) {
			bow[(a[i] / rat) % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			bow[i] = bow[i]+bow[i - 1];
			printf("%d\n", bow[i]);
		}
		//printf("------------\n");
		for (int i = size-1; i >= 0; i--) {
			b[bow[(a[i] / rat) % 10]-1] = a[i];		//没-1！！！巨坑
			bow[a[i] / rat % 10]--;
		}
		for (int i = 0; i < size; i++) {
			a[i] = b[i];
			printf("%d\n", a[i]);
		}
		//printf("--------------\n");
		rat *= 10;
	}
}

void ColorSort(int* a, int size) {
	int* p1 = a;
	int* p2 = a;
	int* p3 = (a + size-1);
	for (int i = 0; i < size; i++) {
		if (*p2 == 0) {
			if (p1 == p2) {
				p1++;
			}
			p2++;
			continue;
		}
		if (*p3 == 2) {
			p3--;
			continue;
		}
		if (*p1 == 0) {
			swap(p1, p2);
			p2++;
		}
		if (*p1 == 2) {
			swap(p1, p3);
			p3--;
		}
		if (p1 == p3 || p2 == p3) {
			break;
		}
		p1++;
	}
}

void My_func(int* a, int size) {
	int n = 0;
	printf("请输入你想找出的第N大的数字：\n");
	scanf("%d", &n);
	char ch;
	while (n <= 0)
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
		printf("请输入正确的数字:\n");
		scanf("%d", &n);
	}
	int* b = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++) {
		b[i] = a[i];
	}
	QuickSort_Recursion(b, 0, size - 1);
	printf("该数字为：%d\n",b[n-1]);
}