#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int data[123456];

int s(int a)
{
	if (a == 2)return 1;
	if (a == 1 || a % 2 == 0)return 0;
	for (int i = 3; i*i <= a; i++)
	{
		if (a%i == 0)return 0;
	}
	return 1;
}
int main(void)
{
	int n;
	for (n = 0;; n++)
	{
		scanf("%d", &data[n]);
		if (data[n] == 0)break;
	}
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = data[i]+1; j <= data[i] * 2; j++)
		{
			if (s(j))count++;
		}
		printf("%d\n", count);
	}
	return 0;
}