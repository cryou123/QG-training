#define _CRT_SECURE_NO_WARNINGS 1
#include"QGѵ��Ӫ��һ�ܴ�����ҵ.h"

void SearchList(ML* head, int a)
{
	ML* L = (ML*)malloc(sizeof(ML));
	L = head->next;
	int step = 1;
	while (L != NULL)
	{
		if (L->num == a)
		{
			printf("�������и����֣����ڽ��λ��Ϊ��%d\n", step);
			return;
		}
		L = L->next;
		step++;
	}
	printf("������û�и����֣�\n");
	return;
}