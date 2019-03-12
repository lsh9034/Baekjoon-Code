#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int data1[10001];
int temp[10001];
int N;
using namespace std;
//void merge_sort(int s, int e)
//{
//	if (e <= s)return;
//	int m = (s + e) / 2;
//	merge_sort(s, m);
//	merge_sort(m + 1, e);
//	for (int i = s, j = m + 1, cnt = 0; ;)
//	{
//		if (data1[i] < data1[j])
//		{
//			temp[cnt++] = data1[i];
//			i++;
//		}
//		else
//		{
//			temp[cnt++] = data1[j];
//			j++;
//		}
//		if (i > m)
//		{
//			for (j; j <= e; j++)
//			{
//				temp[cnt++] = data1[j];
//			}
//			break;
//		}
//		else if (j > e)
//		{
//			for (i; i <= m; i++)
//			{
//				temp[cnt++] = data1[i];
//			}
//			break;
//		}
//	}
//	for (int i = s, j = 0; i <= e; i++, j++)data1[i] = temp[j];
//	return;
//}
int main(void)
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		data1[a]++;
	}
	for (int i = 0; i <= 10000; i++)
	{
		if (data1[i] == 0)continue;
		for (int j = 0; j < data1[i]; j++)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}