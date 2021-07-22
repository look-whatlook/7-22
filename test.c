#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct S
//{
//	int n;
//	int arr[0];//未知大小的-柔性数组成员-数组的大小是可以调整的
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
//				ps->arr[i] = i;//编译器导致arr[]未配置5-9
//			}
//			for (i = 0; i < 10; i++)
//			{
//				printf("%d ", ps->arr[i]);
//			}
//
//		}
//	}
//	// ptr 未处理 会导致野指针 得小心
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
	if (ps == NULL)//判断ps->arr空指针
	{
		return 0;
	}
	ps->n = 100;//结构体指针ps所指那块空间结构体的n赋值为100
	ps->arr = malloc(5 * sizeof(int));
	if (ps->arr) //判断ps->arr空指针
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
		int* ptr = realloc(ps->arr, 10 * sizeof(int));//arr[i]未配置好
		         //可能是realloc 和 编译器 的原因导致 数组溢出
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