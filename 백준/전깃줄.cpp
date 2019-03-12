#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

struct s
{
	int a, b;
};

bool compare(const s&i, const s&j)
{
	return i.a < j.a;
}
int main(void)
{
	s data1[200];
	int n;
	int lis[1000] = { 0, };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &data1[i].a, &data1[i].b);
	}
	std::sort(data1, data1 + n, compare);

	int size = 0;
	lis[size++] = data1[0].b;
	for (int i = 1; i < n; i++)
	{
		int check = 0;
		for (int j = 0; j < size; j++)
		{
			if (lis[j] > data1[i].b)
			{
				lis[j] = data1[i].b;
				check = 1;
				break;
			}
		}
		if (!check)lis[size++] = data1[i].b;
	}
	printf("%d", n - size);
	return 0;
}