#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct S
//{
//	int n;
//	int arr[0];//δ֪��С��-���������Ա-����Ĵ�С�ǿ��Ե�����
//};
//int main()
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));//
//	struct S* ps = (struct S*)malloc(sizeof(struct S) + 5 * sizeof(int));
//	if (ps == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		ps->n = 100;
//		int i = 0;
//		for (i = 0; i < 5; i++)
//		{
//			ps->arr[i] = i;//0 1 2 3 4
//		}
//		for (i = 0; i < 5; i++)
//		{
//			printf("%d ", ps->arr[i]);
//		}
//		struct S* ptr = realloc(ps, 44);
//		if (ptr != NULL)
//		{
//			ps = ptr;
//			for (i = 5; i < 10; i++)
//			{
//				ps->arr[i] = i;//����������arr[]δ����5-9
//			}
//			for (i = 0; i < 10; i++)
//			{
//				printf("%d ", ps->arr[i]);
//			}
//
//		}
//	}
//	// ptr δ���� �ᵼ��Ұָ�� ��С��
//	free(ps);
//	ps = NULL;
//}
	
struct S
{
	int n;
	int* arr;
};
int main()
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	if (ps == NULL)//�ж�ps->arr��ָ��
	{
		return 0;
	}
	ps->n = 100;//�ṹ��ָ��ps��ָ�ǿ�ռ�ṹ���n��ֵΪ100
	ps->arr = malloc(5 * sizeof(int));
	if (ps->arr) //�ж�ps->arr��ָ��
	{
		int i = 0;
		for (i = 0; i < 5; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 5; i++)
		{
			printf("%d ", ps->arr[i]);
		}
		int* ptr = realloc(ps->arr, 10 * sizeof(int));//arr[i]δ���ú�
		         //������realloc �� ������ ��ԭ���� �������
		if (ptr == NULL)
		{
			return 0;
		}
		if (ptr != NULL)
		{
			ps->arr = ptr; 
		}
		for (i = 5; i < 10; i++)
		{
			ps->arr[i] = i;
		}
		for (i = 0; i < 10; i++)
		{
			printf("%d ", ps->arr[i]);
		}
	}
	free(ps->arr);
	ps->arr = NULL;
	free(ps);
	ps = NULL;
	return 0;
}